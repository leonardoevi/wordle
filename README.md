# wordle
C implementation of the game Wordle.

Guess the secret word in as few tries as possible.
If a letter of the word you guessed is colored green, it means that it is correct and in the right spot. If it's yellow, it means that it's correct but it is not in the right spot. If it's white, it means that the secret word doesn't contain that letter.

The keyboard displayed on the screen will help you visualize the informations you have on the secret word.

You can decide which file the possible secret words are picked from, and what are the possible guesses to accept. You just have to add those files in the folder and change the definitions of POSSIBLE_ANSWERS and ALLOWED_GUESSES to the name of your new files in the source code.
