#include "get_words_count.h"
#include <ctype.h>
#include <stdio.h>

int get_words_count(char *file) {
  int c;
  int count = 0;
  int in_word = 0;

  if (file != NULL) {
    FILE *input_file = fopen(file, "r");
    // Traverse each character
    while ((c = fgetc(input_file)) != EOF) {
      if (isspace(c)) {
        if (in_word) { // a word is found
          count++;
          in_word = 0;
        }
      } else {
        in_word = 1;
      }
    }
    fclose(input_file); // close a file stream
  } else {
    while ((c = fgetc(stdin)) != EOF) {
      if (isspace(c)) {
        if (in_word) { // a word is found
          count++;
          in_word = 0;
        }
      } else {
        in_word = 1;
      }
    }
  }

  return count;
}

