#include "library/lib_for_str.h"
#include "file_read.h"

int main() {
    printf("Program starts!\n");
    my_str_t str;
    my_str_create(&str, 3);  // initialize with buffer 3
    my_str_clear(&str);      // clear str
    my_str_free(&str);       // destroy str

    my_str_t str2;
    const char line[] = "symbol";
    // initialize str from line
    my_str_from_cstr(&str2, line, 6);
    printf("Creating str: %s\n", str2.data);

    printf("Size: %d, buffer: %d, empty?: %d\n", my_str_size(&str2), my_str_capacity(&str2),
            my_str_empty(&str2));

    printf("First symbol: %c \n", my_str_getc(&str2, 0));
    my_str_putc(&str2, 4, 'm');
    printf("Change o to m: %s\n", str2.data);

    const char* cstr = my_str_get_cstr(&str2);
    printf("Getting equal c string: %s\n", cstr);

    size_t index = my_str_find_c(&str2, 'm', 3);
    printf("Find the index of 'm' starts from 3: %d\n", index);

    my_str_t str3;
    my_str_copy(&str2, &str3, 1);
    printf("Create a copy of str: %s\n", str3.data);


    printf("Starting tests \n");

    my_str_t test_str;
    const char test_line[] = "symbol";
    my_str_from_cstr(&test_str, test_line, 6);
    my_str_sort(&test_str);
//    printf("%s", test_str);
    read_write("test.txt", "sorted.txt");
    return 0;
}