#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ADTStack.h"

#define MAX_LENGTH 16

typedef struct intl_passenger {
    char given_name[MAX_LENGTH];
    char surname[MAX_LENGTH];
    char passport_id[MAX_LENGTH];
    char country[MAX_LENGTH];
} intl_passenger;


intl_passenger *pCreate() {
    intl_passenger *p = malloc(sizeof(struct intl_passenger));
    if(!p) {
        fprintf(stderr, "Cannot allocate memory\n");
        exit(-1);
    }
    return p;
}


void pDestroy(intl_passenger* p) {
    free(p);
}


char* label_elm(intl_passenger* p) {
    char* str = malloc((16 * 4) + 4);
    if(!str) {
        fprintf(stderr, "Cannot allocate memory\n");
        exit(-1);
    }
    strcat(str, p->given_name);
    strcat(str, " ");
    strcat(str, p->surname);
    strcat(str, " ");
    strcat(str, p->passport_id);
    strcat(str, " ");
    strcat(str, p->country);
    return str;
}


int main() {
    FILE* fp = fopen("international_passengers.dat", "r");
    if(!fp) {
        fprintf(stderr, "Cannot open file, aborting\n");
        exit(-1);
    }

    Stack stack = init(60, (void *(*)(void *)) strcpy, free, (char *(*)(void *)) label_elm);

    char* buff = NULL;
    size_t bufSize = 0;
    char* word;
    int count = 0;

    while(getline(&buff, &bufSize, fp) != EOF) {
        intl_passenger *p = pCreate();
        word = strtok(buff, " ");
        while(word != NULL ) {
            if(count == 0) {
                strcpy(p->given_name, word);
            }
            else if(count == 1) {
                strcpy(p->surname, word);
            }
            else if(count == 2) {
                strcpy(p->passport_id, word);
            }
            else if(count == 3) {
                strcpy(p->country, word);
                push(stack, p);
                count = -1;
            }
            count++;
            word = strtok(NULL, " ");
        }
    }

    fclose(fp);
    free(buff);

    intl_passenger *temp;
    while(size(stack) != 0) {
        temp = pop(stack);
        printf("%s %s %s\n", temp->given_name, temp->surname, temp->passport_id);
    }

    pDestroy(temp);
    destroy(stack);

    return 0;
}
