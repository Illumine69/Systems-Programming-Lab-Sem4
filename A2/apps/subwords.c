#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wordutils.h>

int main(){
    dict D;
    printf("Which dictionary do you wish to use ?\n");
    printf("1.Default\t2.Other\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    while(choice != 1 && choice != 2){
        printf("Please enter correct choice: ");
        scanf("%d", &choice);
    }
    if(choice == 1){
        D = loaddfltdict();
    }
    else{
        char file[30];
        printf("Enter file name that is saved in the dict directory: ");
        scanf("%s", file);
        
        char* file_name = (char*)malloc(sizeof(char)*40);
        strcpy(file_name, "../dict/");
        strcat(file_name, file);
        D = loaddict(fopen(file_name, "r"));
        free(file_name);
    }

    char* word = (char*)malloc(sizeof(char));
    printf("Enter a lower-case string: ");
    scanf("%s", word);
    int alpha[26] = {0};
    int count = 0;
    
    for(int i = 0; i < strlen(word); i++){
        if(alpha[word[i] - 'a'] != 0){  // if the letter has already been used, ignore it
            continue;
        }
        alpha[word[i] - 'a'] = 1;
        char* substr = strdup(word);
        substr[i] = '\0';
        strcat(substr, word + i + 1);  // remove the ith letter from the string

        char** subwords = anagrams(&D, substr);
        int j = 0;
        while(subwords[j] != NULL){
            printf("%s\n", subwords[j]);
            j++;
            count++;
        }
    }
    printf("%d subwords found\n", count);
    free(word);
    return 0;
}