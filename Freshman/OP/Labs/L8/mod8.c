#include <stdio.h>
#include <math.h>
#define EPS 0.1E-1
#define REAL 3

double f(double);
double solution(double, double);
void out(double);

int main(){
    double a = 0, b = 4, answer;
	if ((f(a)*f(b))>0) printf("ERROR\n");
	else{
		answer = solution(a,b);
		out(answer);
	}
}

double f(double x){                       // функция  (not working with y = x*x)
    return 20 - exp(x) + cos(x);
}

double solution(double a, double b){     // корень
    double c = (b+a)/2;
    while (fabs(f(c)) > EPS){
        (f(a)*f(c)<0) ? (b = c) : (a = c);
        c = (a+b)/2;
    }
    return c;
}

void out(double c){                      // вывод
    double absolute = fabs(REAL-c);
    printf("\033[92mX = \033[97m%lf\n\033[92mАбсолютная погрешность - \033[97m%lf\n\033[92mОтносительная погрешность - \033[97m%lf %\n", c, absolute, (absolute/fabs(c))*100);
}
