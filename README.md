# wordle
C implementation of the game Wordle.

Guess the secret word in as few tries as possible.
If a letter of the word you guessed is colored green, it means that it is correct and in the right spot. If it's yellow, it means that it's correct but it is not in the right spot. If it's white, it means that the secret word doesn't contain that letter.

The keyboard displayed on the screen will help you visualize the informations you have on the secret word.

You can decide which file the possible secret words are picked from, and what are the possible guesses to accept. You just have to add those files in the folder and change the definitions of POSSIBLE_ANSWERS and ALLOWED_GUESSES to the name of your new files in the source code.

Here is an example of how the game works:

<img width="928" alt="Screenshot 2023-10-12 alle 19 49 22" src="https://github.com/leonardoevi/wordle/assets/141726636/8c9dc428-0aa7-41e5-9342-7edb6af7a203">
<img width="792" alt="Screenshot 2023-10-12 alle 19 49 10" src="https://github.com/leonardoevi/wordle/assets/141726636/c0b37fcf-af50-43ef-b16c-55e35b4e3c33">
<img width="805" alt="Screenshot 2023-10-12 alle 19 49 04" src="https://github.com/leonardoevi/wordle/assets/141726636/6fd46253-4e02-4d8a-8500-942421469d71">
<img width="805" alt="Screenshot 2023-10-12 alle 19 48 41" src="https://github.com/leonardoevi/wordle/assets/141726636/60cbad51-1291-4939-b6fc-baf9716ae151">
<img width="795" alt="Screenshot 2023-10-12 alle 19 48 35" src="https://github.com/leonardoevi/wordle/assets/141726636/68b98b52-d5a3-4ce9-877f-fcad6719d4e2">
<img width="800" alt="Screenshot 2023-10-12 alle 19 48 28" src="https://github.com/leonardoevi/wordle/assets/141726636/2110d444-2ddf-4205-8578-415976a0f1a2">
