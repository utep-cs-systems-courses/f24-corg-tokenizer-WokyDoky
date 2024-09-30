#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tokenizer.h"


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
    return (c == ' ' || c == '\t') ? 1 : 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
    return (c == ' ' || c == '\t' || c == '\0') ? 0 : 1;
}

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str){
    if (str == NULL) return NULL;

    while (space_char(*str)) *str++;
    if (*str == '\0') return NULL;

    return str; 
} 

/* Returns a pointer terminator char following *token */
// Regresa justo el punto despues de token eop \0 
char *token_terminator(char *token){
    if (token == NULL || *token == '\0') return NULL;

    return token + strlen(token);
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str){
    if (str == NULL) return 0;

    while (space_char(*str)) *str++;
    if (*str == '\0') return 0;

    //Found token
    while (non_space_char(*str)) *str++;
    return 1 + count_tokens(str);
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
    //No Empty Strings
    if (len < 0 || inStr == NULL) return NULL;

    // Just in case. 
    short inStr_len = strlen(inStr);
    if (len > inStr_len) len = inStr_len;

    /*
    The malloc() function allocates size bytes and returns a pointer to the
       allocated memory.  The memory is not initialized.  If size is  0,  then
       malloc()  returns either NULL, or a unique pointer value that can later
       be successfully passed to free().

    Malloc is used for dynamic memory allocation or when you need to allocate 
        objects that must exist beyond the lifetime of execution of the current block
    */
    char *newStr = (char *)malloc((len + 1) * sizeof(char));

    //Can I use other methods? 
    strncpy(newStr, inStr, len);
    newStr[len] = '\0'; // Null-terminate the new string

    return newStr;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string"
     tokens[3] = 0
*/
char **tokenize(char* str){
    // Double *asterisks mean func returns pointer to a pointer
    // We have lost the plot.
    // Puedes pensarlos un poco como arrays. Son cubetas donde 
    //  C dedice alocar memoria. 
    //  Ejemplo: [][][], donde cada espacio es un pointer. 
    // De la misma manera, un char* funciona muy similar a una string. 

    //Checks. 
    if (str == NULL) return NULL;
    int token_count = count_tokens(str);
    if (token_count == 0) return NULL;

    char **tokens = (char **)malloc((token_count + 1) * sizeof(char *));

    //Extract and copy each token
    // We start at memory pos. 
    char *current_pos = str;
    for (int i = 0; i < token_count; i++) {
        char *start = token_start(current_pos);
        if (start == NULL) break;

        // Find the end of the current token
        char *end = start;
        while (non_space_char(*end)) {
            end++;
        }

        // Calculate the length of the current token
        int len = end - start;

        // Copy the token into freshly allocated memory
        tokens[i] = copy_str(start, len);

        // Move the current position pointer past this token
        current_pos = end;
    }

    // Step 4: Null-terminate the array of strings
    tokens[token_count] = NULL;

    return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
    printf("===\n");
    for (int i = 0; tokens[i] != NULL; i++) {
        printf("Token[%d]: %s\n", i, tokens[i]);
    }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
    for (int i = 0; tokens[i] != NULL; i++) {
        free(tokens[i]);
    }
    free(tokens);
}