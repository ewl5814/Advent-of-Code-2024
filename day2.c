#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isSafe(char buffer[]) {
    char* token = strtok(buffer, " ");
    int value1 = strtol(token, NULL, 10);

    int r = 1;
    int initial = 0;

    token = strtok(NULL, " ");
    int value2 = strtol(token, NULL, 10);
    
    if (value1 == value2) {
        initial++;
    }

    int damp = initial;

    if (value2 >= value1) {
        
        if (value2 - value1 > 3) {
            damp++;
        }

        value1 = value2;
        token = strtok(NULL, " ");

        while (token != NULL) {
            
            value2 = strtol(token, NULL, 10);

            if (value2 - value1 <= 0 || value2 - value1 > 3) {
                damp++;
            }
            else {
                value1 = value2;
            }

            if (damp > 1) {
                r = 0;
                break;
            }

            //value1 = value2;
            token = strtok(NULL, " ");
        }

        damp = initial;
    }
    else if (value2 <= value1) {
        
        if (value1 - value2 > 3) {
            damp++;
        }

        value1 = value2;
        token = strtok(NULL, " ");

        while (token != NULL) {
            
            value2 = strtol(token, NULL, 10);

            if (value1 - value2 <= 0 || value1 - value2 > 3) {
                damp++;
            }
            else {
                value1 = value2;
            }

            if (damp > 1) {
                r = 0;
                break;
            }

            //value1 = value2;
            token = strtok(NULL, " ");
        }
    }
    else {
        r = 0;
    }

    return r;
}

int main() {
    FILE *fptr;
    fptr = fopen("day2input.txt", "r");
    
    char buffer[100];
    int count = 0;
    int line = 1;

    while(fgets(buffer, 100, fptr)) {
        printf("%s ", buffer);
        if (isSafe(buffer)) {
            printf(" safe %d\n", line);
            count++;
        }
        line++;
    }

    printf("%d", count);
}
    
    