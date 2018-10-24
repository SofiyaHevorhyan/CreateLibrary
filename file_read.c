//
// Created by yarka on 10/23/18.
//

#include <stdio.h>
#include "library/lib_for_str.h"

int read_write(const char* file_read,const char* file_write) {
    FILE* file = fopen(file_read, "r");
    my_str_t str;

    FILE* result = fopen(file_write, "a");
    while (my_str_read_word(&str, file) != -1) {
        printf("/more\n");
        fwrite(&str, my_str_size(&str), 1, result);
        my_str_free(&str);
    }
    fclose(file);
    fclose(result);
    return 0;
}
