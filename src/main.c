#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#include <direct.h>

#include "../inc/keyboard.h"

// char *file_name = "C:/DanyaMain/Projects_programming/C/ProjectForWork/words.txt";
// char *file_name = "words.txt";

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Using: %s <path_to_file>\n", argv[0]);
        return 1;
    }

    char *file_path = argv[1];

    // char cwd[1024];
    // if (_getcwd(cwd, sizeof(cwd)) != NULL) {
    //     printf("Current directory   : %s\n", cwd);
    // }

    FILE *file = fopen(file_path, "r"); 
    if (!file) {
        perror("Error of open file in that directory");
        return 1;
    }
    printf("File open: %s\n\n", file_path);

    int counter_words = 0;
    int counter_all_words = 0;
    char word[1024]; \

    while (fgets(word, sizeof(word), file)) {  
        counter_all_words++;
        word[strcspn(word, "\n")] = '\0';       // Удаляем символ новой строки '\n', если есть
        
        // printf("Current counter words = %d\n", counter_words);
        printf("%d.Word read: %s\n", counter_all_words, word);

        if (check_word(word)) {
            printf("The word fits\n");
            counter_words++;
        }
        printf("Current counter words with adjacent keys = %d\n", counter_words);
        printf("\n");
    }

    fclose(file); 

    printf("\nTotal counter words with adjacent keys = %d\n", counter_words);
    

    // _getch();

    return 0;
}
