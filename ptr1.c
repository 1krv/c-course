#include <stdio.h>

void print_string(char *p_str) {
    while (*p_str) {
        putchar(*p_str);
        p_str++;
    }
    puts("");
}

void swap(int *px, int *py) {
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

int main(void) {
    char mystr[] = "Hello World";

    int x = 10;
    int y = 25;

    print_string(mystr);
    print_string(mystr+6);

    printf("Before swap: x %d y %d\n", x, y);
    swap(&x, &y);
    printf("After swap: x %d y %d\n", x, y);

    return 0;
}
