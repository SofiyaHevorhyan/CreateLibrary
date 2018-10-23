#include "lib_for_str.h"
#include <stdlib.h>

//! Обчислює розмір С-стрічки
//! приймає вказівник на перший символ (назва масиву)
size_t static len_c_str(const char* cstr) {
    const char* pstr = cstr;
    size_t len = 0;
    while (*pstr++ != '\0') {
        len++;
    }
    return len;
}

//! Створити стрічку із буфером вказаного розміру. Пам'ять виділяється динамічно.
//! Варто виділяти buf_size+1 для спрощення роботи my_str_get_cstr().
int my_str_create(my_str_t* str, size_t buf_size) {

    char* data1 = (char*)malloc(sizeof(char) * (buf_size+1));
    if (data1) {
        str->data = data1;
        printf("%p", (void*) str->data);
        str->capacity_m = buf_size;
        str->size_m = 0;

        return 0;
    }
    return 1;
}

//! Створити стрічку із буфером вказаного розміру із переданої С-стрічки.
//! Якщо розмір -- 0, виділяє блок, рівний розміру С-стрічки, якщо
//! менший за її розмір -- вважати помилкою.
//! Пам'ять виділяється динамічно.
//! 0 -- якщо все ОК, -1 -- недостатній розмір буфера, -2 -- не вдалося виділити пам'ять
int my_str_from_cstr(my_str_t* str, const char* cstr, size_t buf_size) {
    size_t len = len_c_str(cstr);
    if (buf_size == 0) {
        buf_size = len;
    }

    if (buf_size < len) {
        return -1;
    }

    if (my_str_create(str, buf_size) == 1) {
        return -2;
    }


    else {
        return my_str_create(str, buf_size);
    }

    // while there is place in buffer - save element to memory from malloc
    // if buffer < len(cstr) - -1
    // if wrong create - -2
    // everything ok - 0

    return 0;
}

//! Звільнє пам'ять, знищуючи стрічку:
void my_str_free(my_str_t* str){
    printf("my_str_free");
}
        my_str_t str;

//! Повертає розмір стрічки:
size_t my_str_size(const my_str_t* str) {
    return str->size_m;
}

//! Повертає розмір буфера:
size_t my_str_capacity(const my_str_t* str) {
    return str->capacity_m;
}

//! Повертає булеве значення, чи стрічка порожня:
int my_str_empty(const my_str_t* str) {
    if (str->size_m > 0) {
        return 0;
    }
    return 1;
}

//! Повертає символ у вказаній позиції, або -1, якщо вихід за межі стрічки
//! Тому, власне, int а не char
int my_str_getc(const my_str_t* str, size_t index) {
    if (index < str->size_m) {
        return (int) *(str->data + index);
    }
    return -1;
}

//! Записує символ у вказану позиції (заміняючи той, що там був),
//! Повертає 0, якщо позиція в межах стрічки,
//! Поветає -1, не змінюючи її вмісту, якщо ні.
int my_str_putc(my_str_t* str, size_t index, char c) {
    return 0;
}

//! Додає символ в кінець.
//! Повертає 0, якщо успішно, -1, якщо буфер закінчився.
int my_str_pushback(my_str_t* str, char c) {
    return 0;
}

//! Викидає символ з кінця.
//! Повертає його, якщо успішно, -1, якщо буфер закінчився.
int my_str_popback(my_str_t* str) {
    return 0;
}

//! Копіює стрічку. Якщо reserve == true,
//! то із тим же розміром буферу, що й вихідна,
//! інакше -- із буфером мінімального достатнього розміру.
//! Старий вміст стрічки перед тим звільняє, за потреби.
int my_str_copy(const my_str_t* from,  my_str_t* to, int reserve) {
    return 0;
}

//! Очищає стрічку -- робить її порожньою. Складність має бути О(1).
void my_str_clear(my_str_t* str) {
    printf("my_str_clear");
}

//! Вставити символ у стрічку в заданій позиції, змістивши решту символів праворуч.
//! Якщо це неможливо, повертає -1, інакше 0.
int my_str_insert_c(my_str_t* str, char c, size_t pos) {
    return 0;
}

//! Вставити стрічку в заданій позиції, змістивши решту символів праворуч.
//! Якщо це неможливо, повертає -1, інакше 0.
int my_str_insert(my_str_t* str, const my_str_t* from, size_t pos) {
    return 0;
}

//! Вставити C-стрічку в заданій позиції, змістивши решту символів праворуч.
//! Якщо це неможливо, повертає -1, інакше 0.
int my_str_insert_cstr(my_str_t* str, const char* from, size_t pos) {
    return 0;
}

//! Додати стрічку в кінець.
//! Якщо це неможливо, повертає -1, інакше 0.
int my_str_append(my_str_t* str, const my_str_t* from) {
    return 0;
}

//! Додати С-стрічку в кінець.
//! Якщо це неможливо, повертає -1, інакше 0.
int my_str_append_cstr(my_str_t* str, const char* from) {
    return 0;
}

//! Порівняти стрічки, повернути 0, якщо рівні (за вмістом!)
//! -1, якщо перша менша, 1 -- якщо друга.
//! Поведінка має бути такою ж, як в strcmp.
int my_str_cmp(my_str_t* str, const char* from) {
    return 0;
}

//! Скопіювати підстрічку, із beg включно, по end не включно ([beg, end)).
//! Якщо end виходить за межі str -- скопіювати скільки вдасться, не вважати
//! це помилкою. Якщо ж в ціловій стрічці замало місця, або beg більший
//! за розмір str -- це помилка. Повернути відповідний код завершення.
int my_str_substr(const my_str_t* str, char* to, size_t beg, size_t end) {
    return 0;
}


//! Повернути вказівник на С-стрічку, еквівалентну str.
//! Вважатимемо, що змінювати цю С-стрічку заборонено.
//! Якщо в буфері було зарезервовано на байт більше за макс. розмір, можна
//! просто додати нульовий символ в кінці та повернути вказівник data.
const char* my_str_get_cstr(my_str_t* str) {
    return str->data;
}

//! Знайти першу підстрічку в стрічці, повернути номер її
//! початку або -1u, якщо не знайдено. from -- місце, з якого починати шукати.
//! Якщо більше за розмір -- вважати, що не знайдено.
size_t my_str_find(const my_str_t* str, const my_str_t* tofind, size_t from) {
    return 0;
}

//! Знайти перший символ в стрічці, повернути його номер
//! або -1u, якщо не знайдено. from -- місце, з якого починати шукати.
//! Якщо більше за розмір -- вважати, що не знайдено.
size_t my_str_find_c(const my_str_t* str, char tofind, size_t from) {
    return 0;
}

//! Знайти символ в стрічці, для якого передана
//! функція повернула true, повернути його номер
//! або -1u, якщо не знайдено:
size_t my_str_find_if(const my_str_t* str, int (*predicat)(char)) {
    return 0;
}

//! Прочитати стрічку із файлу. Повернути, 0, якщо успішно, -1,
//! якщо сталися помилки. Кінець вводу -- не помилка, однак,
//! слід не давати читанню вийти за межі буфера!
//! Рекомендую скористатися fgets().
size_t my_str_read_file(my_str_t* str, FILE* file) {
    return 0;
}

//! Аналог my_str_read_file, із stdin
size_t my_str_read(my_str_t* str) {
    return 0;
}
//
//int my_str_read_word(my_str_t* str, FILE* file) {
//    if (file != NULL)
//    {
//        char* c_str[45];
//        int word_size = fscanf(file, "%s", c_str);
//        my_str_from_cstr(str, c_str, word_size);
//        return 0;
//    }
//
//    return -1;
//}
//
//int my_str_sort(my_str_t* str){
//
//    int i, key, j;
//    int size = my_str_size(str);
//    for (i = 1; i < size; i++)
//
//    {
//
//        key = my_str_getc(str, i);
//        j = i-1;
//
//        /* Move elements of arr[0..i-1], that are
//           greater than key, to one position ahead
//           of their current position */
//        while (j >= 0 && my_str_getc(str, j) > key)
//        {
//            j = j-1;
//        }
//        if (i != j++){
//
//        }
//        arr[j+1] = key;
//    }
//
//    return -1;
//}
//
int my_str_reorder(my_str_t* str,int key_take,int key_put){
    if (key_take == key_put){
        return 0;
    }
    if (key_take < key_put){
        int key_temp = key_take;
        key_take = key_put;
        key_put = key_temp;
    }

    char value = (char) my_str_getc(&str, key_take);
    char temp = (char) my_str_getc(&str, key_put);

    for (int i=key_put; i < key_take; i++){
        char* p1 = str.data + i;
        *p1 = temp;
//      дуже кончено, але я хз, як то норм поінтерами робити
        temp = (char) my_str_getc(&str, i+1);

    }
}