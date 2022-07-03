#include <limits.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  char pwd[PATH_MAX];
  getcwd(pwd, sizeof(pwd));
  printf("%s\n", pwd);
}
