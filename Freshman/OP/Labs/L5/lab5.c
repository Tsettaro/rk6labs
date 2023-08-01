#include <stdio.h>

int in(){
    int a;
    printf("Введите свой возраст: ");
    while((scanf("%d",&a) != 1) || a > 100 || a < 1){
        while(getchar() != '\n') ;
        printf("Ошибка! Попробуйте снова\nВведите свой возраст: ");
    }
}



void yr(int age){                  // обработка вывода 
    if (age >= 11 && age <= 14) printf("%d лет.\n", age);
    else{
        int ost = age % 10;
        switch(ost){
        case 1: printf("%d год.\n", age);
                break;
        case 2:
        case 3:
        case 4: printf("%d года.\n", age);
                break;
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 0: printf("%d лет.\n", age);
                break;
        }
    }

}
void ord(int age){                 // обработка остальных возрастов
    if (age > 18){
        printf("Вы совершеннолетний ");
        yr(age-18);
        if (age > 18 && age < 60){
            printf("Вам до пенсии ");
            yr(60 - age);
        }
        else{
            printf("Вы на пенсии ");
            yr(age - 60);
        }
    }
    else{
        printf("Вам до совершеннолетия ");
        yr(18 - age);
        printf("Вам до пенсии ");
        yr(60 - age);
    }
}
void special(int age){          // обработка особых возрастов (18 и 60)
    printf("Вам исполнилось ");
    yr(age);
    switch(age){
        case 18: printf("Вы совершеннолетний.\n");
                 printf("Вам до пенсии 59 лет.\n");
                 break;
        case 60: printf("Вы совершеннолетний 42 года.\n");
                 printf("Вы пенсионер.\n");
                 break;
        default: ord(age);
    }
}
int main() {
    int age = in();
    special(age);
}
