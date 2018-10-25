#include "library/lib_for_str.h"
#include "file_read.h"
int static compare(char c);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Number of arguments must be 3 (program name, file_in, file_out.");
        return -1;
    }


    char *file_read = argv[1];
    char *file_write = argv[2];
    printf("Program starts!\n");
    my_str_t str;
    printf("Creating a string with buffer size 3...\n");
    my_str_create(&str, 3);
    printf("Creating a C string: ");
    const char *line = "symbol";
    printf("%s\n", line);
    printf("Recreating string from C string with buffer 6...\n");
    my_str_from_cstr(&str, line, 6);
    printf("Created string: %s.\n", str.data);
    if (my_str_empty(&str) == 1) {
        printf("Size of the string is %d, size of the buffer is %d, it is empty: %s.\n", my_str_size(&str),
               my_str_capacity(&str), "yes");
    }
    else{
        printf("Size of the string is %d, size of the buffer is %d, it is empty: %s.\n", my_str_size(&str),
               my_str_capacity(&str), "no");
    }
    my_str_clear(&str);
    printf("Clearing string...\nSize of the string is %d and size of the buffer is %d.\n", my_str_size(&str), my_str_capacity(&str));
    my_str_free(&str);       // destroy str

    printf("Creating a new string...\n");
    my_str_t str2;
    my_str_create(&str, 3);
    const char *line2 = "symbol";
    my_str_from_cstr(&str2, line, 6);
    printf("Created string: %s.\n", str2.data);
    printf("dd%c", (char) my_str_getc(&str2, 2));
    printf("Getting char at the position 3 is %c.\n", (char) my_str_getc(&str2, (size_t) 2));

    printf("First symbol: %c \n", my_str_getc(&str2, 0));
//    my_str_putc(&str2, 4, 'm');
//    printf("Change o to m: %s\n", str2.data);

//    const char* cstr = my_str_get_cstr(&str2);
//    printf("Getting equal c string: %s\n", cstr);
//
//    size_t index = my_str_find_c(&str2, 'm', 3);
//    printf("Find the index of 'm' starts from 3: %d\n", index);
//
//    my_str_t str3;
//    my_str_copy(&str2, &str3, 1);
//    printf("Create a copy of str: %s\n", str3.data);
//
//
//    printf("Starting tests \n");
//
//    my_str_t test_str;
//    const char test_line[] = "symbol";
//    my_str_from_cstr(&test_str, test_line, 6);
//    my_str_sort(&test_str);
//
//    read_write("../test.txt", "../sorted.txt");
//
    my_str_t test_str;
    const char test_line[] = "symbal";
    my_str_from_cstr(&test_str, test_line, 6);

    read_write(file_read, file_write);
    printf("%d", my_str_find_if(&test_str, &compare));
    return 0;
}

int static compare(char c) {
    return c == 'a';
}