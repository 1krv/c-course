#include <stdio.h>

void hello(void) {
    printf("Hello!\n");
}

void baubau(void) {
    printf("Bau Bau!\n");
}

void call_n_times(int n, void(*x)(void)) {
    while(n--) {
        x();
    }
}

int main(void) {
    printf("%p\n", main);

    call_n_times(10, hello);
    call_n_times(10, baubau);
    return 0;
}
