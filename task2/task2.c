#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void check(int *circle, int *point, int j) {
  for (int h = 0; h < j; h += 2) {
    float dist_square =
        pow(point[h] - circle[0], 2) + pow(point[h + 1] - circle[1], 2);
    if (dist_square < pow(circle[2], 2)) {
      printf("1\n");
    } else if (dist_square == pow(circle[2], 2)) {
      printf("0\n");
    } else {
      printf("2\n");
    }
  }
}

int main() {
  char file1[100], file2[100];
  int circle[3], point[256];
  int i = 0, j = 0;
  printf("Введите имя файла с координатами центра окружности и радиусом: ");
  scanf("%s", file1);
  FILE *fp1 = fopen(file1, "r");
  if (!fp1) {
    printf("file nf\n");
    exit(1);
  }
  while (fscanf(fp1, "%d", &circle[i]) == 1) {
    if (circle[i] < 10e-38 && circle[i] > 10e38) {
      printf("Числа вне диапазона\n");
      exit(1);
    } else {
      i++;
    }
  }
  fclose(fp1);

  printf("Введите имя файла с координатами точек: ");
  scanf("%s", file2);
  FILE *fp2 = fopen(file2, "r");
  if (!fp2) {
    printf("file2 nf\n");
    exit(1);
  }

  while (fscanf(fp2, "%d", &point[j]) == 1) {
    if (point[j] < 10e-38 && point[j] > 10e38) {
      printf("Числа вне диапазона\n");
      exit(1);
    } else {
      j++;
    }
  }
  fclose(fp2);

  if (j > 1 && j <= 200) {
    check(circle, point, j);
  } else {
    printf("Количество точек вне диапазона\n");
  }

  return 0;
}