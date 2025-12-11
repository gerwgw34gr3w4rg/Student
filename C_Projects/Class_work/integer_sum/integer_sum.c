#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>


int64_t integer_sum(const char *filename, const int64_t MIN, const int64_t MAX){
/*
    Preconditions (Requires):
    filename points to a valid, null‐terminated string.
    The file named by filename exists and is readable.
    The file’s contents consist exclusively of
    (possibly signed) integers separated by newlines in the range [-10 billion, +10 billion].
    The total sum of all integers fits within a signed 64‐bit range (no overflow).
    Postconditions (Ensures):
    All integers in the file have been read exactly once in textual order.
    Returns the arithmetic sum of those integers.
    If filename is NULL or any I/O error or non‐integer token is encountered,
    the function prints an error message to stderr and call abort().
*/
    if(NULL == filename){
        fprintf(stderr, "NULL pointer ar %s(): %d line\n", __FUNCTION__, __LINE__ - 1);
        abort();
    }
    FILE *file = fopen(filename, "r");
    if(NULL == file){
        perror("fopen()");
        abort();
    }

    int64_t sum = 0;
    for(;;){
        int64_t num;
        int fscanf_return = fscanf(file, "%" SCNd64, &num);
        if(EOF == fscanf_return){
            break;
        }
        else if(fscanf_return != 1 or num < MIN or num > MAX){
            fprintf(stderr, "Invalid file content: file should only contain numbers in the range [%" PRId64 ", +%" PRId64 "].", MIN, MAX);
            abort();
        }

        int64_t tmp_sum = sum + num;
        if(sum < 0 and num < 0 and tmp_sum >= 0 or sum > 0 and num > 0 and tmp_sum < 0){
            fprintf(stderr, "Overflow with %" PRId64 " + %" PRId64 "= %" PRId64 "\n", sum, num, tmp_sum);
            abort();
        }
        sum += num;
    }

    fclose(file);
    return sum;
}


int main(int argc, char *argv[]){
    if(argc != 2){
        fprintf(stderr, "Call: %s <file_name.dat>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    const int64_t MIN = (size_t)-10 * (size_t)1000 * (size_t)1000 * (size_t)1000;
    const int64_t MAX = (size_t)+10 * (size_t)1000 * (size_t)1000 * (size_t)1000;
    int64_t sum = integer_sum(argv[1], MIN, MAX);
    printf("%" PRId64 "\n", sum);
    getchar();
}