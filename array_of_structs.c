#include <stdio.h>
#include <stdlib.h>

typedef struct _some_struct {
    int a; // 4 -> 8 for memory alignment
    int *b; // 8
    char *str; // 8
    struct _some_struct *partner; // 8
} some_struct_t, *some_struct_pt; // total size of struct = 32


int main() {
    printf("Hello, World!\n");
    printf("sizeof(some_struct_t) = %lu!\n", (unsigned long) sizeof(some_struct_t));
    const unsigned ARRAY_SIZE = 100;

    some_struct_t static_ss;
    static_ss.a = 10;
    static_ss.b = &static_ss.a;
    static_ss.str = "array\n";
    static_ss.partner = NULL;

    // allocate the array
    some_struct_pt array_of_ss = (some_struct_pt) calloc(ARRAY_SIZE, sizeof(some_struct_t));

    // traverse the array
    for (unsigned u=0; u<ARRAY_SIZE; u++) {
        array_of_ss[u] = static_ss;
    }

    // print
    for (unsigned u=0; u<ARRAY_SIZE; u++) {
        printf("%d-%d-%s\n", array_of_ss[u].a, *array_of_ss[u].b, array_of_ss[u].str);
    }

    // free the array
    free(array_of_ss);

    return 0;
}
