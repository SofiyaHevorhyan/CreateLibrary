typedef struct
{
    int capacity_m; // Розмір блока
    int size_m;	   // Фактичний розмір стрічки
    char*  data;	   // Вказівник на блок пам'яті
} my_str_t;

int my_str_create(my_str_t* str, int buf_size);

int my_str_from_cstr(my_str_t* str, const char* cstr, int buf_size);

void my_str_free(my_str_t* str);

int my_str_size(const my_str_t* str);

int my_str_capacity(const my_str_t* str);

int my_str_empty(const my_str_t* str);

int my_str_getc(const my_str_t* str, int index);

int my_str_putc(my_str_t* str, int index, char c);

int my_str_pushback(my_str_t* str, char c);

int my_str_popback(my_str_t* str);

int my_str_copy(const my_str_t* from,  my_str_t* to, int reserve);

void my_str_clear(my_str_t* str);

int my_str_insert_c(my_str_t* str, char c, int pos);

int my_str_insert(my_str_t* str, const my_str_t* from, int pos);

int my_str_insert_cstr(my_str_t* str, const char* from, int pos);

int my_str_append(my_str_t* str, const my_str_t* from);

int my_str_append_cstr(my_str_t* str, const char* from);

int my_str_cmp(my_str_t* str, const char* from);

int my_str_substr(const my_str_t* str, char* to, int beg, int end);

const char* my_str_get_cstr(my_str_t* str);

int my_str_find(const my_str_t* str, const my_str_t* tofind, int from);

int my_str_find_c(const my_str_t* str, char tofind, int from);

int my_str_find_if(const my_str_t* str, int (*predicat)(char));

//int my_str_read_file(my_str_t* str, FILE* file);

//int my_str_read(my_str_t* str);