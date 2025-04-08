#include "get_file_size.h"
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>

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

int main(int argc, char *argv[]) {
  // Checks the input arguments
  if (argc == 1) {
    printf("reowc [option] file\n\n");
    printf("options:\n");
    printf("\t-c  file size (bytes)\n");
    printf("\t-l  number of lines\n");
    printf("\t-m  number of characters\n");
    printf("\t-w  number of words\n\n");

    return 1;
  }

  if (strcmp(argv[1], "-c") == 0) {
    long file_size = get_file_size(argv[2]);
    if (argv[2] != NULL) {
      printf("%ld\t%s\n", file_size, argv[2]);
    } else {
      printf("%ld\n", file_size);
    }
  } else if (strcmp(argv[1], "-l") == 0) {
    int lines_count = get_lines_count(argv[2]);
    if (argv[2] != NULL) {
      printf("%d\t%s\n", lines_count, argv[2]);
    } else {
      printf("%d\n", lines_count);
    }
  } else if (strcmp(argv[1], "-w") == 0) {
    int words_count = get_words_count(argv[2]);
    if (argv[2] != NULL) {
      printf("%d\t%s\n", words_count, argv[2]);
    } else {
      printf("%d\n", words_count);
    }
  } else if (strcmp(argv[1], "-m") == 0) {
    int char_count = get_characters_count(argv[2]);
    if (argv[2] != NULL) {
      printf("%d\t%s\n", char_count, argv[2]);
    } else {
      printf("%d\n", char_count);
    }
  } else {
    int lines_count = get_lines_count(argv[1]);
    int words_count = get_words_count(argv[1]);
    long file_size = get_file_size(argv[1]);
    printf("%d\t%d\t%ld\t%s\n", lines_count, words_count, file_size, argv[1]);
  }

  return 0;
}
