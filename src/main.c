#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAX 300


int main (){
    char str[] = "   The cake is a lie";
    
    char *token = token_start(str);
    
    if (token) {
        printf("The first token starts with: '%c'\n", *token);
        printf("The first token is: \"%s\"\n", token);
    } else {
        printf("No tokens found.\n");
    }

    printf("===================== \n");

    char *original = "Hello, world!";
    short len = 5;

    char *copiedStr = copy_str(original, len);
    
    if (copiedStr != NULL) {
        printf("Original string: %s\n", original);
        printf("Copied string: %s\n", copiedStr);
        free(copiedStr); // Free the allocated memory
    } else {
        printf("String copy failed.\n");
    }
    return 0;
}