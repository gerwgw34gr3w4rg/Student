#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


size_t str_size(const char *str);


typedef struct person {
    char *name;
    unsigned age;
} Person;



unsigned Person_get_age(struct person *person) {
    assert(NULL != person);
    return person -> age;
}


void Person_set_age(struct person *person, unsigned new_age) {
    assert(NULL != person);
    person -> age = new_age;
}


char *Person_get_name(const struct person *person){
    assert(person != NULL);
    assert((*person).name != NULL);
    return (*person).name;
}


void Person_set_name(struct person *person, const char *new_name) {
    assert(person != NULL);
    assert(new_name != NULL);
    free(person -> name);
    person -> name = (char *)malloc(sizeof(char) * (str_size(new_name) + 1));
    assert(person -> name != NULL);
    size_t i = 0;
    while (new_name[i] != '\0') {
        person -> name[i] = new_name[i];
        i++;
    }
    person -> name[i] = '\0';
}


void Person_print(struct person *person) {
    assert(NULL != person);
    printf("%s %u\n", person -> name, person -> age);
}


struct person *Person_init(const char *name, unsigned age) {
    struct person *person = (struct person *)malloc(sizeof(struct person));
    assert(person != NULL);

    person -> name = NULL;
    
    Person_set_age(person, age);
    Person_set_name(person, name);

    return person;
}


void Person_delete(struct person *person){
    assert(person != NULL);
    free((*person).name);
    (*person).name = NULL;
    free(person);
}


size_t str_size(const char *str){
    /**
    * @brief Calculates the length of a null-terminated C string.
    *
    * This function returns the number of characters in the input string,
    * excluding the null terminator ('\0').
    *
    * If the input pointer is NULL, the function prints an error message
    * to stderr indicating the file and line where the null pointer was detected,
    * and then terminates the program using abort().
    *
    * @param str A pointer to a null-terminated C string.
    *
    * @return The number of characters in the string (not including the null terminator).
    *
    * @note This function is designed for ASCII or UTF-8 strings where characters are
    *       represented by single bytes. It does not support wide or multibyte characters.
    *
    * @warning Passing a NULL pointer will cause the program to terminate.
    *
    * @examples
    * str_size("Hello")         -> 5
    * str_size("")              -> 0
    * str_size("OpenAI GPT-4")  -> 12
    * str_size(NULL)            -> Program aborts with an error message
    */
    if (NULL == str){
        fprintf(stderr, "Null pointer at %s: %d\n", __FILE__, __LINE__ - 1);
        abort();
    }
    size_t size = 0;
    for (size_t i = 0; str[i] != '\0'; i++){
        size++;
    }
    return size;
}