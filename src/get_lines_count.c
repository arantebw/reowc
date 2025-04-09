#include "get_lines_count.h"
#include <stdio.h>

int get_lines_count(char *file) {
  int c;
  int count = 0;

  if (file != NULL) {
    FILE *input_file = fopen(file, "r");
    while ((c = fgetc(input_file)) != EOF) {
      if (c == '\n') {
        count++;
      }
    }
    fclose(input_file);
  } else {
    while ((c = fgetc(stdin)) != EOF) {
      if (c == '\n') {
        count++;
      }
    }
  }

  return count;
}

