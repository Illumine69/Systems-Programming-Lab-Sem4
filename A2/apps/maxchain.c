#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wordutils.h>

#define SIZE 100

typedef struct _chain{
    char* word;
}chain;

//calulate the length of chain
int chain_len(chain* c){
    int i = 0;
    while(c[i].word != NULL){
        i++;
    }
    return i;
}

//get max possible chain according to the dictionary
void getMaxChain(dict *D, chain* C, int len, int* maxLen, chain** maxChain){
	
    // base case
    if(len > *maxLen){
        *maxLen = len;
        *maxChain = C;
    }

    // recursive case 1 - add before
    char* before = addbefore(D, C[len-1].word);

    for(int i=0; before[i]!='\0'; i++){

        chain* temp = (chain*)malloc(sizeof(chain)*(len+1));
        for(int j=0; j < len; j++){
            temp[j] = C[j];
        }
        temp[len].word = (char*)malloc(sizeof(char)*strlen(C[len-1].word)+2);
        temp[len].word[0] = before[i];
        strcpy(temp[len].word+1, C[len-1].word);

        getMaxChain(D, temp, len+1, maxLen, maxChain);
    }

    // recursive case 2 - add after
    char* after = addafter(D, C[len-1].word);
    for(int i=0; after[i]!='\0'; i++){

        chain* temp = (chain*)malloc(sizeof(chain)*(len+1));
        for(int j=0; j < len; j++){
            temp[j] = C[j];
        }
        temp[len].word = (char*)malloc(sizeof(char)*strlen(C[len-1].word)+2);
        strcpy(temp[len].word, C[len-1].word);
        temp[len].word[strlen(C[len-1].word)] = after[i];
        temp[len].word[strlen(C[len-1].word)+1] = '\0';
        
        getMaxChain(D, temp, len+1, maxLen, maxChain);
    }

    free(before);
    free(after);
    return;
}

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

    chain** maxChain = (chain**)malloc(sizeof(chain*));
    chain* C = (chain*)malloc(sizeof(chain));
    C[0].word = "";
    int maxLen = 0;
    getMaxChain(&D, C, 1, &maxLen, maxChain);

    for(int i=0; i<maxLen; i++){
        if(strcmp((*maxChain)[i].word, "") != 0){
            printf("%s\n", (*maxChain)[i].word);
        }
    }
    free(maxChain);
    free(C);
    return 0;
}