#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 256

int main(void) {
    char userInput[MAX_INPUT_SIZE];

    printf("Enter a 64-bit binary string or a decimal number: ");
    
    if (fgets(userInput, sizeof(userInput), stdin) == NULL) {
        printf("Error getting input\n");
        return 1;
    }
}