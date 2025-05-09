from pyspark.sql import SparkSession
from pyspark.sql.types import  StructField, StructType, StringType

from pyspark.ml.feature import VectorAssembler
from pyspark.sql.functions import *
from pyspark.ml.pipeline import Pipeline, PipelineModel
from pyspark.sql.types import *

from pyspark.sql import DataFrame
from pyspark import keyword_only
from pyspark.ml import Transformer
from pyspark.ml.param.shared import HasInputCol, HasOutputCol, Param, Params, TypeConverters
from pyspark.ml.util import DefaultParamsReadable, DefaultParamsWritable

# from sparktorch import PysparkPipelineWrapper

import re
import string

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
        def preprocess_text(text, ) -> str:
            # try:
            #     text = demoji.replace_with_desc(str(text), sep = '', )
            # except:
            #     text = ''
            text = re.sub(r'\d+', '', str(text)).translate(str.maketrans( string.punctuation, ' '*len(string.punctuation)),).strip().lower()
            return text
        input_col = self.get_input_col()
        output_col = self.get_output_col()
        # The custom action: concatenate the integer form of the doubles from the Vector
        transform_udf = udf(preprocess_text, StringType())
        new_df = df.withColumn(output_col, transform_udf(input_col))
        return new_df

if __name__ == '__main__':
    pass