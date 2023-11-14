import math

def first_task(lamb, nu):
    local_p = []
    ro = lamb/nu
    sum = 0
    n = 0
    while(True):
        sum += (ro**n)/math.factorial(n)
        local_p.append((ro**n)/math.factorial(n))
        if ((ro**n)/math.factorial(n) < 0.01):
            break
        n+=1
    p0 = 1/sum
    local_p = [local_p * p0 for local_p in local_p]
    N = 0
    arr_N = []
    for n in range(len(local_p)):
        N += n * local_p[n]
        arr_N.append(N)
    for n in range(len(local_p)):
        if (n == 0): continue
        print(f'p{n} = {local_p[n]}')
        print(f'N{n} = {arr_N[n]}')
        print(f'k{n} = {N/n}')
        print('\n')
    return n

def second_task(lamb, nu, n): # NOT FINISHED
    local_p = []
    ro = lamb/nu
    sum = 0
    n = 0
    for i in range(n):
        sum += (ro**i)/math.factorial(i)
        local_p.append((ro**i)/math.factorial(i))

    return n

lamb = 1/19
nu = 1/7
a = first_task(lamb, nu)
second_task(lamb, nu, a)