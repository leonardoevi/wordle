# wordle
C implementation of the game Wordle.

Guess the secret word in as few tries as possible.
If a letter of the word you guessed is colored green, it means that it is correct and in the right spot. If it's yellow, it means that it's correct but it is not in the right spot. If it's white, it means that the secret word doesn't contain that letter.

The keyboard displayed on the screen will help you visualize the informations you have on the secret word.

You can decide which file the possible secret words are picked from, and what are the possible guesses to accept. You just have to add those files in the folder and change the definitions of POSSIBLE_ANSWERS and ALLOWED_GUESSES to the name of your new files in the source code.

Here is an example of how the game works:

<img width="800" alt="Screenshot 2023-10-12 alle 19 48 28" src="https://github.com/leonardoevi/wordle/assets/141726636/acc5547e-2e68-4433-9edf-20e9e3a67095">
<img width="795" alt="Screenshot 2023-10-12 alle 19 48 35" src="https://github.com/leonardoevi/wordle/assets/141726636/053d4d1c-995f-48b0-bfce-2a86bf3785b0">
<img width="805" alt="Screenshot 2023-10-12 alle 19 48 41" src="https://github.com/leonardoevi/wordle/assets/141726636/bfe693ff-cb30-4017-946a-16800eaaa7ad">
<img width="805" alt="Screenshot 2023-10-12 alle 19 49 04" src="https://github.com/leonardoevi/wordle/assets/141726636/1c5f0bb5-216d-440c-a8ad-ef40ae328bf5">
<img width="792" alt="Screenshot 2023-10-12 alle 19 49 10" src="https://github.com/leonardoevi/wordle/assets/141726636/c90b12cf-b14e-430c-bc25-606e7d853b0f">
<img width="928" alt="Screenshot 2023-10-12 alle 19 49 22" src="https://github.com/leonardoevi/wordle/assets/141726636/3c2ef9a3-e74d-4c4f-b1c9-d48e0245fc11">

