#include "lib_for_str.h"
#include <stdlib.h>

//! Обчислює розмір С-стрічки
//! приймає вказівник на перший символ (назва масиву)
size_t static len_c_str(const char *cstr) {
    const char *pstr = cstr;
    size_t len = 0;
    while (*pstr++ != '\0') {
        len++;
    }
    return len;
}

//! Створити стрічку із буфером вказаного розміру. Пам'ять виділяється динамічно.
//! Варто виділяти buf_size+1 для спрощення роботи my_str_get_cstr().
int my_str_create(my_str_t *str, size_t buf_size) {

    char *data1 = (char *) malloc(sizeof(char) * (buf_size + 1));
    if (data1) {
        str->data = data1;
        *str->data = '\0';
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
int my_str_from_cstr(my_str_t *str, const char *cstr, size_t buf_size) {
    size_t len = len_c_str(cstr);
    if (buf_size == 0) {
        buf_size = len;
    }

    if (buf_size < len) {
        return -1;
    }
    my_str_free(str);
    int status = my_str_create(str, buf_size);
    if (!status) {
        const char *ps = cstr;
        char *pstr = str->data;

        while (*ps++ != '\0') {
            *pstr++ = *(ps - 1);
            str->size_m++;
        }
        *pstr = '\0';
        return 0;
    }
    return -2;
}


//! Звільнє пам'ять, знищуючи стрічку:
void my_str_free(my_str_t* str){
    free((void*)str->data);
    str->size_m = 0;
    str->capacity_m = 0;
}

//! Повертає розмір стрічки:
size_t my_str_size(const my_str_t *str) {
    return str->size_m;
}

//! Повертає розмір буфера:
size_t my_str_capacity(const my_str_t *str) {
    return str->capacity_m;
}

//! Повертає булеве значення, чи стрічка порожня:
int my_str_empty(const my_str_t *str) {
    return (str->size_m < 1);
}

//! Повертає символ у вказаній позиції, або -1, якщо вихід за межі стрічки
//! Тому, власне, int а не char
//! indexes are from 0 to size_m - 1 - others will be interpreted as error
int my_str_getc(const my_str_t *str, size_t index) {
    if (0 <= index < str->size_m) {
        return (int) *(str->data + index);
    }
    return -1;
}

//! Записує символ у вказану позиції (заміняючи той, що там був),
//! Повертає 0, якщо позиція в межах стрічки,
//! Поветає -1, не змінюючи її вмісту, якщо ні.
int my_str_putc(my_str_t *str, size_t index, char c) {
    if (0 <= index < str->size_m) {
        *(str->data + index) = c;
        return 0;
    }
    return -1;
}

//! Додає символ в кінець.
//! Повертає 0, якщо успішно, -1, якщо буфер закінчився.
int my_str_pushback(my_str_t *str, char c) {
    if (str->size_m < str->capacity_m){
        *(str->data + str->size_m) = c;
        *(str->data + str->size_m + 1) = '\0';
        str->size_m++;
        return 0;
    }
    return -1;
}

//! Викидає символ з кінця.
//! Повертає його, якщо успішно, -1, якщо буфер закінчився.
int my_str_popback(my_str_t *str) {
    // TODO: коли -1 повертає? якщо стрічка пуста і немає, що видаляти чи що?
    if (str->size_m > 0){
        *(str->data + str->size_m-1) = '\0';
        str->size_m--;
        return 0;
    }
    return -1;
}

//! Копіює стрічку. Якщо reserve == true,
//! то із тим же розміром буферу, що й вихідна,
//! інакше -- із буфером мінімального достатнього розміру.
//! Старий вміст стрічки перед тим звільняє, за потреби.
int my_str_copy(const my_str_t* from,  my_str_t* to, int reserve) {
    // TODO: за потреби звільнити вміст стрічки??
    // todo: return another statement
    if (reserve || (from->size_m > to->capacity_m)) {
        my_str_free(to);

        int status = my_str_create(to, from->capacity_m);
        if (status) {
            return -1;
        }

    } else {
        if (from->size_m > to->capacity_m) {
            my_str_free(to);
            my_str_create(to, from->size_m);
        }
        //copy

    }
    const char *pfrom = from->data;
    char *pto = to->data;

    while (*pfrom++ != '\0') {
        *pto++ = *(pfrom - 1);
        to->size_m++;
    }
    *pto = '\0';
    return 0;
}

//! Очищає стрічку -- робить її порожньою. Складність має бути О(1).
void my_str_clear(my_str_t* str) {
    *str->data = '\0';
    str->size_m = 0;
}

//! Вставити символ у стрічку в заданій позиції, змістивши решту символів праворуч.
//! Якщо це неможливо, повертає -1, інакше 0.
int my_str_insert_c(my_str_t *str, char c, size_t pos) {
    return 0;
}

//! Вставити стрічку в заданій позиції, змістивши решту символів праворуч.
//! Якщо це неможливо, повертає -1, інакше 0.
int my_str_insert(my_str_t *str, const my_str_t *from, size_t pos) {
    return 0;
}

//! Вставити C-стрічку в заданій позиції, змістивши решту символів праворуч.
//! Якщо це неможливо, повертає -1, інакше 0.
int my_str_insert_cstr(my_str_t *str, const char *from, size_t pos) {
    return 0;
}

//! Додати стрічку в кінець.
//! Якщо це неможливо, повертає -1, інакше 0.
int my_str_append(my_str_t *str, const my_str_t *from) {
    if (str->size_m + from->size_m < str->capacity_m){
        char* pstr = str->data + str->size_m;
        const char* pfrom = from->data;

        while (*pfrom++ != '\0'){
            *pstr++ = *(pfrom-1);
            str->size_m++;
        }
        *pstr = '\0';
        return 0;
    }
    return -1;
}

//! Додати С-стрічку в кінець.
//! Якщо це неможливо, повертає -1, інакше 0.
int my_str_append_cstr(my_str_t *str, const char *from) {
    if (str->size_m + len_c_str(from) < str->capacity_m){
        char* pstr = str->data +str->size_m;
        const char* pfrom = from;

        while (*pfrom++ != '\0'){
            *pstr++ = *(pfrom-1);
        }
        str->size_m += len_c_str(from);
        *pstr = '\0';
        return 0;
    }
    return -1;
}

//! Порівняти стрічки, повернути 0, якщо рівні (за вмістом!)
//! -1, якщо перша менша, 1 -- якщо друга.
//! Поведінка має бути такою ж, як в strcmp.
int my_str_cmp(my_str_t *str, const char *from) {
    return 0;
}

//! Скопіювати підстрічку, із beg включно, по end не включно ([beg, end)).
//! Якщо end виходить за межі str -- скопіювати скільки вдасться, не вважати
//! це помилкою. Якщо ж в ціловій стрічці замало місця, або beg більший
//! за розмір str -- це помилка. Повернути відповідний код завершення.
int my_str_substr(const my_str_t *str, char *to, size_t beg, size_t end) {
    return 0;
}


//! Повернути вказівник на С-стрічку, еквівалентну str.
//! Вважатимемо, що змінювати цю С-стрічку заборонено.
//! Якщо в буфері було зарезервовано на байт більше за макс. розмір, можна
//! просто додати нульовий символ в кінці та повернути вказівник data.
const char* my_str_get_cstr(my_str_t* str) {
    //'\0' вже стоїть в кінці стрічки str->data
    const char* cstr = str->data;
    return cstr;
}

//! Знайти першу підстрічку в стрічці, повернути номер її
//! початку або -1u, якщо не знайдено. from -- місце, з якого починати шукати.
//! Якщо більше за розмір -- вважати, що не знайдено.
size_t my_str_find(const my_str_t *str, const my_str_t *tofind, size_t from) {

    char* pstr = str->data + from;
    char* pfind = tofind->data;
    char* pfirst_str;

    while (*pstr != '\0') {
        if (*pstr != *pfind) {
            pstr = my_str_find_c(&str, )
            pfirst_str = pstr;
        }
    }


    while (*pstr != '\0') {
    }

    return 0;
}

//! Знайти перший символ в стрічці, повернути його номер
//! або -1u, якщо не знайдено. from -- місце, з якого починати шукати.
//! Якщо більше за розмір -- вважати, що не знайдено.
size_t my_str_find_c(const my_str_t* str, char tofind, size_t from) {
    if (0 <= from < str->size_m) {
        char* pc = str->data + from;
        while (*pc != '\0') {
            if (*pc++ == tofind) {
                return (size_t)(pc-str->data-1);
            }
        }
    }
    return (size_t)(-1u);
}

//! Знайти символ в стрічці, для якого передана
//! функція повернула true, повернути його номер
//! або -1u, якщо не знайдено:
size_t my_str_find_if(const my_str_t *str, int (*predicat)(char)) {
    char *pointer = str->data;
    while (*pointer != '\0') {
        if (predicat(*pointer) == 1) {
            return (size_t) (pointer - str->data);
        }
        pointer += 1;
    }
    return (size_t) -1;
}

//! Прочитати стрічку із файлу. Повернути, 0, якщо успішно, -1,
//! якщо сталися помилки. Кінець вводу -- не помилка, однак,
//! слід не давати читанню вийти за межі буфера!
//! Рекомендую скористатися fgets().
size_t my_str_read_file(my_str_t *str, FILE *file) {
    // fgets
    return 0;
}

//! Аналог my_str_read_file, із stdin
size_t my_str_read(my_str_t *str) {
    // gets
    return 0;
}

//! зчитує 1 слово з файла у стрічку (до 1023 символів)
//! якщо переданого файлу не існує або
//! прочитане слово пусте, повертає -1
//! при успішній операції повертає 0
int my_str_read_word(my_str_t *str, FILE *file) {
    if (file != NULL) {
        char c_str[1024];
        int word_size = fscanf(file, "%1023s ", c_str);
        if (word_size < 1) {
            return -1;
        }
        my_str_from_cstr(str, c_str, 0);
        return 0;
    }

    return -1;
}

//! сортує стрічку по символах
void my_str_sort(my_str_t* str){

    int key;
    size_t i, j;
    size_t size = my_str_size(str);
    for (i = 1; i < size; i++) {

        key = my_str_getc(str, i);
        j = i-1;

        while (j >= 0 && my_str_getc(str, j) > key) {
            j = j-1;
        }
        if (i != j++){
            my_str_reorder(str, i, j);
        }
    }
}

//! тут все складно
//! бере символ з kye_take, вставляє на key_put, і зміщує
//! всі значення з key_put по (ket_take - 1) на 1 комірку
//! впрово. якщо key_put > key_take повертає -1.
//! при успішності операції повертає 0.
int my_str_reorder(my_str_t *str, size_t key_take, size_t key_put) {
    if (key_take == key_put) {
        return 0;
    }
    if ((key_take < key_put) || (key_put < 0) || (key_take >= str->size_m)){
        return -1;
    }

    char value = *(str->data + key_take);
    char temp = *(str->data + key_put);

    char *p1 = str->data + key_put;
    *p1 = value;

    for (size_t i = key_put+1; i <= key_take; i++) {

        p1 = str->data + i;
        value = *p1;
        *p1 = temp;
       temp = value;
    }
    return 0;
}