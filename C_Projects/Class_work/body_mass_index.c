




#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>


#define UNDERWEIGHT_BORDER 18.5f
#define NORMAL_WEIGHT_BORDER 25.0f
#define OVERWEIGHT_BORDER 30.0f


int main(){
	const int LOW_LIMIT = 0;
	const int HIGHT_LIMIT = 1000;
	
    int height, weight;
    printf("Введи рост (в см), через пробел вес (в кг)\n");
    if (scanf("%d %d", &height, &weight) != 2){
    	printf("Неверный ввод! Вы не ввели число!\n");
    	abort();
    }
    if (height <= LOW_LIMIT or height > HIGHT_LIMIT
    		or weight <= LOW_LIMIT or weight > HIGHT_LIMIT){
        if (height == 0 or weight == 0){
            printf("Этот человек мёртв\n");
        }
        else{
            printf("Ты выходишь за рамки задания\n");
        }
    	return 0;
    }
    
    float float_height = (float)height / 100;  // convert from Centimeters to Meters
    float body_mass_index = weight / (float_height * float_height);
    
    if (body_mass_index < UNDERWEIGHT_BORDER){
        printf("Underweight\n");
    }
    else if (body_mass_index < NORMAL_WEIGHT_BORDER){
        printf("Normal weight\n");
    }
    else if (body_mass_index < OVERWEIGHT_BORDER){
        printf("Overweight\n");
    }
    else {
        printf("Obesty\n");
    }
    return 0;
}
