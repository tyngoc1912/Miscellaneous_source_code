# Data Types / Tipos de Datos

[Home / Inicio](https://github.com/TheGlitchCat/probability-and-statistics-R)

## Content / Contenido
- [Trend / Tendencia](#trend--tendencia)
- [Variability / Variabilidad](#variability--variabilidad)
- [Position / Posición](#position--posición)
- [Form / Forma](#form--forma)



## Trend / Tendencia
### Mean / Promedio
#### English
It is the sum of all values in a dataset and dividing with the total number of values 
#### Español
Se calcula sumando todos los valores del conjunto de datos y dividiéndolo por la cantidad total de datos
![mean](https://pharmafactz.com/wp-content/uploads/2017/11/p2.png)

### Median / Mediana
#### English
It is the "middle" value of a dataset
#### Español
Es el valor medio de un conjunto de datos
![median](https://upload.wikimedia.org/wikipedia/commons/thumb/c/cf/Finding_the_median.png/1200px-Finding_the_median.png)

### Mode / Moda
#### English
It is the most repetitive value in the dataset
#### Español
Es el valor mas repetido en un conjunto de datos 
![mode](https://www.wikihow.com/images/thumb/2/29/Find-Mean%2C-Median%2C-and-Mode-Step-7-Version-2.jpg/aid1660401-v4-728px-Find-Mean%2C-Median%2C-and-Mode-Step-7-Version-2.jpg)

## Variability / Variabilidad
### Variance and Standard Deviation / Varianza y desviación estandar
#### English
- Variance - Is a numerical measure of how the data values is dispersed around the mean (shows how much the data varies)
- Standard Deviation - Is the square root of variance and represent the range can take the value (between edge_values = mean + sd or mean - sd )
#### Español
- varianza - Es el valor que mide que tan dispersos estan los datos alrededor de la media
- Desviación estándar - es la raíz cuadrada de la varianza y representa el rango que puede tomar el valor (Entre bordes = promedio + ds o promedio - ds)
![variance](http://statisticslectures.com/images/samplevarstd.gif)

### Min, Max and Range / Mínimo, Máximo y Rango
#### English
- Min - It is the lowest value of the dataset
- Max - It is the highest value of the dataset
- Range - it is the subtraction between max and min (max - min)
#### Español
- Mínimo - Es el valor mas bajo del conjunto de datos
- Máximo - Es el valor mas alto del conjunto de datos
- Rango - Es la resta entre el valor máximo y el valor minimo
![dial](https://www.first5000.com.au/wp-content/uploads/2017/10/Dial-up-your-courage-4-1024x683-610x400.png)

## Position / Posición 
### Quartiles / Cuartiles
(see quantiles for more info / para profundizar buscar en cuantiles)
#### English
Quartiles - split the dataset in 4 equal parts Q1 = 25%, Q2(median) = 50%, Q3 = 75%, and tell us how much of our data lies below a section. 
#### Español
Separa el conjunto de datos en partes iguales, los cuales se dividen en Q1 = 25%, Q2(Mediana) = 50%, Q3 = 75%, y nos dice como nuestros datos están distribuidos y como estos se encuentran debajo de dichos porcentajes.
![quartile](https://i.stack.imgur.com/L4GEM.png)

### Interquartile Range / Rango Intercuartil
#### English
Interquartile range(IQR) also called middle 50%, is a statistical dispersion measure, and is the result of substract between Q3 and Q1 (Q3 - Q1)
#### Español
El rango intercuartil es una medida de dispersión en estadística, y es el resultado de la resta entre el Q1 y Q3 (Q3 - Q1)
![IQR](https://i2.wp.com/makemeanalyst.com/wp-content/uploads/2017/05/IQR-1.png?resize=431%2C460)

### Outlier / Dato Atípico
#### English
Outlier are the separated values from main body of dataset
#### Español
Los datos atípicos son aquellos valores que están separados de la agrupación del conjunto de datos

![outlier](https://baldscientist.files.wordpress.com/2013/02/outliers1.jpg)

## Form / Forma
### Kurtosis / Curtosis
#### English
It show us how our data are distributed 
- Leptokurtic - Slender (x > 0)
- Mesokurtic - Normal (x=0 ± 0.5 or 1.5) (Some authors says 0.5 others 1.5)
- Platykurtic - Broad (x < 0)
#### Español
Nos muestra como nuestra data esta agrupada o distribuida
- Leptocúrtica - Estrecha (x > 0)
- Mesocúrtica - Normal (x=0 ± 0.5 o 1.5) (Depende de la literatura)
- Platicírtica - Extendida / alargada (x < 0)
  
![kurtosis](https://miro.medium.com/max/742/1*Nqu07THa7APRTOF7kaVr5Q.jpeg)
![Example-kurtosis](Iris&#32;sepal&#32;length&#32;distribution.png)

### Skewness / Asimetría
#### English
Skewness is a measure of the asymmetry of the distribution about its mean, it can be: 
- Positive - The right tail is longer (data agruped to left)
- Negative - The left tail is longer (data agruped to right)
- Symmetrical - middle/center
#### Español
Asimetría es una medida de la distribución respecto al promedio, el cual puede ser: 
- Positivo - La cola derecha es mas larga (datos agrupados a la izquierda)
- Negativo - La cola izquierda es mas larga (datos agrupados a la derecha)
- Simétrica - Centro 

![skewness](https://miro.medium.com/max/1200/1*nj-Ch3AUFmkd0JUSOW_bTQ.jpeg)