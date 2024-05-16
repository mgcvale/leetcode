#include <stdbool.h>

int lengthOfLastWord(char* s) {

    int wordLength = 0;
    bool looking_for_letters = true;
    for(int i = 0; i<strlen(s); i++) {
        if(s[i] != ' ') {
            if(looking_for_letters) { //if we were looking for letters, we found one! we can now stop looking for one.
                wordLength = 1; 
                looking_for_letters = false;
                continue;
            } else { //if, however, we were not looking for letters, we can just add to our word length and continue.
                wordLength++;
            }
        } else { //if it is a space, we can start looking for letters again.
            looking_for_letters = true;
        }
    }
    return wordLength;
}
