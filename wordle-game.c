#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>

//game options
#define WORD_LEN 5
#define NR_OF_GUESSES 6

//file names, can coincide
#define POSSIBLE_ANSWERS "answers.txt"
#define ALLOWED_GUESSES "accepted_words.txt"

//clear terminal with printf("\e[1;1H\e[2J");
#define CLEAR "\e[1;1H\e[2J"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLACK "\033[0;30m"
#define RESETCOLOUR "\033[0m"

#define CORRECT 'g'
#define MISPLACED 'y'
#define WRONG 'b'

//qwerty keyboard structure
#define NR_OF_KEYS 26
#define ROW1LEN 10
#define ROW2LEN 9
#define ROE3LEN 7

//every guessed word has a 'check' string that tells wich letters are CORRECT, MISPLACED or WRONG
typedef struct guess_str{
    char word[WORD_LEN + 1];
    char* check;
} guess;

typedef struct keys_struct{
    char keys[NR_OF_KEYS + 1];
    char colours[NR_OF_KEYS + 1];
}keyboard_str;

char* cmp_words(char* guess, char* reference);
void check_init(char* check);
void table_init();
void choose_answer();
void print_guess(guess* G);
void print_table();
void get_guess();
int is_valid_entry(char*);
int mystrncmp(char* str1, char* str2, int n);

void printkeys();
int key_idx(char c);
void key_color_update(char c, char color);
void updatekeyboard();

guess Table[NR_OF_GUESSES];
char secret_word[WORD_LEN + 1] = "HOUSE\0";

int Round = 0;
int nr_answers = 0;
int error = 0;

keyboard_str keyboard = {
    {"qwertyuiopasdfghjklzxcvbnm\0"}, //keys
    {"wwwwwwwwwwwwwwwwwwwwwwwwww\0"}  //keys color
};

int main(){
    int WIN = 0;
    table_init();
    choose_answer();

    if(error) return 0;

    printf("%s\n", secret_word);

    while(Round < NR_OF_GUESSES && !WIN && !error){
        printf(CLEAR);
        print_table();
        printkeys();
        get_guess();
        updatekeyboard();
        
        if(strncmp(Table[Round].word, secret_word, WORD_LEN ) == 0)
            WIN = 1;

        Round++;
    }

    if(error) return 0;

    printf(CLEAR);
    print_table();

    if(WIN)
        printf("You found the correct word in %d guesses!\n\n", Round);
    else
        printf("You lost, the correct word is: %s\n\n", secret_word);

    return 0;
}

//compares guessed word to reference word
//returns a string that tells wich letters of the guessed word are CORRECT (g), wich are MISPLACED (y) and wich are WRONG (b)
//for example if the reference word is HEART and the guessed word is SLATE
//                HEART
//                SLATE
//it will return "bbgyy"
char* cmp_words(char* guess, char* reference){
    char* check = (char*)malloc(sizeof(char) * WORD_LEN);

    //create a copy of the words to work on
    char guess_tmp[WORD_LEN + 1];
    strcpy(guess_tmp, guess);
    char ref_tmp[WORD_LEN + 1];
    strcpy(ref_tmp, reference);

    int i, j;
    //initialize check array
    check_init(check);

    //look for CORRECT letters
    for(i=0; i < WORD_LEN; i++){
        if(guess_tmp[i] == ref_tmp[i]){
            guess_tmp[i] = ref_tmp[i] = '-';
            check[i] = CORRECT;
        }
    }
    //look for MISPLACED letters
    for(i=0; i < WORD_LEN; i++){
        if(guess_tmp[i] != '-')
            for(j=0; j < WORD_LEN; j++){
                if(guess_tmp[i] == ref_tmp[j]){
                    guess_tmp[i] = ref_tmp[j] = '-';
                    check[i] = MISPLACED;
                    break;
                }
            }
    }

    return check;
}

void check_init(char* check){
    for(int i=0; i < WORD_LEN; i++){
        check[i] = WRONG;
    }
}

//prints a guessed word acording to the colors specified in the "check" array 
void print_guess(guess* G){
    int i;
    printf("\t      ");
    for(i=0; i < WORD_LEN; i++){
        if(G->check[i] == WRONG)
            printf(RESETCOLOUR);
        else if (G->check[i] == MISPLACED)
            printf(YELLOW);
        else 
            printf(GREEN);
        
        printf("%c", G->word[i]);
    }
    printf(RESETCOLOUR);
    printf("\n");
    return;
}

//initializes the table, every guessed word is "_____" and their check arrays are "bbbbb"
void table_init(){
    int i;
    int j;
    for(i=0; i<NR_OF_GUESSES; i++){
        for(j=0; j<WORD_LEN; j++)
            Table[i].word[j] = '_';
        Table[i].check = (char*)malloc(sizeof(char) * WORD_LEN);
        for(j=0; j<WORD_LEN; j++)
            Table[i].check[j] = WRONG;
    }
}

void print_table(){
    int i;
    for(i=0; i < NR_OF_GUESSES; i++)
        print_guess(&Table[i]);
    printf("\n");
    return;
}

//requres the user to guess a word, checking if it is valid.
//assigns the word to the guess of the current ROUND with its "check" array
void get_guess(){
    char word[WORD_LEN + 1];
    int valid = 0;
    int i;
    do{
        printf("Your %d letter word guess is: ", WORD_LEN);
        for(i=0; i < WORD_LEN; i++){
            scanf("%c", &word[i]);
            if(word[i] == '\n' || word[i] == ' ')
                i--;
        }
        fflush(stdin);
//        printf("\n");
        word[WORD_LEN] = '\0';

        valid = is_valid_entry(word);   
        if(error) return;
    }while(valid == 0);

    for(i=0; i< WORD_LEN; i++)
        word[i] = toupper(word[i]);

    strcpy(Table[Round].word, word);
    free(Table[Round].check);
    Table[Round].check = cmp_words(Table[Round].word, secret_word);

    return;
}

//validates the guessed word
int is_valid_entry(char* word){
    //check if it is of the right lenght
    if(strlen(word) != WORD_LEN)
        return 0;

    int i;
    //check if player hasn't tried it yet
    for(i=0; i<WORD_LEN; i++){
        if(mystrncmp(word, Table[i].word, WORD_LEN) == 0){
            printf("This was your guess number %d, try something else!\n\n", i+1);
            return 0;
        }
    }


    //check if it's contained in allowed guesses
    FILE* allowed = fopen(ALLOWED_GUESSES, "r");
    if(allowed == NULL){
        printf("--- UNABLE TO OPEN %s FILE ---\n", POSSIBLE_ANSWERS);
        error = 1;
        return 0;
    }

    char tmp[WORD_LEN + 1];
    while (!feof(allowed)){
        fscanf(allowed, "%s", tmp);
        if(mystrncmp(tmp, word, WORD_LEN) == 0){
            fclose(allowed);
            return 1;
        }
    }
    
    fclose(allowed);
    printf("word not allowed\n\n");
    return 0;

}

//selects a random word from the POSSIBLE_ANSWERS file
void choose_answer(){
    char tmp[WORD_LEN + 1];

    FILE* possible = fopen(POSSIBLE_ANSWERS, "r");
    if(possible == NULL){
        printf("--- UNABLE TO OPEN %s FILE ---\n", POSSIBLE_ANSWERS);
        error = 1;
        return;
    }

    while (!feof(possible)){
        fscanf(possible, "%s", tmp);
        nr_answers++;
    }

    printf("Possible answers: %d\n", nr_answers);

    srand((unsigned int)time(NULL));
    nr_answers = rand()%nr_answers;

    printf("I choose nr: %d\n", nr_answers);

    fseek(possible, 0, SEEK_SET);

    while(nr_answers > 0){
        fscanf(possible, "%s", tmp);
        nr_answers--;
    }
    fscanf(possible, "%s", tmp);

    for(int i=0; i< WORD_LEN; i++)
            tmp[i] = toupper(tmp[i]);

    fclose(possible);
    strncpy(secret_word, tmp, WORD_LEN);
    return;
}

// strncmp (case insensitive)
int mystrncmp(char* str1, char* str2, int n){
    int i;
    for(i=0; i<n; i++)
        if(tolower(str1[i]) != tolower(str2[i]))
            return 1;
    return 0;
}

//prints the keyboard, with the correct colors for each key
void printkeys(){
    int i;

    printf("\t");
    for(i=0; i<NR_OF_KEYS; i++){
        if(i == ROW1LEN) printf("\n\t ");
        if(i == ROW2LEN + ROW1LEN) printf("\n\t  ");

        if(keyboard.colours[i] == 'w'){
            printf(RESETCOLOUR);
            printf("%c ", toupper(keyboard.keys[i]));
        } else if (keyboard.colours[i] == 'b'){
            printf(BLACK);
            printf("%c ", toupper(keyboard.keys[i]));
        } else if (keyboard.colours[i] == 'y'){
            printf(YELLOW);
            printf("%c ", toupper(keyboard.keys[i]));
        }   else {
            printf(GREEN);
            printf("%c ", toupper(keyboard.keys[i]));
        }
    } printf("\n\n"); printf(RESETCOLOUR);
}

//returns the index of a character (in the keyboard array) q->0 w->1 e->2 r->3 t->4 y->5 ...
int key_idx(char c){
    int i = 0;
    while(i < NR_OF_KEYS && tolower(c) != tolower(keyboard.keys[i]))
        i++;
    return i;
}

//updates the color of a key, according to the Wordle rules
void key_color_update(char c, char newcolor){
    int idx = key_idx(c);

    if(keyboard.colours[idx] == WRONG || keyboard.colours[idx] == CORRECT)
        return;
    if(keyboard.colours[idx] == 'w'){
        keyboard.colours[idx] = newcolor;
        return;
    }
    if(keyboard.colours[idx] == MISPLACED && newcolor == CORRECT){
        keyboard.colours[idx] = newcolor;
        return;
    }

    return;
}

void updatekeyboard(){
    int i;
    for(i=0; i<WORD_LEN; i++){
        key_color_update(Table[Round].word[i], Table[Round].check[i]);
    }
}
