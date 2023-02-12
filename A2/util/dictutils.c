#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dictutils.h>

//returns a single string consisting of all single letters that can be added before s
char* addbefore(dict *D, char* s){

    char arr[27];                //This will store all possible char which can be appended before s
    int valid_char_len = 0;
    char* test_string = (char*)malloc(sizeof(char)*(strlen(s)+2));
    strcpy(test_string, "a");
    strcat(test_string, s);

    for(int i = 0; i < 26; i++){
        test_string[0] = 'a' + i;
        if(triesearch(D, test_string) == 1){
            arr[valid_char_len++] = 'a' + i;
        }
    }

    arr[valid_char_len] = '\0';
    char* validchar = strdup(arr);
    free(test_string);
    return validchar;
}

//returns a single string consisting of all single letters that can be added after s
char* addafter(dict *D, char* s){

    char arr[27];               //This will store all possible char the can be appended to s
    int valid_char_len = 0;
    int length_s = strlen(s);
    char* test_string = (char*)malloc(sizeof(char)*(length_s+2));
    strcpy(test_string, s);
    test_string[length_s+1] = '\0';

    for(int i = 0; i < 26; i++){
        test_string[length_s] = 'a' + i;
        if(triesearch(D, test_string) == 1){
            arr[valid_char_len++] = 'a' + i;
        }
    }

    arr[valid_char_len] = '\0';
    char* validchar = strdup(arr);
    free(test_string);
    return validchar;
}

//returns factorial of a number
int factorial(int n){

    int fact = 1;
    for(int i = 2; i <= n; i++){
        fact *= i;
    }
    return fact;
}

//returns a dynamically allocated array of all permutations of string s
char** permute(char* s){

    int length_s = strlen(s);
    char** permute_arr = (char**)malloc(sizeof(char*)*(factorial(length_s)+1));   //permute_arr stores all the possible permutations of string s

    //base case: if string s has only one character
    if(length_s == 1){
        permute_arr[0] = strdup(s);
        permute_arr[1] = NULL;
        return permute_arr;
    }

    int alpha[26] = {0};
    int permute_len = 0;
    char* valid_string = (char*)malloc(sizeof(char)*(length_s+1));
    char* test_string = (char*)malloc(sizeof(char)*(length_s+1));

    for(int i = 0; i < length_s; i++){
        
        if(alpha[s[i]-'a'] != 0){
            continue;
        }
        alpha[s[i]-'a'] = 1;
        valid_string[0] = s[i];
        strcpy(test_string, s);
        test_string[i] = '\0';
        strcat(test_string, s+i+1);     //test_string now has all the characters of s except the ith character
        
        
        char** sub_permutes = permute(test_string);
        int j = 0;

        while(sub_permutes[j] != NULL){
            valid_string[1] = '\0';
            strcat(valid_string, sub_permutes[j]);
            permute_arr[permute_len++] = strdup(valid_string);
            j++;
        }
        free(sub_permutes);
    }

    permute_arr[permute_len] = NULL;
    free(valid_string);
    free(test_string);
    return permute_arr;
}

//returns a dynamically allocated array of all permutations of string s which are present in the dictionary
char** anagrams(dict *D, char* s){
    
    int length_s = strlen(s);
    char** anagrams_arr = (char**)malloc(sizeof(char*)*(factorial(length_s)+1));      //anagrams_arr stores all the possible anagrams of string s
    int anagrams_len = 0;

    char** permute_str = permute(s);
    int j = 0;
    while(permute_str[j] != NULL){
        if(triesearch(D, permute_str[j]) == 1){
            anagrams_arr[anagrams_len++] = strdup(permute_str[j]);
        }
        j++;
    }

    free(permute_str);
    anagrams_arr[anagrams_len] = NULL;
    return anagrams_arr;
}
