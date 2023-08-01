#include <stdio.h>
#include <math.h>

void in(double *a, double *b, double *c){
    printf("Enter values A,B,C: ");
    while(scanf("%lf %lf %lf",a,b,c) != 3)
    {
     while(getchar() != '\n') ;
     printf("Error. Try again!\nEnter values A,B,C: ");
    }
}

void complex(double D, double a, double b){
    const double sq = sqrt(fabs(D))/(2*a);
    if (b == 0) printf("X1 = i%g\nX2 = -i%g\n",sq,sq);
    else printf("X1 = %g + i%g\nX2 = %g - i%g\n",-b/(2*a),sq,-b/(2*a),sq);
}

void one_solution(double D,double a, double b){
    printf("X = %g\n",(-b-sqrt(D))/(2*a));
}

void two_solutions(double D,double a, double b){
    printf("X1 = %g\nX2 = %g\n",(-b-sqrt(D))/(2*a),(-b+sqrt(D))/(2*a));
}

int main(){
    double a,b,c;
    in(&a,&b,&c);
    if (a == 0) printf("Error! Value A can't be zero.\n");
    else
    {
        const double D = b*b-4*a*c;
        if (D < 0) complex(D,a,b);
        if (D == 0) one_solution(D,a,b);
        if (D > 0) two_solutions(D,a,b);
    }
}
