import torch
import torch.nn as nn

class lstmClassifier(nn.Module):
    def __init__(self,vocab_size, embedding_size = 300, hidden_size = 128 ):
        super(lstmClassifier, self).__init__()
        self.hidden_size = hidden_size
        self.embedding = nn.Embedding(vocab_size, embedding_size)
        self.hidden_size = hidden_size
        self.lstm = nn.LSTM(input_size = embedding_size, 
                            hidden_size = hidden_size, 
                            num_layers = 1, 
                            batch_first = True,
                            bidirectional = True)
        self.drop = nn.Dropout(p = 0.4)
        self.fc = nn.Linear(2*hidden_size, 1)
        self.sigmoid = nn.Sigmoid()

    def forward(self, text):
        text = text.type(torch.LongTensor)
        emb = self.embedding(text)
        out, _ = self.lstm(emb)
        out_forward = out[:, -1, :self.hidden_size]
        out_reverse = out[:, 0, self.hidden_size: ]
        cat_out = torch.cat((out_forward, out_reverse), 1)
        
        logits = self.fc(cat_out)
        out = self.sigmoid(logits)
        # logits = torch.squeeze(logits, 1)
        # p = self.softmax(features)
        return out




