# wordle
C implementation of the game Wordle.

Guess the secret word in as few tries as possible.
If a letter of the word you guessed is colored green, it means that it is correct and in the right spot. If it's yellow, it means that it's correct but it is not in the right spot. If it's white, it means that the secret word doesn't contain that letter.

The keyboard displayed on the screen will help you visualize the informations you have on the secret word.

You can decide which file the possible secret words are picked from, and what are the possible guesses to accept. You just have to add those files in the folder and change the definitions of POSSIBLE_ANSWERS and ALLOWED_GUESSES to the name of your new files in the source code.

Here is an example of how the game works:
<img width="1512" alt="Screenshot 2023-10-12 alle 19 48 28" src="https://github.com/leonardoevi/wordle/assets/141726636/7cef02d7-3ff5-489b-90dd-bc909203d872">
<img width="1512" alt="Screenshot 2023-10-12 alle 19 48 35" src="https://github.com/leonardoevi/wordle/assets/141726636/72f2f645-b330-44be-8da2-ccb26049f544">
<img width="1512" alt="Screenshot 2023-10-12 alle 19 48 41" src="https://github.com/leonardoevi/wordle/assets/141726636/894bbf65-56e3-4c9c-8214-6b9540e1f223">
<img width="1512" alt="Screenshot 2023-10-12 alle 19 49 04" src="https://github.com/leonardoevi/wordle/assets/141726636/acb3382d-3625-42af-84c0-f6bc0ab22118">
<img width="1512" alt="Screenshot 2023-10-12 alle 19 49 10" src="https://github.com/leonardoevi/wordle/assets/141726636/072403ce-33f8-496b-9719-0812567f2a12">
<img width="1512" alt="Screenshot 2023-10-12 alle 19 48 28" src="https://github.com/leonardoevi/wordle/assets/141726636/dda3a89e-8486-45f3-9fc0-11e75ccd7362">
