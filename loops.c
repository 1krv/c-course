#include <stdio.h>

/*
void count_vanilla(int start, int end) {
    if (start > end) return;
    printf("%d\n", start);
    count_vanilla(start + 1,  end);
}
*/

/* Tail Call Optimization (TCO) implementata tramite goto */
void count(int start, int end) {
iterate:
    if (start > end) return;
    printf("%d\n", start);
    start = start + 1;
    goto iterate;
}

void hello_world(int n, char str[]) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", str);
    }
}

int main(void) {
    count(1, 9);
    hello_world(10, "Hello WRLD!");
    return 0;
}
