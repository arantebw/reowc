#include "get_characters_count.h"
#include <locale.h>
#include <stdio.h>
#include <wchar.h>

int get_characters_count(char *file) {
  setlocale(LC_ALL, ""); // set locale to default environment locale

  int c;
  int count = 0;

  if (file != NULL) {
    FILE *input_file = fopen(file, "r");

    // Use `fgetwc` to read wide characters
    while ((c = fgetwc(input_file)) != WEOF) {
      count++;
    }

    fclose(input_file);
  } else {
    // Use `fgetwc` to read wide characters
    while ((c = fgetwc(stdin)) != WEOF) {
      count++;
    }
  }

  return count;
}

