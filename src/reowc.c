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

  if (strcmp(argv[1], "-c") == 0) {
    printf("%s\n", argv[2]);
  }

  return 0;
}
