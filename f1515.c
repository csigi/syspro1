#include "apue.h"
#include <sys/wait.h>

int main(void) {
  char line[MAXLINE];
  FILE *fpin;

  if ((fpin = popen("./f1514", "r")) == NULL)
    err_sys("popen error");

  for (;;) {
    fputs("ProMpt> ", stdout);
    fflush(stdout);
    if (fgets(line, MAXLINE, fpin) == NULL) // read from pipe
      break;
    if (fputs(line, stdout) == EOF)
      err_sys("fputs error to pipe");
  }
  if (pclose(fpin) == -1)
    err_sys("pclose error");
  putchar('\n');
  exit(0);
}
