#include "apue.h"

int main(void) {
  int n;
  int fd[2];
  pid_t pid;
  char line[MAXLINE];

  if (pipe(fd) < 0)
    err_sys("pipe error");
  if ((pid = fork()) < 0) {
    err_sys("fork error");
  } else if (pid > 0) { // parent
    //close(fd[0]);
    printf("closed fd[0] in parent\n");
    write(fd[1], "hello world\n", 12);
    printf("wrote 'hello world' to child\n");
  } else { // child
    //close(fd[1]);
    printf("closed fd[1] in child\n");
    n = read(fd[0], line, MAXLINE);
    printf("read from parent through pipeline\n");
    write(STDOUT_FILENO, line, n);
    printf("wrote to output from child\n");
  }
  exit(0);
}
