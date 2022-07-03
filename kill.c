#include <stdio.h>
#include <stdlib.h>
#include <syscall.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
  error:
    printf("usage: kill [pid]\n");
    exit(1);
  }
  for (int i = 1; i < argc; i++) {
    if (!(atoi(argv[i])))
      goto error;
    if (syscall(SYS_kill, atoi(argv[i]), 15))
      perror("error");
    else
      printf("%i killed\n", atoi(argv[i]));
  }
}
