#include <stdio.h>

int in(){
    int a;
    printf("Введите свой возраст: ");
    while((scanf("%d",&a) != 1) || a > 100 || a < 1){
        while(getchar() != '\n') ;
        printf("Ошибка! Попробуйте снова.\nВведите свой возраст: ");
    }
}



void yr(int age){                  // обработка вывода "год", "года" и "лет"
    if (age >= 11 && age <= 14) printf("%d лет.\n", age);
    else{
        int ost = age % 10;
        switch(ost){
        case 1:
			printf("%d год.\n", age);
            break;
        case 2 ... 4: 
			printf("%d года.\n", age);
            break;
		default:
			printf("%d лет.\n", age);
			break;
        }
    }

}

void adult(int age){   // совершеннолетие
	switch(age){
		case 1 ... 17:
			printf("Вам до совершеннолетия ");
			yr(18 - age);
			break;
		case 18:
			printf("Вы совершеннолетний.\n");
			break;
		default:
			printf("Вы совершеннолетний ");
        	yr(age-18);
			break;
	}

}

void pensioner(int age){   // пенсия
	switch(age){
		case 1 ... 59:
			printf("Вам до пенсии ");
            yr(60 - age);
			break;
		case 60:
			printf("Вы пенсионер.\n");
			break;
		default:
			printf("Вы на пенсии ");
            yr(age - 60);
			break;
	}
}

int main() {
    int age = in();
    adult(age);
	pensioner(age);
}
