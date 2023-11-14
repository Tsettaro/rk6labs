#include <iostream>
#include <cmath>
#include <vector>
using std::cin, std::vector;

int factorial(int i)
{
  if (i==0) return 1;
  else return i*factorial(i-1);
}

void first_task(long double lambda, long double nu){
    vector<long double> p;
    long double sum = 0, M = 0, k = 0, ro = lambda / nu, p0 = 0;
    for (int i = 0; i < 4; i++){
        if (i == 0) {
            p0 = 1;
        } else {
            p0 = (long double) pow(ro, i) / factorial(i);
        }
        std::cout << p0 << '\n';
        p.push_back(p0);
        sum += p0;
    }
    p0 = 1 / sum;
}



int main(){
    /*int R1, G1, B1, R2, G2, B2, R3, G3, B3;
    cin >> R1 >> G1 >> B1;
    cin >> R2 >> G2 >> B2;
    cin >> R3 >> G3 >> B3;

    long double T_c = R1 + G1 + B1, T_s = R2;*/
    long double lambda = 1/19, nu = 1/7;

    first_task(lambda, nu);
}
