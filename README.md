# wordle
C implementation of the game Wordle.

Guess the secret word in as few tries as possible.
If a letter of the word you guessed is colored green, it means that it is correct and in the right spot. If it's yellow, it means that it's correct but it is not in the right spot. If it's white, it means that the secret word doesn't contain that letter.

The keyboard displayed on the screen will help you visualize the informations you have on the secret word.

You can decide which file the possible secret words are picked from, and what are the possible guesses to accept. You just have to add those files in the folder and change the definitions of POSSIBLE_ANSWERS and ALLOWED_GUESSES to the name of your new files in the source code.

Here is an example of how the game works:
<img width="1512" alt="Screenshot 2023-10-12 alle 19 48 28" src="https://github.com/leonardoevi/wordle/assets/141726636/489b74fa-d77c-4a97-9c62-badfcc776324">
<img width="1512" alt="Screenshot 2023-10-12 alle 19 48 35" src="https://github.com/leonardoevi/wordle/assets/141726636/9c400ffc-9032-4048-9f41-901649d179c1">
<img width="1512" alt="Screenshot 2023-10-12 alle 19 48 41" src="https://github.com/leonardoevi/wordle/assets/141726636/58b10923-7661-43ec-9b3f-ac285502e924">
<img width="1512" alt="Screenshot 2023-10-12 alle 19 49 04" src="https://github.com/leonardoevi/wordle/assets/141726636/add33176-e1cc-44d1-bcef-2a67ca6fc5f8">
<img width="1512" alt="Screenshot 2023-10-12 alle 19 49 10" src="https://github.com/leonardoevi/wordle/assets/141726636/4ab44ff2-29d1-45aa-931d-7fe1a884b5d3">
<img width="1512" alt="Screenshot 2023-10-12 alle 19 49 22" src="https://github.com/leonardoevi/wordle/assets/141726636/d994f22e-672c-47b7-9cee-1ffdab7abcf7">
