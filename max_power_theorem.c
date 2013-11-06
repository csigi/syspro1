#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double square(double a);

int main(void) {
  double Rl, Rs, Xs, Xl, Vs, result ;
  Vs = 10;
  Xs = 10 / 1000;
  Xl = 0.01 / 1000000;
  Rs = 500;
  while (1) {
    printf("Input Rl:");
    scanf("%lf", &Rl);
    if (Rl < 0)
      break;
    result = (square(abs(Vs)) * Rl) / (square(Rs + Rl) + square(Xs+Xl));
    printf("%lf\n", result);
				     
  }
}

double square(double a) {
  return a*a;
}
