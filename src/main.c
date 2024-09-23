#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"
#define MAX_INPUT_SIZE 256


int main (){
    List *historyList = init_history();
    char input[MAX_INPUT_SIZE];

    printf("Press 0 to exit code. ");
    while (1) {
        // Display prompt indicator
        printf("> ");
        if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
            break;
        }

        // Remove newline character from the input
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        // Check if the input is to recall history (!id)
        if (input[0] == '!' && strlen(input) > 1) {
            int id = atoi(input + 1);
            char *historyEntry = get_history(historyList, id);
            if (historyEntry != NULL) {
                printf("Recalled: %s\n", historyEntry);
            } else {
                printf("No history entry found for id %d.\n", id);
            }
        }
        // Check if the input is "history" to print all history entries
        else if (strcmp(input, "history") == 0) {
            print_history(historyList);
        }
        else if (strcmp(input, "0") == 0) {
            break;
        }
        // Otherwise, add the input to history
        else {
            add_history(historyList, input);
        }
    }

    // Free the allocated memory
    free_history(historyList);
    return 0;
}