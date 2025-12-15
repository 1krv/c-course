#include <stdio.h>

int main(void) {
    int a = 10;
    unsigned int b = 20;
    float y = 1.3424;

    char c = 127;
    int i = c + 1;
    char d = c + 1;
    unsigned char cc = 255;
    (cc++);

    printf("%d; %.2f; %d\n", a, y, b);
    printf("c: %d\t i:%d\t d:%d\n", c, i, d);
    printf("cc + 1: %d\n", cc + 1);

    return 0;
}
