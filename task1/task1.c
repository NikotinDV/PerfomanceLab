#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Use: %s n m\n", argv[0]);
    exit(1);
  }
  int n = atoi(argv[1]), m = atoi(argv[2]);
  int arr[n], arr2[m];
  for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
  }
  int i;
  while (arr[0] != arr2[m - 1]) {
    for (int t = 0; t < m; t++) {
      i = (i == n) ? 0 : i;
      arr2[t] = arr[i];
      i = (t < m - 1) ? i + 1 : i;
    }
    printf("%d", arr2[0]);
  }
  printf("\n");
  return 0;
}