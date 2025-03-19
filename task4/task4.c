#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) { return (a - b); }

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Use: %s input_file\n", argv[0]);
    exit(1);
  }

  FILE *file = fopen(argv[1], "r");
  if (!file) {
    printf("File nf %s\n", argv[1]);
    exit(1);
  }

  int numbers[1000];
  int n = 0;

  while (fscanf(file, "%d", &numbers[n]) == 1) {
    n++;
  }
  fclose(file);

  if (!n) {
    printf("В файле отсутствуют числа\n");
    exit(1);
  }

  qsort(numbers, n, sizeof(int), compare);
  int median = numbers[n / 2];

  int steps = 0;
  for (int i = 0; i < n; i++) {
    steps = steps + abs(numbers[i] - median);
  }

  printf("%d\n", steps);

  return 0;
}
