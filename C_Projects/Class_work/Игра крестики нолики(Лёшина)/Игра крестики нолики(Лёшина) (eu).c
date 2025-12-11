#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define FIELD_SIZE 9


void print_filed(const char field[FIELD_SIZE]);
char upper(char c);
void choose_side(char *player);
void player_tern(char field[FIELD_SIZE], char player);
bool check_win(const char field[FIELD_SIZE]);
void bot_tern(char field[FIELD_SIZE], char bor);



int main(){
    srand(time(NULL));
    char field[FIELD_SIZE] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    char bot = 'q';
    char player = 'q';
    choose_side(&player);
    if ('X' == player){
        bot = 'O';
    }
    else {
        bot = 'X';
    }
    int terns_counter = 0;
    while(terns_counter != FIELD_SIZE){
        print_filed((const char *)field);
        printf("\n  Select any free square by pressing the corresponding number\n");
        printf("\n  Me %c, bot %c\n\n  ", player, bot);
        player_tern(field, player);
        if(check_win(field)){
            print_filed((const char *)field);
            printf("  You win\n");
            return 0;
        }
        terns_counter++;
        if(terns_counter == 9){
            printf("\n  Draw\n");
            return 0;
        }
        bot_tern(field, bot);
        if(check_win(field)){
            print_filed((const char *)field);
            printf("  You lose\n");
            return 0;
        }
        terns_counter++;
    }
    

}

void print_filed(const char field[FIELD_SIZE]){
    system("clear");
    printf("\n");
    printf("  +-------+-------+-------+\n");
    printf("  |       |       |       |\n");
    printf("  |   %c   |   %c   |   %c   |\n", field[6], field[7], field[8]);
    printf("  |       |       |       |\n");
    printf("  +-------+-------+-------+\n");
    printf("  |       |       |       |\n");
    printf("  |   %c   |   %c   |   %c   |\n", field[3], field[4], field[5]);
    printf("  |       |       |       |\n");
    printf("  +-------+-------+-------+\n");
    printf("  |       |       |       |\n");
    printf("  |   %c   |   %c   |   %c   |\n", field[0], field[1], field[2]);
    printf("  |       |       |       |\n");
    printf("  +-------+-------+-------+\n");

    
}

char upper(char c){
    if ('a' <= c and c <= 'z'){
        return c + 'A' - 'a';
    }
    return c;
}


void choose_side(char *player){
    printf("Choose yuor side:\n");
    printf("press X, press O\n");
    
    if(scanf("%c", player) !=1){
        abort();
    }
    *player = upper(*player);
    if (not (*player == 'O' or *player == 'X')){
        abort();
    }
}


void player_tern(char field[FIELD_SIZE], char player){
    int choose;
    if (scanf("%d", &choose) != 1
            or choose < 1 or choose > FIELD_SIZE or field[choose - 1] == 'X' or field[choose - 1] == 'O'){
        abort();
    }
    field[choose - 1] = player;
}


bool check_win(const char field[FIELD_SIZE]){
    for(int i = 0; i < 3; i++){
        if (field[i * 3] == field[i * 3 + 1] and field[i * 3 + 1] == field[i * 3 + 2]){
            return true;
        }
        if (field[i] == field[i + 3] and field[i + 3] == field[i + 6]){
            return true;
        }
    }
    if (field[0] == field[4] and field[4] == field[8] or field[2] == field[4] and field[4] == field[6]){
        return true;
    }
    return false;
}


void bot_tern(char field[FIELD_SIZE], char bot){
    int rand_tern = rand() % FIELD_SIZE;
    while(field[rand_tern] == 'X' or field[rand_tern] == 'O'){
        rand_tern = rand() % FIELD_SIZE;
    }
    field[rand_tern] = bot;
}







