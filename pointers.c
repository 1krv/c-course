#include <stdio.h>

void inc(int *p) {
  printf("address of p: %p\n", p);
  ++(*p);
}

int main(void) {
  int x = 0;

  printf("before %d\n", x);
  inc(&x);
  printf("addres of x: %p\n", &x);
  printf("after %d\n", x);
  return 0;
}
