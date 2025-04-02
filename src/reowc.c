#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>

void get_file_size(char *file) {
  FILE *input_file = fopen(file, "rb");
  fseek(input_file, 0, SEEK_END);
  long file_size = ftell(input_file);
  fclose(input_file);

  printf("%ld\t%s\n", file_size, file);
}

void get_lines_count(char *file) {
  FILE *input_file = fopen(file, "r");
  int c;
  int count = 0;
  while ((c = fgetc(input_file)) != EOF) {
    if (c == '\n') {
      count++;
    }
  }
  fclose(input_file);

  printf("%d\t%s\n", count, file);
}

void get_words_count(char *file) {
  FILE *input_file = fopen(file, "r"); // open a file stream

  int c;
  int count = 0;
  int in_word = 0;

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

  printf("%d\t%s\n", count, file);
}

void get_characters_count(char *file) {
  setlocale(LC_ALL, ""); // set locale to default environment locale

  FILE *input_file = fopen(file, "r");

  int c;
  int count = 0;
  // Use `fgetwc` to read wide characters
  while ((c = fgetwc(input_file)) != WEOF) {
    count++;
  }

  fclose(input_file);

  printf("%d\t%s\n", count, file);
}

int main(int argc, char *argv[]) {
  // Checks the input arguments
  if (argc > 1 == 0) {
    printf("reowc [option] file\n\n");
    printf("options:\n");
    printf("\t-c  file size (bytes)\n");
    printf("\t-l  number of lines\n");
    printf("\t-m  number of characters\n");
    printf("\t-w  number of words\n\n");

    return 1;
  }

  if (strcmp(argv[1], "-c") == 0) {
    get_file_size(argv[2]);
  } else if (strcmp(argv[1], "-l") == 0) {
    get_lines_count(argv[2]);
  } else if (strcmp(argv[1], "-w") == 0) {
    get_words_count(argv[2]);
  } else if (strcmp(argv[1], "-m") == 0) {
    get_characters_count(argv[2]);
  } else {
    //
  }

  return 0;
}
