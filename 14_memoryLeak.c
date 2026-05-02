/*
 * Memory Leak in C
 * Description: Demonstrates a memory leak scenario in C and how to avoid it
 * Author: R. Azondekon
 * Date: 05/01/2026
 * Modified: 05/01/2026
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h> // Include for the time function used to seed the random number generator

 // A memory leak occurs when a program allocates memory on the heap but fails to free it, 
 // leading to a gradual increase in memory usage over time. This can eventually cause 
 // the program to run out of memory and crash. In C, memory leaks can occur when using 
 // dynamic memory allocation functions like malloc, calloc, or realloc without properly 
 // freeing the allocated memory.

 // Let's demonstrate a memory leak scenario in C by building a simple game

    // Simple Betting Game
    // "Jack Queen King" is a simple betting game where players bet on one of three cards: Jack, Queen, or King.
    // If the player's bet matches the `Queen`, they
    // win three times their bet; otherwise, they lose their bet. 
    // The game continues until the player is out of money or decides to quit.

int cash;

void playGame(unsigned int *bet){
    // char cards[] = {'J', 'Q', 'K'}; // Array of cards - this is a local variable that goes on the stack and will be destroyed once the function exits, so it does not cause a memory leak
    char *cards = (char*)malloc(sizeof(char) * 3); // Dynamically allocate memory for an array of 3 characters on the heap to store the cards
    // char *cards = (char*)malloc(sizeof(char) * 1000); // Use this to simulate a more severe memory leak scenario by allocating a large amount of memory on the heap without freeing it
    cards[0] = 'J'; // Assign the first card to the first element in the array
    cards[1] = 'Q'; // Assign the second card to the second element in the array
    cards[2] = 'K'; // Assign the third card to the third element in the array
    size_t playerBet;
    srand(time(NULL)); // Seed the random number generator with the current time
    for(size_t i = 0; i < 5; i++){
        size_t x = rand() % 3; // Generate a random number between 0 and 2 to select a card
        size_t y = rand() % 3; // Generate a random number between 0 and 2 to select a card
        char temp = cards[x]; // Get the card corresponding to the random number
        cards[x] = cards[y]; // Swap the selected card with another card
        cards[y] = temp; // Complete the swap
    }
    printf("Guess the position of the Queen (1, 2, or 3): ");
    scanf("%zu", &playerBet); // Read the player's bet (the position of the Queen) from the user
    if(cards[playerBet - 1] == 'Q'){
        cash += (*bet) * 3; // If the player wins, add three times their bet to their cash
        printf("Congratulations! You guessed correctly. Your new cash amount is: %d\n", cash);
    }
    else{
        cash -= *bet; // If the player loses, subtract their bet from their cash
        printf("Sorry, you guessed incorrectly. Your new cash amount is: %d\n", cash);
    }
    free(cards); // Comment this line out to simulate a memory leak scenario
}

int main(){
    printf("\nWelcome to the Jack Queen King Betting Game!\n");
    printf("\nHow deep is your pocket? Enter your initial cash amount: $");
    
    scanf("%d", &cash); // Read the initial cash amount from the user

    unsigned int bet;

    while(cash > 0){
        printf("\nEnter your bet amount (or 0 to quit): $");
        scanf("%u", &bet); // Read the player's bet amount from the user
        if(bet == 0){
            printf("Thanks for playing! Your final cash amount is: $%d\n", cash);
            exit(0); // Exit the game if the player chooses to quit by entering 0 as their bet
        }
        else if(bet > cash){
            printf("You cannot bet more than your current cash amount! Please enter a valid bet.\n");
            continue; // Prompt the player to enter a valid bet if they try to bet more than their current cash amount
        }
        else if(bet < 0){
            printf("Bet amount cannot be negative! Please enter a valid bet.\n");
            continue; // Prompt the player to enter a valid bet if they try to bet a negative amount
        } else{
            playGame(&bet); // Call the game function, passing the address of the bet variable to store the player's bet
        }

        // Check if the player is out of cash after each round of the game
        if(cash <= 0){
            printf("You are out of cash! Game over!\n");
            break; // Exit the loop if the player is out of cash
        }
    }
    return 0;
}