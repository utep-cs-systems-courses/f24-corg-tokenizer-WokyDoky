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
    return (c != ' ' && c != '\t' && c != '\0') ? 1 : 0;
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


}

/* Prints all tokens. */
void print_tokens(char **tokens){

}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){

}