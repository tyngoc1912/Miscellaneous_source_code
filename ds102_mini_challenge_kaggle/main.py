import argparse
import sys
import os
import pandas as pd
import numpy as np
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import StandardScaler
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import cross_val_score
from joblib import dump, load


def run_train(public_dir, model_dir):
    os.makedirs(model_dir, exist_ok=True)
    train_file = os.path.join(public_dir, 'train_data', 'train.npz')
    train_data = np.load(train_file)
    X_train = train_data['X_train']
    y_train = train_data['y_train']

    # Tạo pipeline: chuẩn hóa + mô hình RandomForest
    model = Pipeline([
        ('scaler', StandardScaler()),
        ('clf', RandomForestClassifier(n_estimators=100, max_depth=8, random_state=42))
    ])

    # In điểm cross-validation để bạn biết model đang hoạt động thế nào
    scores = cross_val_score(model, X_train, y_train, cv=5, scoring='f1_weighted')
    print(f"Cross-validation F1 scores: {scores}")
    print(f"Mean F1 score: {np.mean(scores)}")

    model.fit(X_train, y_train)

    model_path = os.path.join(model_dir, 'trained_model.joblib')
    dump(model, model_path)


def run_predict(model_dir, test_input_dir, output_path):
    model_path = os.path.join(model_dir, 'trained_model.joblib')
    test_file = os.path.join(test_input_dir, 'test.npz')
    model = load(model_path)
    test_data = np.load(test_file)
    X_test = test_data['X_test']
    y_pred = model.predict(X_test)
    pd.DataFrame({'y': y_pred}).to_json(output_path, orient='records', lines=True)


def main():
    parser = argparse.ArgumentParser()
    subparsers = parser.add_subparsers(dest='command')

    parser_train = subparsers.add_parser('train')
    parser_train.add_argument('--public_dir', type=str)
    parser_train.add_argument('--model_dir', type=str)

    parser_predict = subparsers.add_parser('predict')
    parser_predict.add_argument('--model_dir', type=str)
    parser_predict.add_argument('--test_input_dir', type=str)
    parser_predict.add_argument('--output_path', type=str)

    args = parser.parse_args()

    if args.command == 'train':
        run_train(args.public_dir, args.model_dir)
    elif args.command == 'predict':
        run_predict(args.model_dir, args.test_input_dir, args.output_path)
    else:
        parser.print_help()
        sys.exit(1)


if __name__ == "__main__":
    main()
