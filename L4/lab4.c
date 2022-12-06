#include <stdio.h>
#include <math.h>

void in(double *eps){
    printf("Enter epsilon: ");
    while(scanf("%lf",eps) != 1)
    {
     while(getchar() != '\n') ;
     printf("Error. Try again!\nEnter epsilon: ");
    }
}

int fib(int n){                          // получение n-го числа Фибоначчи
  int a1 = 1, a2 = 1;
  for (int i = 3; i <= n; i++){
    a2 = a1 + a2;
    a1 = a2 - a1;
  }
  return a2;
}

double ot(double n2, double n1){         // получение отношения двух послед. чисел Фибоначчи
  double o;
  o = ((double)fib(n2)) / (fib(n1));
  return o;
}

// Ряд Фибоначчи: 1 1 2 3 5 8 13 21

void gar(double eps){                    // Коэффициент зол. сечения, абсолютная и относительная погрешности
  int i = 3;
  double cor_gr = (sqrt(5) + 1) / 2;
  double a = fabs(ot(i, i - 1)-ot(i - 1,i - 2));
  while (a > eps){
  	i++;
  	a = fabs(ot(i, i - 1) - ot(i - 1,i - 2));
  }
  double A = fabs(ot(i, i - 1) - cor_gr);
  printf("Golden ratio: %.15f\nAbsolute error: %.15f\n",ot(i, i - 1), A);
  printf("Relative error: %.15f\n", (A/cor_gr)*100);
}

int main() {
	double eps;
	in(&eps);
	gar(eps);
}
