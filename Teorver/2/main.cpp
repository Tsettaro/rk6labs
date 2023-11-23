#include <iostream>
#include <cmath>
#include <iomanip>
using std::cin;

int factorial(int i)
{
  if (i==0) return 1;
  else return i*factorial(i-1);
}

void first_task(long double lambda, long double nu){
    long double sum = 0, M = 0, k = 0, ro = lambda/nu;
    for (int i = 0; i < 4; i++){
        long double p_0 = 1/(sum + pow(ro, i)/factorial(i));
        sum += p_0;
        long double p = pow(ro, i)/factorial(i) * p_0;
        M += p * i;
        std::cout << "n = " << i << " p = " << p << " M = " << M;
        if (i > 0) std::cout << " k = " << M/i;
        std::cout << '\n';
    }
}

int main(){
    int R1, G1, B1, R2, G2, B2, R3, G3, B3;
    cin >> R1 >> G1 >> B1;
    cin >> R2 >> G2 >> B2;
    cin >> R3 >> G3 >> B3;

    long double T_c = R1 + G1 + B1, T_s = R2;
    long double lambda = 1/T_c, nu = 1/T_s;

    first_task(lambda, nu);
}
