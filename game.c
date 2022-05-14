#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <strings.h>

int main()
{
    int n;

    int guess, attempts[10], p, a;
    char name[10][50];
    system("clear");
    printf("here, the game is, you need to guess the number between 1 to 100. the number between 1 to 100 is autometically generated but you dont't know that number and you have to guess which number is that.\n\nso, you will have the hint. when you enter the number, and if you've guessed the lower number than actual one, it'll say to enter a higher number and vice versa.\n\nnow, here trick is you need to guess the number in minimum attempts. \n\n\nthis game can be played between any no. of players. you can play with your friends and compared to each other by the number of attempts each one had took and one with minimum attempts wins the game.\n");

    printf("\nso shall we begin?\n\nEnter no. of Players: ");
    scanf("%d", &p);
    // system("clear");
    for (a = 0; a < p; a++)
    {
        //  printf("Enter name of Player: ");
        // scanf("%s",&name);
        system("clear");
        printf("******Player %d is Playing********\n\n", a + 1);

        srand(time(0));
        n = rand() % 100 + 1;
        //printf("%d", n);

        do
        {
            printf("Enter your number between 1 to 100: ");
            scanf("%d", &guess);
            if (!(guess <= 100 && guess >= 1))
            {
                printf("\nInvalid input. please enter the right number\n\n");
                continue;
            }
            else if (guess == n)
            {
                printf("\n\n******congratulations, you've guessed the number in %d attempts******\n", attempts[a]+1);
                printf("\nExcuse me, What is your name please? : ");
                scanf("%s", name[a]);
            }
            else if (guess < n)
            {
                printf("*********your guess is lower**********\n");
            }
            else if (guess > n)
            {
                printf("*********your guess is higher**********\n");
            }
            attempts[a]++;
        } while (!(guess == n));
        // system("clear");
    }
    int chase = attempts[0], count = 0;
    for (a = 1; a < p; a++)
    {
        if (attempts[a] < chase)
        {
            count = a;
            chase = attempts[a];
        }
    }
    printf("\n\n\n*******Winner is %s**********\n\n", name[count]);
    return 0;
}