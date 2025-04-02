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
  } else if (strcmp(argv[1], "-c") == 0) {
    get_file_size(argv[2]);
  }
  // Return the number of lines
  else if (strcmp(argv[1], "-l") == 0) {
    FILE *input_file = fopen(argv[2], "r");
    int ch;
    int line_count = 0;
    while ((ch = fgetc(input_file)) != EOF) {
      if (ch == '\n') {
        line_count++;
      }
    }
    fclose(input_file);

    printf("%d\t%s\n", line_count, argv[2]);
  }
  // Return the number of words
  else if (strcmp(argv[1], "-w") == 0) {
    FILE *input_file = fopen(argv[2], "r"); // open a file stream

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

    printf("%d\t%s\n", count, argv[2]);
  }
  // Return the number of characters
  else if (strcmp(argv[1], "-m") == 0) {
    setlocale(LC_ALL, ""); // set locale to default environment locale

    FILE *input_file = fopen(argv[2], "r");

    int c;
    int count;
    // Use `fgetwc` to read wide characters
    while ((c = fgetwc(input_file) != WEOF)) {
      count++;
    }

    fclose(input_file);

    printf("%d\t%s\n", count, argv[2]);
  } else {
    //
  }

  return 0;
}
