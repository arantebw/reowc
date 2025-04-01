#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Checks the input arguments
  if (argc > 1 == 0) {
    printf("Error: Provide a target file and at least of the following "
           "options:\n");
    printf("-c  file size (bytes)\n");
    printf("-l  number of lines\n\n");
    printf("Help:\n");
    printf("reowc [option] [target_file]\n");

    return 1;
  }

  // Return the file size
  if (strcmp(argv[1], "-c") == 0) {
    FILE *input_file = fopen(argv[2], "rb");
    fseek(input_file, 0, SEEK_END);
    long file_size = ftell(input_file);
    fclose(input_file);

    printf("%ld\t%s\n", file_size, argv[2]);
  }

  // Return the number of lines
  if (strcmp(argv[1], "-l") == 0) {
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

  return 0;
}
