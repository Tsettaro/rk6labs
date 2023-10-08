#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TEAMS 8

void fill_zero(int [][TEAMS]);
void games(int [][TEAMS]);
void table(int [][TEAMS]);
void points(int [][TEAMS]);

int main(){
    srand(time(NULL));
    int mas[TEAMS][TEAMS];
    fill_zero(mas);
    games(mas);
    table(mas);
    points(mas);
}

void fill_zero(int mas[][TEAMS]){
    for (int i = 0; i < TEAMS; i++){
        mas[i][i] = 0;
    }
}

void games(int mas[][TEAMS]){
    for (int i = 0; i < TEAMS; i++){
        for (int j = i+1; j < TEAMS; j++){
            mas[i][j]=rand() % 3;
            switch (mas[i][j])
            {
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
void table(int mas[][TEAMS]){
    printf("Fixture table:\n\n       1   2   3   4   5   6   7   8\n     –––––––––––––––––––––––––––––––-–\n");
    for (int i = 0; i < TEAMS; i++){
        printf("  %d  | ", i+1);
        for (int j = 0; j < TEAMS; j++){
            printf("%d | ", mas[i][j]);
        }
        printf("\n     –––––––––––––––––––––––––––––––-–\n");
    }
}

void points(int mas[][TEAMS]){
    int maxi = -1, points[TEAMS]={0};
    printf("\nPoints of every team:\n");
    for (int i = 0; i < TEAMS; i++){
        for (int j = 0; j < TEAMS; j++){
            points[i]+=mas[i][j];
        }
        if (points[i] > maxi) maxi = points[i];
        printf("Team %d – %d\n", i+1, points[i]);
    }
    printf("\nMaximum of points – %d\n", maxi);
    printf("Best teams – ");
    for (int i = 0; i < TEAMS; i++){
        if (points[i] == maxi){
            printf("%d", i+1);
            switch (i+1)
            {
            case 1: printf("-st ");
                    break;
            case 2: printf("-nd ");
                    break;
            case 3: printf("-rd ");
                    break;
            default:
                    printf("-th ");
                    break;
            }
        }
    }
    putchar('\n');
}