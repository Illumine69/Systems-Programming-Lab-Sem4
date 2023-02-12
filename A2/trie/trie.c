#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <trie.h>

//creates an empty trie containing only the root node
trie trieinit(){

    trie* T = (trie*)malloc(sizeof(trie));
    T->root = (trienode*)malloc(sizeof(trienode));
    T->root->isword = 0;
    T->root->firstChild = NULL;
    T->root->nextSibling = NULL;
    return *T;
}

//finds whether the string S is stored in the trie T
int triesearch(trie* T, char* s){

    trienode* current = T->root;
    int i = 0;              //counter to get each character of string s
    
    while(s[i] != '\0'){
        if(current->firstChild == NULL){        //since string did not end and we have reached the root node
            return 0;
        }
        current = current->firstChild;

        while(current->nextSibling != NULL && current->char_label != s[i]){        //traverse in same row
            current = current->nextSibling;
        }
        if(current->char_label != s[i]){        //reached row end and still didn't find matching character
            return 0;
        }
        i++;
    }
    if(current->isword == 1){       //check whether the node is marked after finishing search
        return 1;
    }
    return 0;
}

//inserts a string S in a sorted trie 
void trieinsert(trie* T, char* s){

    trienode* current = T->root;
    trienode* previous = T->root;
    int i = 0;              //counter to get each character of string s

    while(s[i] != '\0'){
        if(current->firstChild == NULL){        //if no child exists, we create a new child with the required character
            trienode* newnode = (trienode*)malloc(sizeof(trienode));
            newnode->char_label = s[i];
            newnode->isword = 0;
            newnode->firstChild = NULL;
            newnode->nextSibling = NULL;
            current->firstChild = newnode;
            current = newnode;
        }
        else{
            previous = current;
            current = current->firstChild;

            while(current->char_label < s[i] && current->nextSibling != NULL && current->nextSibling->char_label <= s[i]){      //checks if required character is not in current along with the next sibling node
                current = current->nextSibling;
            }
            if(current->char_label > s[i]){     //if the new character has to be inserted between current and previous node
                trienode* newnode = (trienode*)malloc(sizeof(trienode));
                newnode->char_label = s[i];
                newnode->isword = 0;
                newnode->firstChild = NULL;
                newnode->nextSibling = current;
                previous->firstChild = newnode;
                current = newnode;
            }
            else if(current->char_label == s[i]){       //if the current node has the character
                i++;
                continue;
            }
            else if(current->nextSibling!=NULL && current->nextSibling->char_label > s[i]){     //if the new character has to be inserted between current and next sibling node
                trienode* newnode = (trienode*)malloc(sizeof(trienode));
                newnode->char_label = s[i];
                newnode->isword = 0;
                newnode->firstChild = NULL;
                newnode->nextSibling = current->nextSibling;
                current->nextSibling = newnode;
                current = newnode;
            }
            else{                                       //if we reach the end of row                                                        
                trienode* newnode = (trienode*)malloc(sizeof(trienode));
                newnode->char_label = s[i];
                newnode->isword = 0;
                newnode->firstChild = NULL;
                newnode->nextSibling = NULL;
                current->nextSibling = newnode;
                current = newnode;
            }
        }
        i++;
    }
    current->isword = 1;        //marks the root node
}

//prints an alphabetic listing of all the words stored in the trie T 
void listall(trie* T, char* s){

    trienode* current = T->root;
    if(current->isword == 1){       //prints all the characters traversed down upto this node
        printf("%s\n", s);
    }
    current = current->firstChild;
    while(current != NULL){     
        trie subT = {current};     //creates a sub trie with current as root node
        char* subS = (char*)malloc(sizeof(char)*(strlen(s)+2));     //creates a sub string which stores the word upto the current node from the root
        strcpy(subS, s);        
        strcat(subS, &current->char_label);
        listall(&subT, subS);       //recursively call the sub trie and appends all characters to subS which are in trie
        current = current->nextSibling;     //repeats same for the next node in the row
    }
}
