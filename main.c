#include <stdio.h> //Standard Input-Output Library Included
#include <stdlib.h> //Standard Library Included
#include <string.h> // String Library Included
#include <ctype.h>   // Includes Functions To Handle Character Types

#define MAX_WORD_LENGTH 100 // A Constant = 100 is set for maximum length of the guessing word
#define MAX_ATTEMPTS_LEVEL1 6 // Maximum Attempts = 6 is set for Level 1
#define MAX_ATTEMPTS_LEVEL2 4   // Maximum Attempts = 4 is set for Level 2
#define MAX_ATTEMPTS_LEVEL3 2  // Maximum Attempts = 2 is set for Level 3

void clearScreen() {
    system("cls"); // Function to clear the screen
}



//--------------------------  MD Sayem  --------------------------------//

 //    Displaying underscores for Unrevealed letters and actual letters for revealed ones.

void displayWord(char *word, int *revealed) {
    for (int i = 0; i < strlen(word); i++) {     // Loops through each character of the word
        if (revealed[i]) {                       // Checks if the character at position (i) has been guessed correctly
            printf("%c ", word[i]);              // Print the letter if it has been guessed
        } else {
            printf("_ ");                        // Print an underscore if the letter has not been guessed
        }
    }
    printf("\n");
}  //-----------------------------------------------------------------//





//----------------------- ROnjon Sarker----------------------------//

      // this function is to check if all letters of the word has been guessed or not
int isWordRevealed(char *word, int *revealed)

{

    for (int i = 0; i < strlen(word); i++)  // looping to each character of the word
        {
        if (!revealed[i]) {                // Checking if any word is not revealed
            return 0;                      // Return 0 if its unrevealed
        }
    }
    return 1;                              // return 1 for revealed character

}//---------------------------------------------------------------//



//-------------------------MD Sayem------------------------ //

// This Function Is To Show The Hangman ASCII Art According To The Attempts Left

void displayHangman(int attemptsLeft) {
    switch (attemptsLeft) {                //Checks The Value Of Attempt Left and Execute The Case Based On Attempt Left
        case 6:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 5:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 4:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf("  |   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 3:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 2:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 1:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf(" /    |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 0:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf(" / \\  |\n");
            printf("      |\n");
            printf("=========\n");
            break;
    }
}


//--------------Ronjon Sarker---------------------//

//function for playing a level of the game
int playLevel(char *word, int maxAttempts)
{
    int wordLength = strlen(word);  // calculating the length of the word

    int revealed[wordLength];                   //array to keep track on revealed letter, initialized to 0
    memset(revealed, 0, sizeof(revealed));

    int attemptsLeft = maxAttempts;  // initialize the number of attempts left
    char guessedLetters[26] = {0};    // array to keep track of guessed letters, initialized to 0
    int guessedLettersCount = 0;        // Counting  the number of guessed letters
    int consecutiveWrongGuesses = 0;     // counting consecutive wrong guesses
    clearScreen();                      // Clear the screen for the game

    while (attemptsLeft > 0 && !isWordRevealed(word, revealed)) // continue while there are attempts left and the word is not fully revealed
        {
        displayHangman(attemptsLeft);  // display the current state of the hangman
        displayWord(word, revealed);   // display the current state of the word with revealed letters

        printf("Attempts left: %d\n", attemptsLeft); // display the number of attempts left
        printf("Guessed letters: ");              // display the letters that have been guessed so far
        for (int i = 0; i < guessedLettersCount; i++) // looping to check for more guessed letters
            {
            printf("%c ", guessedLetters[i]);       //print the guessed letters
        }
        printf("\n");
//--------------------------------------------------------------------------------------------------------

//-------------------------------MD Sayem---------------------------------------------------------------
        char guess;
        printf("Enter your guess: ");        //Ask player For a Guess
        scanf(" %c", &guess);                //Taking Input and storing it in "guess"
        guess = tolower(guess);              // Converting Uppercase Letters to Lower Case

        int alreadyGuessed = 0;              // Declared To Check multiple same input for guess
        for (int i = 0; i < guessedLettersCount; i++) // Looping Through guessedLetterCount incrementing from 0
            {
            if (guessedLetters[i] == guess) // Statement To Check If The current guess has been already guessed
            {

                alreadyGuessed = 1;          // If Already Guessed Return 1
                break;
            }
        }


        // If The Letter Has Been Already Guessed, Notify The User
        if (alreadyGuessed)
            {
            printf("You have already guessed that letter. Try again.\n");
            continue;
        }

        guessedLetters[guessedLettersCount++] = guess; //Incrementing Guessed Letter to the list

        int correctGuess = 0;   //Declared for indicating correct guess letter.
        for (int i = 0; i < wordLength; i++) // Looping through wordLength
            {
            if (tolower(word[i]) == guess) // Statement to check if current guess is on the word
            {
                revealed[i] = 1;  // Reveal the array positions of the word
                correctGuess = 1; // Correct guess true
            }
        }

        if (!correctGuess) {    // Incorrect guess
            attemptsLeft--;       //Decrement attempt left
            consecutiveWrongGuesses++; // Increment  consecutiveWrongGuesses
        } else {
            consecutiveWrongGuesses = 0; // Else Reset consecutiveWrongGuesses = 0
        }

        if (consecutiveWrongGuesses == 2)
            {
            int middleIndex = wordLength / 2; // if consecutiveWrongGuesses = 2, hints reveal
            revealed[middleIndex] = 1;
        }

        clearScreen();
    }

    // // After the loop, check if the word has been fully revealed
    if (isWordRevealed(word, revealed))
        {
        printf("Congratulations! You guessed the word: %s\n", word); // If the word is fully revealed within attempts, the player wins
        return 1;
    } else {
        displayHangman(0);
        printf("Sorry, you lost. The word was: %s\n", word);     // Else Lost
        return 0;
    }
}
//---------------------------------------------------------------------------------------------------------------------------------

//-----------------------------Ronjon Sarker----MD Sayem---------------------------------------------------------------------------
int main() {
    char word[MAX_WORD_LENGTH]; // Array declared to store the guessed word
    int level, playAgain;    // Declared to store the current level and manipulate play again decision

    do {
        level = 1; // Initialize the game at level 1
        do {
            printf("Enter the word to be guessed for level %d: ", level); //ask player to input a letter
            scanf("%s", word);              // storing it word

            //Setting attempts according to levels
            int maxAttempts = (level == 1) ? MAX_ATTEMPTS_LEVEL1 : (level == 2) ? MAX_ATTEMPTS_LEVEL2 : MAX_ATTEMPTS_LEVEL3;

            //Play current level with specified word and max attempts according to level
            if (playLevel(word, maxAttempts)) {
                if (level == 3) // If player completed level 3
                    {
                    printf("Congrats! You have completed all levels!\n");
                    break; // ending the inner loop
                }

                //asking user if he wants to continue
                printf("Do you want to play again in level %d? (1 for Yes, 0 for No): ", level + 1);
                scanf("%d", &playAgain); //if 1 , return to play again with a level incemented
                if (playAgain) {
                    level++;
                } else {
                    printf("Well done, see you again!\n"); //if 0
                    break;
                }
            } else
            //If the player loose the current level
            {
                printf("Do you want to start a new round? (1 for Yes, 0 for No): ");
                scanf("%d", &playAgain);
                if (playAgain)    // If 1 , Start from level 1
                    {
                    level = 1;
                } else                   // If 0,
                 {
                    printf("Well done, see you again!\n");
                    break;
                }
            }
        } while (level <= 3); // Allows player to continue till level 3

        if (level == 3)  // If the player has completed all the levels, ask for another round.
            {
            printf("Do you want to play another round? (1 for Yes, 0 for No): ");
            scanf("%d", &playAgain);  // taking inpur
        } else {
            playAgain = 0; // If not in level 3 play again =0, end outer loop
        }
    } while (playAgain == 1); // Continuing outer loop if player wants another round

    return 0;   // end
}
//------------------------------MD Sayem---------Ronjon Sarker-----------------------------
