#include "library/lib_for_str.h"

int main() {
    printf("Hello, World!\n");
    my_str_t str;
    my_str_create(&str, 3);

    my_str_t str2;
    const char line[] = "symbol";
    printf("%d\n", my_str_from_cstr(&str2, line, 6));

    char* ps = str2.data;
    while (*ps++ != '\0') {
        printf("%c ", *(ps-1));
    }
    printf("\nsize: %d, buffer: %d, empty?: %d\n",
            my_str_size(&str2), my_str_capacity(&str2),
            my_str_empty(&str2));

    printf("first symbol: %c \n", my_str_getc(&str2, 0));
    printf("change o to a: ");
    ps = str2.data;
    my_str_putc(&str2, 4, 'a');
    while (*ps++ != '\0') {
        printf("%c ", *(ps-1));
    }

    printf("\n starting test \n");
    printf("\n prev\n");
    my_str_t test_str;
    const char test_line[] = "symbol";
    my_str_from_cstr(&test_str, test_line, 6);
    my_str_sort(&test_str);
//    printf("%s", test_str);
    char* p_test = test_str.data;
    while (*p_test++ != '\0') {
        printf("%c ", *(p_test-1));
    }

    return 0;
}