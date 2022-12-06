#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#define ROW 6
#define COLUMN 8

void fill(int[][COLUMN]);
void sum(int[], int[][COLUMN]);
void swap(int[][COLUMN], int, int);
void maximum(int[], int * , int * );
void minimum(int[], int * , int * );
void print(int[][COLUMN]);

int main() {
  srand(time(NULL));
  int mas[ROW][COLUMN], max = -41, min = 121, points[ROW] = {0}, r_min = 0, r_max = 0;
  fill(mas);
  printf("Before swap:\n");
  print(mas);
  sum(points, mas);
  maximum(points, & max, & r_max);
  minimum(points, & min, & r_min);
  printf("\n\nMaximum (row %d) = %d\tMinimum (row %d) = %d\n\n", r_max + 1, max, r_min + 1, min);
  swap(mas, r_min, r_max);
  printf("After swap:\n");
  print(mas);
  printf("\n");
}

void fill(int mas[][COLUMN]) {
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COLUMN; j++) {
      mas[i][j] = rand() % 21 - 5;
    }
  }
}

void sum(int points[], int mas[][COLUMN]) {
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COLUMN; j++) {
      points[i] += mas[i][j];
    }
  }
}

void swap(int mas[][COLUMN], int r_min, int r_max) {
  for (int j = 0; j < COLUMN; j++) {
    mas[r_min][j] = mas[r_max][j] ^ mas[r_min][j];
    mas[r_max][j] = mas[r_max][j] ^ mas[r_min][j];
    mas[r_min][j] = mas[r_max][j] ^ mas[r_min][j];
  }
}

void maximum(int points[], int * max, int * r_max) {
  for (int i = 0; i < ROW; i++) {
    if (points[i] > * max) {
      * max = points[i];
      * r_max = i;
    }
  }
}

void minimum(int points[], int * min, int * r_min) {
  for (int i = 0; i < ROW; i++) {
    if (points[i] < * min) {
      * min = points[i];
      * r_min = i;
    }
  }
}

void print(int mas[][COLUMN]) {
  for (int i = 0; i < ROW; i++) {
    printf("\n%d\t", i + 1);
    for (int j = 0; j < COLUMN; j++) {
      printf("%d ", mas[i][j]);
    }
  }
}
