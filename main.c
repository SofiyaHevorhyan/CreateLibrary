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
    } else {
        printf("Size of the string is %d, size of the buffer is %d, it is empty: %s.\n", my_str_size(&str),
               my_str_capacity(&str), "no");
    }

    my_str_clear(&str);
    printf("Clearing string...\nSize of the string is %d and size of the buffer is %d.\n", my_str_size(&str),
           my_str_capacity(&str));

    my_str_free(&str);

    printf("Creating a new string...\n");
    my_str_t str2;
    my_str_create(&str2, 3);
    const char *line2 = "symbol";
    my_str_from_cstr(&str2, line, 6);
    printf("Created string: %s.\n", str2.data);

    printf("Getting char at the position 3 is %c.\n", (char) my_str_getc(&str2, (size_t) 2));
    printf("First symbol: %c \n", my_str_getc(&str2, 0));

    printf("Putting char 's' at the position 3.\n");
    my_str_putc(&str2, 2, 's');
    printf("Modified string: %s.\n", str2.data);

    printf("Popping last element from string...\n");
    my_str_popback(&str2);
    printf("Modified string: %s.\n", str2.data);

    printf("Pushing 'e' to the end of the string...\n");
    my_str_pushback(&str2, 'e');
    printf("Modified string: %s.\n", str2.data);

    my_str_t str3;
    my_str_create(&str3, 3);
    const char *str3_c = "pokba";
    my_str_from_cstr(&str3, str3_c, 6);

    printf("Copying string with saving buffer size of the copied string...\n");
    printf("String to which str2 will be copied: %s\n", str3.data);
    my_str_copy(&str2, &str3, 1);
    printf("String to which str2 was copied: %s\n", str3.data);

    printf("Appending string to the end of another string...\n");
    my_str_t str4;
    my_str_create(&str4, 3);
    const char *str4_c = "bagirls";
    my_str_from_cstr(&str4, str4_c, 20);

    my_str_append(&str4, &str3);
    printf("String to which str3 was appended: %s\n", str4.data);

    printf("Appending C string to the end of another string...\n");
    const char *str5_c = "ba";
    my_str_append_cstr(&str4, str5_c);
    printf("String to which str3 was appended: %s\n", str4.data);
    const char *str6_c = my_str_get_cstr(&str4);
    printf("Getting equal c string: %s\n", str6_c);

    printf("Number of element 's' in string %s is %d\n", str4.data, my_str_find_c(&str4, 's', (size_t) 1));


//    size_t index = my_str_find_c(&str2, 'm', 3);
//    printf("Find the index of 'm' starts from 3: %d\n", index);
//
//    my_str_t str3;
//    my_str_copy(&str2, &str3, 1);
//    printf("Create a copy of str: %s\n", str3.data);

    my_str_t str6;
    my_str_create(&str6, 10);
    const char *test_line = "bagirls";
    my_str_from_cstr(&str6, test_line, 7);

    printf("Number of element 'a' in string %s: %d", str6.data, my_str_find_if(&str6, &compare));

    read_write(file_read, file_write);
    return 0;
}

int static compare(char c) {
    return c == 'a';
}