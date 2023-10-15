# wordle
C implementation of the game Wordle.

Guess the secret word in as few tries as possible.
If a letter of the word you guessed is colored green, it means that it is correct and in the right spot. If it's yellow, it means that it's correct but it is not in the right spot. If it's white, it means that the secret word doesn't contain that letter.

The keyboard displayed on the screen will help you visualize the informations you have on the secret word.

You can decide which file the possible secret words are picked from, and what are the possible guesses to accept. You just have to add those files in the folder and change the definitions of POSSIBLE_ANSWERS and ALLOWED_GUESSES to the name of your new files in the source code.

Here is an example of how the game works:

<img width="1512" alt="Screenshot 2023-10-12 alle 19 48 28" src="https://github.com/leonardoevi/wordle/assets/141726636/e15c922f-7813-4d60-a920-ca64a76613fa">
<img width="1512" alt="Screenshot 2023-10-12 alle 19 48 35" src="https://github.com/leonardoevi/wordle/assets/141726636/ca0dd520-99fb-41c6-933d-317be14253b6">
<img width="1512" alt="Screenshot 2023-10-12 alle 19 48 41" src="https://github.com/leonardoevi/wordle/assets/141726636/e2cc0c7f-425f-4f13-a0c9-8fedb118d2c2">
<img width="1512" alt="Screenshot 2023-10-12 alle 19 49 04" src="https://github.com/leonardoevi/wordle/assets/141726636/110ad93b-1db5-4558-932f-5f56d1f9c0c5">
<img width="1512" alt="Screenshot 2023-10-12 alle 19 49 10" src="https://github.com/leonardoevi/wordle/assets/141726636/edcfd59c-4def-46fd-b1e9-df50d2ba39d2">
<img width="1512" alt="Screenshot 2023-10-12 alle 19 49 22" src="https://github.com/leonardoevi/wordle/assets/141726636/3c16fdae-723f-46b0-b68e-789fa1533a93">
