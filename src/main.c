#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAX_INPUT_SIZE 256

int main(){
    printf("===================================================================\n");
	puts("Commands => h for history | #num for specific history | q for quit");
    printf("===================================================================\n");

	List *list = init_history();
	char input[MAX_INPUT_SIZE];
	char count = 0;
	while(1){
		fputs("\n>", stdout);
		fflush(stdout);
		char count_in = count;
		char curr_char = getchar();

		while(curr_char != '\n'){
			input[count] = curr_char;
			curr_char = getchar();
			count++;
		}
		
		if (input[count_in] == 'h' && (count-count_in) == 1){
			printf("Full History: \n");
			print_history(list);			
		}else if (input[count_in] == '#' && (count-count_in) == 2){
			int num = (int)input[count_in+1] -48;
			printf("History[%d]: %s \n", num,  get_history(list, num));
		}else if ((input[count_in] == 'q' || input[count_in] == '0') && (count-count_in) == 1){
			break;
		}else{
			printf("Tokenizing your input: \n");
			char **tokens = tokenize(&input[count_in]);
			print_tokens(tokens);
			add_history(list, &input[count_in]);
            free(tokens);
		}
		count ++;	
	}

	printf("Terminating program...!\n");

}