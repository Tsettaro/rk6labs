import math
import numpy as np
import polars as pl
import matplotlib.pylab as plt
import pyarrow
import xlsxwriter


# Make polars dataframe_2 with columns n, m, P, M, k, P(queue), Q, k(query) and set 'n' type is i64 and other is 'f64'

dataframe_2 = pl.DataFrame(
    {'n': [0], 'm': [0], 'P_reject': [0.], 'M_wait': [0.], 'k_op': [0.], 'P(queue)': [0.], 'M_queue': [0.], 'k(query)': [0.]}
)

dataframe_3 = pl.DataFrame(
    {'n': [0], 'N': [0.], 'k': [0.], 'P(queue)': [0.], 'Q': [0.]}
)
dataframe_4 = pl.DataFrame(
    {'n': [0], 'N': [0.], 'k': [0.], 'P(queue)': [0.], 'Q': [0.]}
)

def plot_2(dataframe, a):
    def plot(name, xlabel, ylabel):
        f = plt.figure()
        f.set_figwidth(10)
        f.set_figheight(8)
        i = 0
        for row in range(0, len(dataframe), a):
            plt.plot([j for j in range(1, a+1)], dataframe[name][row:row+a], label=f'{name}_{i+1}')
            i+=1
        plt.title(f'task2-{ylabel}'.replace('/', '-'))
        plt.xlabel(xlabel)
        plt.ylabel(ylabel)
        plt.grid()
        plt.legend()
        plt.savefig(f'task2-{ylabel}'.replace('/', '-'))
        plt.clf()
    # Make P-plot of dataframe
    dataframe = dataframe.sort('m')
    plot('P_reject', 'm', 'P_reject')
    plot('M_wait', 'm', 'M_wait')
    plot('k_op', 'm', 'k_op')
    plot('P(queue)', 'm', 'P (queue)')
    plot('M_queue', 'm', 'M (queue)')
    plot('k(query)', 'm', 'k (query)')

def plot_3_4(dataframe, a, number):
    def plot(name, xlabel, ylabel):
        i = 0
        plt.plot([j for j in range(1, a+1)], dataframe[name][:a+1], label=f'{name}')
        plt.title(f'task{number}-{ylabel}'.replace('/', '-'))
        plt.xlabel(xlabel)
        plt.ylabel(ylabel)
        plt.grid()
        plt.legend()
        plt.savefig(f'task{number}-{ylabel}'.replace('/', '-'))
        plt.clf()
    plot('N', 'n', 'N')
    plot('k', 'n', 'k')
    plot('P(queue)', 'n', 'P')
    plot('Q', 'n', 'Q')

def first_task(lamb, mu):
    def make_plot(mas, xlabel, ylabel, title):
        plt.plot([i for i in range(1, n+1)], mas)
        plt.xlabel(xlabel)
        plt.ylabel(ylabel)
        plt.title(title)
        plt.grid()
        plt.savefig(f'task1-{ylabel}'.replace('/', '-'))
        plt.clf()
        #plt.show()
    local_p = []
    ro = lamb/mu
    sum = 0
    n = 0
    while(True):
        sum += (ro**n)/math.factorial(n)
        local_p.append((ro**n)/math.factorial(n))
        if ((ro**n)/math.factorial(n) < 0.01):
            break
        n+=1
    p = 1/sum
    local_p = [local_p * p for local_p in local_p]
    N = 0
    arr_N = []
    for n in range(len(local_p)):
        N += n * local_p[n]
        arr_N.append(N)
    arr_N.pop(0)
    local_p.pop(0)
    # Generate polars dataframe with index from 1 to n, local_p, arr_n and N/n
    data = {'n': [i for i in range(1, n+1)], 'local_p': local_p, 'arr_n': arr_N, 'N/n': [N/n for i in range(1, n+1)]}
    df = pl.DataFrame(data)
    #with pl.Config(tbl_hide_dataframe_shape=True, tbl_hide_column_data_types=True, tbl_rows=df.height):
    #    print(df)

    # Make plots
    make_plot(local_p, 'n', 'local_p', 'P')
    make_plot(arr_N, 'n', 'arr_N', 'N')
    make_plot([N/n for n in range(1, n+1)], 'n', 'N/n', 'k')
    return df

def second_task(lamb, mu, n, m):
    p_arr = []
    global dataframe_2
    sum = 0
    M_wait = 0
    ro = lamb/mu
    for i in range(n+1):
        sum += (ro**i)/math.factorial(i)
        p_arr.append((ro**i)/math.factorial(i))

    # P = (lamb/mu)**n / (n**j * math.factorial(n))
    for j in range(n+1,n+1+m):
        sum += (ro**j)/(n**(j-n) * math.factorial(n))
        p_arr.append((ro**j)/(n**(j-n) * math.factorial(i)))
    p0 = 1/sum
    p_arr.pop(0)
    p_arr = [p_arr * p0 for p_arr in p_arr]

    for i in range(n):
        M_wait += (i+1) * p_arr[i]
    for i in range(n, n+m):
        M_wait += n * p_arr[i]
    M_query = 0.0
    P_query = 0.0
    j = 0
    for i in range(n, n+m):
        M_query += (j+1) * p_arr[i]
        j+=1
    for i in range(n, n+m):
        P_query += p_arr[i]
    k_query = M_query/m

    # Make row with n, m, P_reject, M_wait, k_op, P(queue), M_queue, k(query) and append to dataframe_2
    data = pl.DataFrame({'n': [n], 'm': [m], 'P_reject': [p_arr[len(p_arr)-1]], 'M_wait': [M_wait], 'k_op': [M_wait/n], 'P(queue)': [P_query], 'M_queue': [M_query], 'k(query)': [k_query]})
    dataframe_2 = dataframe_2.vstack(data)

def third_task(lamb, mu, n):
    p_arr = []
    global dataframe_3
    sum = 0
    ro = lamb/mu
    N = 0
    a = lamb/(n*mu)
    for i in range(n+1):
        sum += (ro**i)/math.factorial(i)
        p_arr.append((ro**i)/math.factorial(i))
    sum += (ro**n/math.factorial(n) * (a/(1-a))) # BE CAREFUL HERE
    p0 = 1/sum
    p_arr.pop(0)
    p_arr = [p_arr * p0 for p_arr in p_arr]
    for i in range(len(p_arr)):
        N+= (i+1) * p_arr[i]
    N += (n * p_arr[len(p_arr) - 1] * (a/(1-a)))
    data = pl.DataFrame({'n': [n], 'N': [N], 'k': [N/n], 'P(queue)': [p_arr[len(p_arr) - 1] * (a/(1-a))], 'Q': [p_arr[len(p_arr) - 1] * a * 1/(1-a)**2]})
    dataframe_3 = dataframe_3.vstack(data)

def _p0product(n, j, lamb, mu, nu):
    array = np.fromfunction(lambda k: lamb / (n*mu+(k+1)*nu), (np.int64(j),), dtype = float)
    return np.prod(array)

p0product = np.vectorize(_p0product)
def fourth_task(n, nmult, lamb, mu, nu):
    global dataframe_4

    # Initializing factorial
    factorial = np.arange(n + nmult + 1, dtype=float)
    factorial[0] = 1
    for i in range(1, n + nmult):
        factorial[i] = factorial[i - 1] * factorial[i]
        

    # Computing P0
    P0A = np.fromfunction(lambda i: (lamb**i) / (factorial[np.int64(i)] * (mu**i)), (n+1,), dtype = float)
    P0B = (lamb**n)/(factorial[np.int64(n)]*(mu**n))
    P0C = np.fromfunction(lambda j: p0product(n, j+1, lamb, mu, nu), (n + nmult,), dtype = float) # (n * nmult, ) was set randomly in order to meet minimum precision requirements 

    P0 = 1 / (np.sum(P0A) + P0B * np.sum(P0C)) # +
    # print(P0, P0A, P0B)

    # Computing Ps
    #P0Aextended = (lamb**n) / (factorial[np.int64(n)] * (mu**n))
    Pok = P0A * P0
    # print(f'Ps: {Pok}')
    #Pinf = P0C * P0Aextended * Pok[-1]
    #P = np.concatenate((Pok, Pinf))
    #print(P0C)
    #print(' ')
    #print(P0A)
    #print(' ')
    #print(P)

    # Computing N
    NA = np.fromfunction(lambda i: (i * (lamb**i)) / (factorial[np.int64(i)] * (mu**i)), (n+1,), dtype = float)
    N = np.sum(NA) * P0 + n * Pok[-1] * np.sum(P0C)

    # Computing load coef K
    K = N / n

    # Computing P
    P = np.sum(P0C) * Pok[-1]

    # Compiting Q
    QA = np.fromfunction(lambda j: (j + 1) * p0product(n, j+1, lamb, mu, nu), (n + nmult + 1,), dtype = float)
    Q = np.sum(QA) * Pok[-1]

    data = pl.DataFrame({'n': [n], 'N': [N], 'k': [K], 'P(queue)': [P], 'Q': [Q]})
    dataframe_4 = dataframe_4.vstack(data)

tc = 9
ts = 47
tw = 66

lamb = 1/tc
mu = 1/ts
nmult = 25
nu = 1/tw

const = 20

for n in range(1, const+1):
    for m in range(1, const+1):
        second_task(lamb, mu, n, m)
for n in range(1, const+1):
    third_task(lamb, mu, n)
    fourth_task(n, nmult, lamb, mu, nu)

dataframe_1 = first_task(lamb, mu)
dataframe_2 = dataframe_2[1:]
dataframe_3 = dataframe_3[1:]
dataframe_4 = dataframe_4[1:]

 
def write_to_xlsx_file(dataframe, name):
    dataframe.write_excel(workbook=name)

write_to_xlsx_file(dataframe_1, 'task1-1')
write_to_xlsx_file(dataframe_2, 'task1-2')
write_to_xlsx_file(dataframe_3, 'task1-3')
write_to_xlsx_file(dataframe_4, 'task1-4')

plot_2(dataframe_2, const)
plot_3_4(dataframe_3, const, 3)
plot_3_4(dataframe_4, const, 4)