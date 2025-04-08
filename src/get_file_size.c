#include "get_file_size.h"
#include <stdio.h>

long get_file_size(char *file) {
  long file_size = 0;

  if (file != NULL) {
    FILE *input_file = fopen(file, "rb");
    fseek(input_file, 0, SEEK_END);
    file_size = ftell(input_file);
    fclose(input_file);
  } else {
    int ch;
    while ((ch = fgetc(stdin)) != EOF) {
      file_size++;
    }
  }

  return file_size;
}

