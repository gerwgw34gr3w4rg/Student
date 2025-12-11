#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    const int MIN = 0, MAX = 100;
    const int SEQUENCE_SIZE = 10;
    printf("Enter %d numbers from %d to %d\n", SEQUENCE_SIZE, MIN, MAX);
    int sum = 0;
    int square_sum = 0;
    for (int i = 0; i < SEQUENCE_SIZE; i++){
    	int x;
        if (scanf("%d", &x) != 1 or x < MIN or x > MAX){
            printf("It was necessary to enter number numbers from %d to %d\n", MIN, MAX);
            abort();
        }
        sum += x;
        square_sum += x * x;
    }
    double average = (float)sum / SEQUENCE_SIZE;
    double square_average = (float)square_sum / SEQUENCE_SIZE;
    double standard_deviaton = sqrt(square_average - average * average);
    printf("standard_deviaton=%lf\n", standard_deviaton);
}
