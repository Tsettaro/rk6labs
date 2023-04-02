#include <stdio.h>
#include <stdlib.h>
#define EP 4
double in_num(){
	double num;
    printf("Enter number: ");
    while(scanf("%lf", &num) != 1)
    {
     while(getchar() != '\n') ;
     printf("Error. Try again!\nEnter number: ");
    }
	return num;
}

int new_base(){
    int base;
    printf("Enter base: ");
    while(scanf("%d",&base) != 1 || base < 2 || base > 16)
    {
     while(getchar() != '\n') ;
     printf("Error. Try again!\nEnter base: ");
    }
    return base;
}

int size_prt1(int base, int new_part1){
    int cur = base, i = 1;
    while (cur < new_part1){
        cur *= base;
        i++;
    }
    return i;
}

void comp_dec(int new_part1, int base){
    int p1[size_prt1(base, new_part1)];
    int i = 0;
    while (new_part1 >= base){
        int ost = new_part1 % base;
        p1[i] = ost;
        i++;
        new_part1 /= base;
    }
    p1[i] = new_part1;
    for (int j = i; j >= 0; j--){
        printf("%X", p1[j]);
    }
}
 
void comp_rat(double new_part2, int base){
    printf(".");
    for (int j = 0; j < EP; j++){
        double p = new_part2 * base;
        int i = (int)p;
        printf("%X", i);
        new_part2 = p - i;
    }
    printf("\n");
}

int main(){
    double new_part2, num = in_num();
    int base = new_base();
    int new_part1 = (int)num;                                      
	if (num < 0){
		new_part2 = -num - abs(num);
		printf("Translated number: -");
	} else{
		new_part2 = num - abs(num);
		printf("Translated number: ");
	}
	comp_dec(abs(new_part1), base); // целая часть
	comp_rat(new_part2, base); // дробная часть
}
