#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 256

void removeNewline(char *str) {
    size_t length = strlen(str);
    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';
    }
}

int isDecimalOrDouble(const char *str) {
    int dotCount = 0; 
    size_t length = strlen(str);

    if (length == 0) return 0; //empty string 


    for (size_t i = 0; i < length; i++) {
        if (str[i] == '.') {
            dotCount++;
            if (dotCount > 1) return 0; // More than one dot
        } else if (!isdigit(str[i])) {
            return 0; //not a digit or a dot
        }
    }
    
    if (length == 64 && dotCount==0) return 2; // A Double

    return 1; //Valid
}

int main(void) {
    char userInput[MAX_INPUT_SIZE];

    printf("Enter a 64-bit binary string or a decimal number: ");
    
    if (fgets(userInput, sizeof(userInput), stdin) == NULL) {
        printf("Error getting input\n");
        return 1;
    }

    removeNewline(userInput);

    switch (isDecimalOrDouble(userInput)){
        case 1:
            /* code */
            break;
    
        case 2:
            break;
        default:
            printf("Not an decimal or double, please check Input");
            break;
    }

    return 0;
}