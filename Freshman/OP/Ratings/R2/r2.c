#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#define ROW 6
#define COLUMN 8

void fill(int[][COLUMN]);
void sum(int[], int[][COLUMN]);
void swap(int[][COLUMN], int, int);
int maximum(int[]);
int minimum(int[]);
void print(int[][COLUMN]);

int main() {
  srand(time(NULL));
  int mas[ROW][COLUMN], points[ROW] = {0};
  fill(mas);
  printf("Before swap:\n");
  print(mas);
  sum(points, mas);
  int r_max = maximum(points), r_min = minimum(points);
  swap(mas, r_min, r_max);
  printf("\n\nAfter swap:\n");
  print(mas);
  printf("\n\nSwaped rows - %d and %d.\n", r_max + 1, r_min + 1);
}

void fill(int mas[][COLUMN]) {        // Заполнение массива псевдослучайными числами
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COLUMN; j++) {
      mas[i][j] = rand() % 21 - 5;
    }
  }
}

void sum(int points[], int mas[][COLUMN]) {       // Сумма чисел в каждой строке
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COLUMN; j++) {
      points[i] += mas[i][j];
    }
  }
}

void swap(int mas[][COLUMN], int r_min, int r_max) {   // Замена строк с максимальными и минимальными суммами местами
  int tmp;
  for (int j = 0; j < COLUMN; j++) {
    tmp = mas[r_min][j];
    mas[r_min][j] = mas[r_max][j];
    mas[r_max][j] = tmp;
  }
}

int maximum(int points[]) {       // Индекс строки с максимальной суммой
  int max = -41, r = 0; 
  for (int i = 0; i < ROW; i++) {
    if (points[i] > max) {
      max = points[i];
      r = i;
    }
  }
  return r;
}

int minimum(int points[]) {       // Индекс строки с минимальной суммой
  int min = 121, r = 0;
  for (int i = 0; i < ROW; i++) {
    if (points[i] <  min) {
      min = points[i];
      r = i;
    }
  }
  return r;
}

void print(int mas[][COLUMN]) {       // Вывод массива на экран
  for (int i = 0; i < ROW; i++) {
    printf("\n%d\t", i + 1);
    for (int j = 0; j < COLUMN; j++) {
      printf("%d ", mas[i][j]);
    }
  }
}
