#include <stdio.h>
#include <stdlib.h>

int glob = 100;

int main(void) {
  int var = 10;
  int pid;

  printf("before fork() \n");

  pid = fork();

  if (pid < 0) {
    printf(" Fork() error !\n");
    exit(0);
 
  } else if (pid == 0) {
    printf("child process()\n");
    var++;
    glob--;
  } else {
    sleep(2);
  }

  printf("pid = %d, var = %d glob_val = %d \n", pid, var, glob);
  return 0;
}
