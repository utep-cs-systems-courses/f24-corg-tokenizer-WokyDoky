#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAX 300


int main (){
    char str[] = "The cake is a lie";
    
    // Tokenize the input string
    char **tokens = tokenize(str);

    // Check if the function returned NULL
    if (tokens == NULL) {
        printf("No tokens found or an error occurred.\n");
        return 1;
    }

    print_tokens(tokens);
    free_tokens(tokens);
    

    return 0;
}