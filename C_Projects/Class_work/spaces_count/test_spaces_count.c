#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include <limits.h>


#include "spaces_count.c"


typedef struct {
    char *input_file;
    unsigned int expected_spaces_amount;

} TestCase;



int main(){
    TestCase test_case[] = {
        //{.input_file = "empty_file.txt", .expected_spaces_amount = 0},
        {.input_file = "0spaces.txt", .expected_spaces_amount = 0},
        {.input_file = "5spaces.txt", .expected_spaces_amount = 5},
        {.input_file = "10spaces.txt", .expected_spaces_amount = 10},
    };
    size_t test_case_size = sizeof(test_case) / sizeof(test_case[0]);

    for(size_t i = 0; i <test_case_size; i++){
        FILE *file = fopen(test_case[i].input_file, "r");
        if(NULL == file){
            fprintf(stderr, "Error oppening file \"%s\"\n", test_case[i].input_file);
            perror("fopen");
            return EXIT_FAILURE;
        }
    
        unsigned int spaces_amount = UINT_MAX;
        int code = count_spaces(file, &spaces_amount);
        if(SUCCESS != code){
            printf("error code = %d\n", code);
            fclose(file);
            printf("Test %zu failid on <%s>\n", i, test_case[i].input_file);
            abort();
        }
        if(spaces_amount != test_case[i].expected_spaces_amount){
            fclose(file);
            printf("Test %zu failid on <%s>\n", i, test_case[i].input_file);
            abort();
        }

        fclose(file);
    }
    unsigned int spaces_num = UINT_MAX;
    int error_code = count_spaces(NULL, &spaces_num);
    if(NULL_POINTER != error_code){
        printf("Test with NULL failed.\n");
        printf("error code = %d\n", error_code);
        abort();
    }

    FILE *file = fopen(test_case[0].input_file, "w");
    error_code = count_spaces(file, NULL);
    if(NULL_POINTER != error_code){
        printf("Test with NULL failed.\n");
        printf("error code = %d\n", error_code);
        fclose(file);
        abort();
    }

    if(ERROR_READING_FILE != error_code){
        printf("File mod, test filed\n");
        fclose(file);
        abort();
    }
    fclose(file);
    printf("\nALL TESTS COMPLETE\n");
}