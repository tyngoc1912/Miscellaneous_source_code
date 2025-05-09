from pyspark import keyword_only
from pyspark.ml import Transformer
from pyspark.ml.param.shared import HasInputCol, HasOutputCol, Param, Params, TypeConverters
from pyspark.ml.util import DefaultParamsReadable, DefaultParamsWritable
from pyspark.sql import DataFrame
from pyspark.sql.types import *
import pyspark.sql.functions as F

import re
import string
import demoji
import pickle

demoji.download_codes()
vocab = pickle.load(open('vocab.pkl', 'rb'))
for key in vocab.keys():
    vocab[key] = int(vocab[key])

class TextTransformer(Transformer, HasInputCol, HasOutputCol, DefaultParamsReadable, DefaultParamsWritable):
    input_col = Param(Params._dummy(), "input_col", "input column name.", typeConverter=TypeConverters.toString)
    output_col = Param(Params._dummy(), "output_col", "output column name.", typeConverter=TypeConverters.toString)

    @keyword_only
    def __init__(self, input_col: str = "input", output_col: str = "output", ):
        super(TextTransformer, self).__init__()
        self._setDefault(input_col=None, output_col=None)
        kwargs = self._input_kwargs
        self.set_params(**kwargs)
        

    @keyword_only
    def set_params(self, input_col: str = "input", output_col: str = "output"):
        kwargs = self._input_kwargs
        self._set(**kwargs)

    def get_input_col(self):
        return self.getOrDefault(self.input_col)

    def get_output_col(self):
        return self.getOrDefault(self.output_col)


    def _transform(self, df: DataFrame):
        def preprocess_text(text, maxlen = 50) -> str:
            try:
                text = demoji.replace_with_desc(str(text), sep = '', )
            except:
                text = ''
            text = re.sub(r'\d+', '', text).translate(str.maketrans( string.punctuation, ' '*len(string.punctuation)),).strip().lower().split(' ')
            text = [vocab[word] if word in vocab.keys() else 1 for word in text ]
            if len(text) < maxlen:
                text = text + [0]*(maxlen - len(text))
            else:
                text = text[:50]

            return text

        t = ArrayType(IntegerType())

        input_col = self.get_input_col()
        output_col = self.get_output_col()
        # The custom action: concatenate the integer form of the doubles from the Vector
        transform_udf = F.udf(preprocess_text, t)
        new_df = df.withColumn(output_col, transform_udf(input_col))

        df_exploded = new_df.select(
                new_df["label_id"], 
                *[new_df["features"][i] for i in range(50)]
            )
        return df_exploded


