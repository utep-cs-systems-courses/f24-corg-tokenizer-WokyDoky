#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAX_INPUT_SIZE 256

int main(){
    pruebas();
	puts("Commands => h for history | #num for specific history | q for quit");
		
	List *list = init_history();
	char input[MAX_INPUT_SIZE];
	char count = 0;
	while(1){
		fputs("\n>", stdout);
		fflush(stdout);
		char count_in = count;

		char curr_char = getchar();

		while(curr_char == '\n');
		while(curr_char != '\n'){
			input[count] = curr_char;
			curr_char = getchar();
			count++;
		}
		
		if (input[count_in] == 'h' && (count-count_in) == 1){
			printf("Printing full History: \n");
			print_history(list);			
		}else if (input[count_in] == '#' && (count-count_in) == 2){
			int num = (int)input[count_in+1] -48;
			printf("Getting item %d from History: \n%d:", num, num);
			char *word = get_history(list, num);
			while (*word != 0){
				putchar(*word);
				word++;
			}
			putchar('\n');
		}else if (input[count_in] == 'q' && (count-count_in) == 1){
			break;
		}else{
			printf("Tokenizing your input: \n");
			char **tokens = tokenize(&input[count_in]);
			print_tokens(tokens);
			add_history(list, &input[count_in]);
		}
		count ++;	
	}

	printf("Have a nice day!\n");

}