#include "library/lib_for_str.h"
int read_write(const char* file_read,const char* file_write);


int main() {
    printf("Hello, World!\n");
    my_str_t str;
    my_str_create(&str, 3);
    my_str_clear(&str);
    my_str_free(&str);

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
    const char* arr = my_str_get_cstr(&str2);
    printf("\n%c ", *arr);
    size_t size = str2.size_m;
    const char arr1[size];
    //arr1 = arr;
    //printf("%c ", *arr1);

    printf("\n starting test \n");
    printf("\n prev\n");
    my_str_t test_str;
    const char test_line[] = "symbol";
    my_str_from_cstr(&test_str, test_line, 6);
    my_str_sort(&test_str);
    //printf("%s", test_str);
    read_write("test.txt", "sorted.txt");
    printf("read_write function was called");
    return 0;
}