#include "library/lib_for_str.h"

int main() {
    printf("Hello, World!\n");
    my_str_t str;

    printf("%d\n", my_str_create(&str, 3));
    printf("%d %d %d %d %d", *str.data, *str.data+1,
            *str.data+2, *str.data+3, *str.data+4);

    return 0;
}