Hangman Game
------------


Overview
--------
This is a console-based Hangman game implemented in C. 
The game consists of three levels with varying numbers of allowed attempts. 
The player must guess the word by inputting one letter at a time. For each incorrect guess, a part of the hangman is drawn.
The game provides hints by revealing letters if the player makes consecutive wrong guesses.


Game Instructions :
-----------------
Start the Game: When you run the program, it starts at level 1.

Input Word: Enter the word to be guessed for the current level.

Guessing Letters: You will be prompted to guess a letter.

The game will show underscores for unrevealed letters and actual letters for revealed ones.

If you guess a correct letter, it will be revealed in the word.

If you guess an incorrect letter, a part of the hangman will be drawn.


Attempts:
--------
Level 1: 6 attempts
Level 2: 4 attempts
Level 3: 2 attempts


Hints:
-----
If you make 2 consecutive wrong guesses, a hint will reveal a letter in the word.

Winning and Losing:
If you guess all the letters in the word within the allowed attempts, you win the level.
If you fail to guess the word within the allowed attempts, you lose the level, and the complete hangman will be displayed.

Progression:
If you win a level, you can proceed to the next level.
If you lose a level, you can choose to start a new round from level 1.

Completion:
If you complete all 3 levels, you win the game and can choose to start another round or end the game.



Code Structure:
----------------
Main Function:
--------------
The main function controls the game flow:
It initializes the game at level 1.
It prompts the player to enter the word to be guessed.
It calls playLevel function to play the current level.
It handles the progression to the next level or restarting the game based on player's choice.



playLevel Function:
------------------
The playLevel function handles the gameplay for each level:
It initializes necessary variables for the game.
It displays the hangman and the word with revealed and unrevealed letters.
It takes the player's guess and checks if it's correct.
It updates the attempts left and the game state based on the guess.
It provides hints if the player makes 2 consecutive wrong guesses.
It checks if the word is fully revealed or if the player has run out of attempts.


Helper Functions:
-----------------
clearScreen: Clears the console screen.
displayWord: Displays the current state of the word with underscores for unrevealed letters and actual letters for revealed ones.
isWordRevealed: Checks if the entire word has been revealed.
displayHangman: Displays the hangman ASCII art based on the number of attempts left.


Authors:
-------
MD Sayem
Ronjon Sarker
