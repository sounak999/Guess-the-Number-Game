#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int smallest(int arr[], int n)
{
    int i;

    // Initialize minimum element
    int min = 0;

    // Traverse array elements from second and
    // compare every element with current max
    for (i = 1; i < n; i++)
        if (arr[i] < arr[min])
            min = i;

    return min + 1;
}

int main()
{
    // int number, guess;
    // srand(time(0));
    // number = rand() % 100 + 1; // Generates a random number between 1 and 100
    // printf("The number is %d\n", number);
    // Keep running the loop until the number is guessed
    int players;
    printf("How many players want to play? (upto 100 allowed)\n");
    scanf("%d", &players);

    int arr[100];
    for (int i = 0; i < 100; i++)
    {
        arr[i] = 101;
    }
    
    int idx = 0;
    while (players--)
    {
        int number, guess, nguesses = 1;
        srand(time(0));
        number = rand() % 100 + 1; // Generates a random number between 1 and 100
        printf("\n*** Game Begins for Player-%d ***\n", idx + 1);
        do
        {
            printf("\nGuess the number between 1 to 100\n");
            scanf("%d", &guess);
            if (guess > number)
            {
                printf("Lower number please!\n");
            }
            else if (guess < number)
            {
                printf("Higher number please!\n");
            }
            else
            {
                printf("\n\nPlayer-%d guessed it in %d attempts!!\n\n", idx + 1, nguesses);
                arr[idx++] = nguesses;
            }
            nguesses++;
        } while (guess != number);
    }

    printf("\nCongratulations!! Player-%d won the game!!!\n\n", smallest(arr, 100));

    return 0;
}