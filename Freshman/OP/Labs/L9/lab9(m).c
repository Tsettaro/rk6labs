#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TEAMS 8

void fill_zero(int [][TEAMS]);
void games(int [][TEAMS]);
void sum(int [][TEAMS], int []);
int maximum(int []);
void result(int [][TEAMS], int [], int);

int main(){
    srand(time(NULL));
    int mas[TEAMS][TEAMS], points[TEAMS]={0};
    fill_zero(mas);
    games(mas);
	sum(mas, points);
	int maxi = maximum(points);
    result(mas, points, maxi);
}

void fill_zero(int mas[][TEAMS]){   // заполнение главной диагонали нулями
    for (int i = 0; i < TEAMS; i++){
        mas[i][i] = 0;
    }
}

void games(int mas[][TEAMS]){      // очки за игру
    for (int i = 0; i < TEAMS; i++){
        for (int j = i+1; j < TEAMS; j++){
            mas[i][j]=rand() % 3;
            switch (mas[i][j]){
            case 0: mas[j][i] = 3;
                    break;
            case 1: mas[j][i] = 1;
                    break;
            case 2: mas[j][i] = 0;
            }
            if (mas[i][j]==2) mas[i][j]+=1;
        }
    }
}

int maximum(int a[]){
	int maxi = -1;	
	for (int i = 0; i < TEAMS; i++){
		if (a[i] > maxi) maxi = a[i];	
	}
	return maxi;
}

void sum(int mas[][TEAMS], int points[]){
    for (int i = 0; i < TEAMS; i++){
        for (int j = 0; j < TEAMS; j++){
            points[i]+=mas[i][j];
        }
    }
}

void separate(int N){
	for (int a = 0; a < N; a++){
		printf("––––");		
	}
}

void result(int mas[][TEAMS], int points[], int maxi){ 
    printf("Fixture table:\n       ");
	for (int i = 1; i <= TEAMS; i++){
		printf("%d   ", i);	
	}
	printf("\n     –"); 

	separate(TEAMS);
	printf("\n");

    for (int i = 0; i < TEAMS; i++){
        printf("  %d  | ", i+1);
        for (int j = 0; j < TEAMS; j++){
            printf("%d | ", mas[i][j]);
        }
        printf("\n     –");
		separate(TEAMS);
		printf("\n");
    }

// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
	printf("\nPoints of every team:\n");
	for (int i = 0; i < TEAMS; i++){
		printf("Team %d – %d\n", i+1, points[i]);
	}
// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
	printf("\nMaximum of points – %d\n", maxi);
// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
    printf("Best teams:\n");
    for (int i = 0; i < TEAMS; i++){
        if (points[i] == maxi) printf("Team №%d\n", i+1);
    }
}

