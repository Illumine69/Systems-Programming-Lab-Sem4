#ifndef TRIE_H
#define TRIE_H

//Node of trie datatype
typedef struct _trienode{
    char char_label;
    int isword;
    struct _trienode *firstChild;
    struct _trienode *nextSibling;
} trienode;

//Trie datatype
typedef struct _trie{
    trienode *root;
} trie;

//Declaration of trie functions
trie trieinit();
int triesearch(trie*, char* );
void trieinsert(trie*, char* );
void listall(trie*, char* s);

#endif