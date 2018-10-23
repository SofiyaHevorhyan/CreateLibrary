#include <stdio.h>
#include "library/lib_for_str.h"

int main() {
    printf("Hello, World!\n");
    my_str_t str;
    my_str_create(&str, 12);
    char data[5] = {'a', 'b', 'c', 'd', '\0'};
    char* pdata = data;
    int a = 1;
    for (pdata; *pdata != '\0'; pdata++) {
        printf("%c", *pdata);


    }
    printf("%c", pdata);



    return 0;
}


