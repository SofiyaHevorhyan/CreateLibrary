#include <stdio.h>
#include "library/lib_for_str.h"

int main() {
    printf("Hello, World!\n");
    my_str_t num;
    my_str_t* str = &num;
    my_str_create(str, 12);
    return 0;
}