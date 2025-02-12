#include "../inc/keyboard.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char alphabet[] = "qwertyuiopasdfghjklzxcvbnm";

char letter_q[] = "qwa";
char letter_w[] = "wqase";
char letter_e[] = "ewsdr";
char letter_r[] = "redft";
char letter_t[] = "trfgy";
char letter_y[] = "ytghu";
char letter_u[] = "uyhji";
char letter_i[] = "iujko";
char letter_o[] = "oiklp";
char letter_p[] = "pol";

char letter_a[] = "aqwsz";
char letter_s[] = "szawedx";
char letter_d[] = "dxserfc";
char letter_f[] = "fcdrtgv";
char letter_g[] = "gvftyhb";
char letter_h[] = "hbgyujn";
char letter_j[] = "jnhuikm";
char letter_k[] = "kmjiol";
char letter_l[] = "lkop";

char letter_z[] = "zasx";
char letter_x[] = "xzsdc";
char letter_c[] = "cxdfv";
char letter_v[] = "vcfgb";
char letter_b[] = "bvghn";
char letter_n[] = "nbhjm";
char letter_m[] = "mnjk";

/*char *alphabet_letters[26] = {

    letter_q,
    letter_w,
    letter_e,
    letter_r,
    letter_t,
    letter_y,
    letter_u,
    letter_i,
    letter_o,   
    letter_p,

    letter_a,
    letter_s,
    letter_d,
    letter_f,
    letter_g,
    letter_h,
    letter_j,
    letter_k,
    letter_l,

    letter_z,
    letter_x,
    letter_c,
    letter_v,
    letter_b,
    letter_n,
    letter_m
};
*/

char *alphabet_letters_straight[26] = {
    letter_a,
    letter_b,
    letter_c,
    letter_d,
    letter_e,
    letter_f,
    letter_g,
    letter_h,
    letter_i,
    letter_j,
    letter_k,
    letter_l,
    letter_m,
    letter_n,
    letter_o,
    letter_p,
    letter_q,
    letter_r,
    letter_s,
    letter_t,
    letter_u,
    letter_v,
    letter_w,
    letter_x,
    letter_y,
    letter_z
};


bool check_word(char * cur_word) {

    // printf("%s\n", cur_word);

    if (cur_word == NULL) {                                     // Проверяем, не пустой ли указатель
        printf("Error: word is NULL!\n");
        return false;
    }

    size_t len = strlen(cur_word);                              
    // printf("Length: %zu\n", len);

    for (size_t i = 0; i < len -1; i++)
    {
        if (!check_next_letter(cur_word[i], cur_word[i+1]))
            return false;
        // printf("succsessfully for letter - %c\n", cur_word[i]);
    }
    return true;
}

bool check_next_letter(char cur_letter, char next_letter) {
    static bool flag_re_press = false;

    if (!((cur_letter >= 'a' && cur_letter <= 'z') || (cur_letter >= 'A' && cur_letter <= 'Z'))) {
        printf("Error: letter not supported!\n");
        return false;
    }

    cur_letter = tolower(cur_letter);
    next_letter = tolower(next_letter);
    int index = cur_letter - 'a';                               // Получаем индекс в массиве (например, 'c' - 'a' = 2)
    
    char *cur_subsequence = alphabet_letters_straight[index];   // Получаем нужную строку


    if (cur_letter == next_letter) {                            // Проверяем, что клавиша нажата дважды подряд
        if (flag_re_press == true) {
            flag_re_press = false;
            printf("The letter is using more than twice - %c!\n", cur_letter);
            return false;
        }
        flag_re_press = true;
    }
    else flag_re_press = false;

    if (searching_letter(next_letter, cur_subsequence))
        return true;
    else {
        printf("There is no any subsequence letters left!\n");
        return false;
    }
}

bool searching_letter(char letter, char * subsequence) {
    size_t len = strlen(subsequence);

    for (size_t i = 0; i < len; i++)
    {
        // printf("%c and %c\n", letter, subsequence[i]);
        if ((char)letter == subsequence[i])
            return true;
    }
    return false;
    
}