#ifndef __KEYBOARD_H
#define __KEYBOARD_H

#include <stdbool.h>

bool check_word(char * cur_word);
bool check_next_letter(char cur_letter, char next_letter);

bool searching_letter(char letter, char * subsequence);

#endif //__KEYBOARD_H


