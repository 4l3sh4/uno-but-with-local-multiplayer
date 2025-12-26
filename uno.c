#include <stdio.h>
#include <string.h> // for string functions
#include <stdbool.h> // for boolean functions

#include <pthread.h> // for multithreading (i haven't implemented this yet - alesha)
#include <unistd.h> // for sleep()

#include <stdlib.h> // for randomized functions
#include <time.h> // for the time() function

// play state (running or ended)
bool play_state = true;

// initializing the 'dice' array for all the players
int p_dice[6] = { 0, 0, 0, 0, 0, 0 };

// which dice needs to be rerolled
int p_reroll[6] = { 0, 0, 0, 0, 0, 0 };

// amount of times a player can reroll
int add_reroll = 2;

// random number
int rand_num;

// yes or no
char yes_no;

// amount of dice to reroll
int reroll_amount;

int main() {
    srand(time(NULL));

    printf("Rolling dice...\n");

    for (int i = 0; i <= 5; i++) {
        rand_num = rand() % 6 + 1;
        p_dice[i] = rand_num;
    }

    for (int i = 0; i <= 5; i++) {
        printf("[%d] ",p_dice[i]);
    }

    while (add_reroll > 0){
        printf("\n\nWould you like to re-roll any of the dices? (Y/N)\n");
        scanf(" %c", &yes_no);

        if (yes_no == 'Y'){
            add_reroll -= 1;
            printf("\nHow many dice would you like to reroll? (0-6)\n");
            scanf("%d", &reroll_amount);
            if(reroll_amount > 0 && reroll_amount <= 6){
                if(reroll_amount > 0 && reroll_amount <= 5){
                    printf("\nPlease input which dice you would like to reroll, from left to right, with spaces.\n");
                }
                switch (reroll_amount) {
                    case 1:
                        scanf("%d", &p_reroll[0]);
                        break;
                    case 2:
                        scanf("%d %d", &p_reroll[0], &p_reroll[1]);
                        break;
                    case 3:
                        scanf("%d %d %d", &p_reroll[0], &p_reroll[1], &p_reroll[2]);
                        break;
                    case 4:
                        scanf("%d %d %d %d", &p_reroll[0], &p_reroll[1], &p_reroll[2], &p_reroll[3]);
                        break;
                    case 5:
                        scanf("%d %d %d %d %d", &p_reroll[0], &p_reroll[1], &p_reroll[2], &p_reroll[3], &p_reroll[4]);
                        break;
                    case 6:
                        for (int i = 0; i <= 5; i++) {
                            p_reroll[i] = i + 1;
                        }
                        break;
                    default:
                        break;
                }

                for (int i = 0; i <= 5; i++) {
                    if(p_reroll[i] != 0){
                        rand_num = rand() % 6 + 1;
                        p_dice[p_reroll[i] - 1] = rand_num;
                        p_reroll[i] = 0;
                    }
                }

                printf("\nRerolling dice...\n");
                for (int i = 0; i <= 5; i++) {
                    printf("[%d] ",p_dice[i]);
                }
            }
        }
    }

    return 0;
}