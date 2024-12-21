#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int simScore(int *arr1, int *arr2, int n) {
    int in = 0;
    int simScore = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr1[i] == arr2[j]) {
                in++;
            }
        }
        simScore += arr1[i] * in;
        in = 0;
    }
    return simScore;
}

int main() {
    FILE *fptr;
    fptr = fopen("day1input.txt", "r");

    char count[50];
    int c = 0;
    char buffer[50];
    int v1;
    int v2;
    int total = 0;
    
    while(fgets(count, 50, fptr)) {
        c++;
    }
    
    fclose(fptr);
    int value1[c];
    int value2[c];
    c = 0;

    fptr = fopen("day1input.txt", "r");
    while(fgets(buffer, 50, fptr)) {
        char* token = strtok(buffer, " ");
        v1 = strtol(token, NULL, 10);
        value1[c] = v1;
        
        token = strtok(NULL, " ");
        v2 = strtol(token, NULL, 10);
        value2[c] = v2;
        c++;
    }
    
    int n = sizeof(value1)/sizeof(value1[0]);
    qsort(value1, n, sizeof(int), comp);
    qsort(value2, n, sizeof(int), comp);

    for (int i = 0; i < n; i++) {
        total += abs(value1[i] - value2[i]);
    }
    printf("%d, %d", total, simScore(value1, value2, n));

    fclose(fptr);
    return 0;
}