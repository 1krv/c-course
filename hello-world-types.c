#include <stdio.h>
#include <limits.h>
#include <stdint.h>

void clear(void) {
    printf("\x1b[2J\x1b[H");
}

int main(void) {
    char c = 1; // intero 8 bit, 1 byte
    short s = 2000; // 16 bit, 2 bytes
    int x = 5; // 32 bit, 4 bytes
    long l = 10; // 64 bit, 8 bytes

    uint64_t y = 34;
    int64_t z = 3434;
    size_t a = 34344;

    clear();

    printf("size_t sizeof: %lu bytes\n", sizeof(a));
    printf("sizeof int64_t: %lu bytes\n\n", sizeof(z));

    printf("Hello, world: long min is %ld, int max is %ld\n",
        LONG_MIN, LONG_MAX);
    return 0;
}
