#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Use: %s tests_file values_file report_file\n", argv[0]);
    exit(1);
  }
  FILE *tests = fopen(argv[1], "r");
  if (!tests) {
    printf("file %s nf\n", argv[1]);
    exit(1);
  }

  FILE *values = fopen(argv[2], "r");
  if (!values) {
    printf("file2 %s nf\n", argv[2]);
    exit(1);
  }

  FILE *report = fopen(argv[3], "w");
  if (!report) {
    printf("file3 %s nf\n", argv[3]);
    exit(1);
  }
  char tests_line[1024], values_line[1024], value[1024], result[1024];
  int id = 0, id2 = 0;

  while (fgets(tests_line, sizeof(tests_line), tests)) {
    if (sscanf(tests_line, " \"id\": %d,", &id) == 1) {
      fprintf(report, "%s", tests_line);
      fseek(values, 0, SEEK_SET);
      while (fgets(values_line, sizeof(values_line), values)) {
        sscanf(values_line, " \"id\": %d,", &id2);
        if (id == id2) {
          sscanf(values_line, " \"value\": \"%[^\"]\"", value);
        }
      }
    } else if (strstr(tests_line, " \"value\": \"\"")) {
      char *quote_pos = strrchr(tests_line, '"');
      size_t prefix_len = quote_pos - tests_line;
      strncpy(result, tests_line, prefix_len);
      strcpy(result + prefix_len, value);
      strcpy(result + prefix_len + strlen(value), quote_pos);
      fprintf(report, "%s", result);
    } else {
      fprintf(report, "%s", tests_line);
    }
  }

  fclose(tests);
  fclose(values);
  fclose(report);
  return 0;
}