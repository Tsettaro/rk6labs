import math
import numpy as np
import polars as pl
import matplotlib.pylab as plt
import pyarrow
pl.Config.set_tbl_hide_dataframe_shape(True)
pl.Config.set_tbl_hide_column_data_types(True)

dataframe = pl.DataFrame(
    {'m': [0], 'Ms0': [0.], 'Ms1': [0.],'p': [0.],'Mn': [0.], 'k': [0.]}
)
# Product of the sequence
def product_of_sequence(n, i):
    result = 1
    for j in range(i):
        result *= (n - j)
    return result

def func(N, m, lamb, mu):
    array = []
    global dataframe
    ro = lamb/mu
    sum = 0
    for i in range(m+1):
        sum += (product_of_sequence(N, i)*(ro**i)/math.factorial(i))
        array.append((product_of_sequence(N, i)*(ro**i)/math.factorial(i)))
    for i in range(m+1, N+1):
        sum += (product_of_sequence(N, i)*(ro**i)/(math.factorial(i)*m**(i-m)))
        array.append((product_of_sequence(N, i)*(ro**i)/(math.factorial(i)*m**(i-m))))
    p0 = 1/sum
    array = [array * p0 for array in array]
    Ms0 = 0.0
    Ms1 = 0.0
    p = 0.0
    Mn = 0.0
    k = 0.0
    temp = 1
    for i in range(N+1):
        Ms0 += i * array[i]
    for i in range(1, N-m+1):
        Ms1 += i * array[m+i]
        p += array[m+i]
    for i in range(1, m+1):
        Mn += i * array[i]

    for i in range(1, N-m+1):
        Mn += (m * array[m+i])
    k = Mn/N
    data = pl.DataFrame({'m': [m], 'Ms0': [Ms0], 'Ms1': [Ms1], 'p': [p], 'Mn': [Mn], 'k': [k]})
    dataframe = dataframe.vstack(data)

N = 39
m = N
tc = 66
ts = 45

lamb = 1/tc
mu = 1/ts

#print(product_of_sequence(15, 0))

for m in range(1, m+1):
    func(N, m, lamb, mu)
dataframe = dataframe[1:]
print(dataframe)
