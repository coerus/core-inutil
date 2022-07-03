#include <stdio.h>

static void wrong_use(void) { printf("usage: cat [file]\n"); }

int main(int argc, char *argv[]) {
  FILE *ptr;
  char ch;

  if (argc == 1) {
    wrong_use();
  }
  for (int i = 1; i < argc; i++) {
    ptr = fopen(argv[i], "r");
    if (ptr == NULL) {
      perror(argv[i]);
      continue;
    }
    do {
      ch = fgetc(ptr);
      printf("%c", ch);
    } while (ch != EOF);
    fclose(ptr);
  }

  return 0;
}
