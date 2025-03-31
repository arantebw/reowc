#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc > 1 == 0) {
    printf("Error: Provide a target file and at least of the following "
           "options:\n");
    printf("-c  return the file size in bytes\n\n");
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

  return 0;
}
