#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct pls {
    uint32_t len;
    uint32_t refcount;
    uint32_t magic;
    char str[];
};

/* Create a new reference-counted, prefixed-length string based on
 * the buffer 'init' of length 'len'.
 *
 * The allocated memory layout is structured as follows:
 *
 * +----------+----------+----------+-------------------+
 * |   len    | refcount |  magic   |   string data...  |
 * +----------+----------+----------+-------------------+
 * | 4 bytes  | 4 bytes  | 4 bytes  |   len + 1 bytes   |
 * +----------+----------+----------+-------------------+
 *                                  |
 * Returned pointer (str) ----------+
 *
 * Key details:
 * 1. Hidden Header: The function returns a pointer to the 'string data'
 * part. The metadata (struct pls) is hidden immediately before this
 * pointer and accessed via pointer arithmetic.
 *
 * 2. Reference Counting: The object is initialized with refcount = 1.
 * Use ps_retain() and ps_release() to manage ownership.
 *
 * 3. Validation: The 'magic' field (0xDEADBEEF) is set to allow
 * runtime validation and detect corruption or invalid pointers.
 *
 * 4. Binary Safe: Since 'len' is stored explicitly, the string can
 * contain null bytes ('\0') in the middle.
 *
 * Note: This function allocates memory but does not check for buffer
 * overflow on the input source 'init'. */
char *ps_create(char *init, int len) {
    struct pls *p = malloc(sizeof(struct pls) + len + 1);
    p->len = len;
    p->refcount = 1;
    p->magic = 0xDEADBEEF;

    for (int j = 0; j < len; j++) {
        p->str[j] = init[j];
    }

    p->str[len] = 0;

    return p->str;
}

/* Display the string 's' on the screen. */
void ps_print(char *s) {
    struct pls *p = (struct pls *)(s - sizeof(*p));
    for (uint32_t j = 0; j < p->len; j++) {
        putchar(p->str[j]);
    }
    printf("\n");
}

/* Free a previously created PS string. */
void ps_free(char *s) {
    free(s - sizeof(struct pls));
}

/* Validate that a PS string looks valid. */
void ps_validate(struct pls *p) {
    if (p->magic != 0xDEADBEEF) {
        printf("INVALID STRING: Aborting\n");
        exit(1);
    }
}

/* Drop the reference count of the string object by one
 * and free the object if the refcount reached 0. */
void ps_release(char *s) {
    struct pls *p = (struct pls *)(s - sizeof(*p));
    ps_validate(p);

    p->refcount--;
    if (p->refcount == 0) {
        p->magic = 0;
        ps_free(s);
    }
}

/* Increase the reference count of the string object by one. */
void ps_retain(char *s) {
    struct pls *p = (struct pls *)(s - sizeof(*p));
    if (p->refcount == 0) {
        printf("ABORTED ON RETAIN OF ILLEGAL STRING\n");
        exit(1);
    }

    p->refcount++;
}

uint32_t ps_len(char *s) {
    struct pls *p = (struct pls *)(s - sizeof(*p));
    return p->len;
}

char *global_string;

int main(void) {
    char *mystr = ps_create("Hello World Hello World Hello World", 35);
    global_string = mystr;
    ps_retain(mystr);

    ps_print(mystr);
    printf("%s\n", mystr);
    ps_release(mystr);

    printf("%s\n", global_string);
    ps_release(mystr);
    return 0;
}
