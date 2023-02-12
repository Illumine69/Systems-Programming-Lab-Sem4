#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dictload.h>

//read default dict file line by line, and prepare a dict from the strings read
dict loaddfltdict(){
    FILE *DFLT_DICT = fopen("../dict/words.txt", "r");

    if (DFLT_DICT == NULL){
        printf("Error opening default dictionary file");
        exit(1);
    }

    dict d = trieinit();
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, DFLT_DICT)) != -1) {
        line[strlen(line)-1] = '\0';
        trieinsert(&d, line);
    }

    fclose(DFLT_DICT);
    if (line)
        free(line);
    
    return d;
}

//builds dict from an explicitly specified dictionary file
dict loaddict(FILE *fname){

    dict d = trieinit();
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fname)) != -1) {
        line[strlen(line)-1] = '\0';
        trieinsert(&d, line);
    }

    if (line)
        free(line);
    
    return d;
}
