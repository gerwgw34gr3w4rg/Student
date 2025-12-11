




#include <stdio.h>


void greetings(void){
	printf("Hi!\n");
}


int sum(int term1, int term2){
	return term1 + term2;
}


int main(){
	greetings();
	int x = 20;
	int y = 30;
	int _sum = sum(x, y);
	printf("%d + %d = %d\n", x, y, _sum);  
}
