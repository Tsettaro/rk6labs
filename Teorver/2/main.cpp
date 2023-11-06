#include <iostream>
#include <ctype>

using std::cin;

int main(){
    int R1, G1, B1, R2, G2, B2, R3, G3, B3;
    cin >> R1 >> G1 >> B1;
    cin >> R2 >> G2 >> B2;
    cin >> R3 >> G3 >> B3;

    int T_c = R1 + G1 + B1, T_s = R2;
    int lambda_c = 1/T_c, lambda_s = 1/T_s;
}
