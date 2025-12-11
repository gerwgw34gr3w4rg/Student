/*
The program takes a file name as a command line argument and
counts the number of spaces in it.
*/
#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include <stdbool.h>


enum RETURN_CODES{
    SUCCESS = 0, NULL_POINTER = 1, NOT_ENOUGH_MEMORY = 2, ERROR_READING_FILE = 3
};


int count_spaces(FILE *file, unsigned int *spaces_count);

#if 0
int main(int argc, char *argv[]){
    if(2 != argc){
        printf("Call %s < filename>\n", argv[0]);
        return EXIT_FAILURE;
    }
    FILE *file = fopen(argv[1], "r");
    if(NULL == file){
        fprintf(stderr, "Error oppening file \"%s\"\n", argv[1]);
        perror("fopen");
        return EXIT_FAILURE;
    }

    unsigned int *spaces_amout;
    count_spaces(file, spaces_amout);

    
    fclose(file);
    return EXIT_SUCCESS;
}
#endif

int count_spaces(FILE *file, unsigned int *spaces_count){
    /*
        Counts the number of whitespace characters in the given file.
    
        Arguments:
            file: the file MUST to be opened for reading.
                The number of whitespace characters will be counted in it.

            space_count: pointer to a variable to which the result will be written.
                    On error, 0 will be written.
    
        Return value:
            0 - SUCCESS
            or error code:
                1 - NULL_POINTER
                2 - NOT_ENOUGH_MEMORY
                3 - ERROR_READING_FILE
    */

    if(NULL == file or NULL == spaces_count){
        return NULL_POINTER;
    }
    const size_t BUFFER_SIZE = (size_t)100 * 1000;
    char *buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    if(NULL == buffer){
        return NOT_ENOUGH_MEMORY;
    }
    *spaces_count = 0u;
    while(true){
        char *fgets_return = fgets(buffer, (int)BUFFER_SIZE, file);
        if(NULL == fgets_return){
            if(feof(file)){
                break;
            }
            perror("fgets");
            free(buffer);
            return ERROR_READING_FILE;
        }
        for(size_t i = 0; buffer[i] != '\0'; i++){
            if(' ' == buffer[i]){
                (*spaces_count)++;
            }
        }
    }
    free(buffer);
    return SUCCESS;
}












