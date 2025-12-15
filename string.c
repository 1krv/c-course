#include <stdio.h>

char string[] = "hello-world";
short CODE_INT = 289;

void cipher(short k) {
    int i = 0;
    k = k % 26;
    while (string[i] != 0) {
        if (string[i] < 97 || string[i] > 122) {
            i++;
            continue;
        }

        if (string[i] + k >= 122) {
            int diff = string[i] + k - 122;
            string[i] = 97 + diff;
        } else {
            string[i] = string[i] + k;
        }
        i++;
    }
    printf("%s\n", string);
}

void decipher(short k) {
    int i = 0;
    k = k % 26;
    while (string[i] != 0) {
        if (string[i] < 97 || string[i] > 122) {
            i++;
            continue;
        }

        if (string[i] - k <= 97) {
            int diff = string[i] - 97;
            string[i] = 122 - (k - diff);
        } else {
            string[i] = string[i] - k;
        }
        i++;
    }
    printf("%s\n", string);
}

int main(void) {
    char str[] = "hello";
    printf("[Hello World]> %s \n", str);
    printf("sizeof: %lu\n", sizeof(str));

    printf("\n");
    cipher(CODE_INT);
    decipher(CODE_INT);

    return 0;
}
