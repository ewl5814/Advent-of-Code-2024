#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    fptr = fopen("day1input.txt", "r");
    char buffer[50];
    int value1;
    int value2;
    int total;
    const char delimiter1[] = ")";
    const char delimiter2[] = "m";
    const char delimiter3[] = ",";
    char* token1;
    char* saveptr1 = NULL;
    char* saveptr2 = NULL;
    char* saveptr3 = NULL;

    fptr = fopen("day1input.txt", "r");
    while(fgets(buffer, 50, fptr)) {
        token1 = strtok_r(buffer, delimiter1, &saveptr1);
        while (token1 != NULL) {
            char* token2 = strtok_r(token1, delimiter2, &saveptr2);
            while (token2 != NULL) {
                char* token3 = strtok_r(token2, delimiter3, &saveptr3);
            
            }
        }
    }
    
    fclose(fptr);
    return 0;
}