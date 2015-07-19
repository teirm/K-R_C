#include <stdio.h>

#define MAX_LENGTH 1000 /* maximum of stack */
#define STRING_START 1 /* start of a string */
#define STRING_END 0  /* end of a string */
#define ESCAPE_START 1 /* end of an escape sequence */
#define ESCAPE_END 0 /* end of an escape sequence */


/* function prototypes */
int push (char stack[], char c, int sc);
int pop (char stack[], int sc);
void error (char stack[], int sc);
int close_search (char stack[], char c, int sc);
void organize_stack (char stack[], int sc, int loc);

/* does some rudimentary syntax checking on a c program given 
   	as input, so much easier to do as ascii codes */

main()
{
	int c, stack_counter, string_state, escape_state;
	char stack[MAX_LENGTH];

	escape_state = 0;	
	string_state = STRING_END;
	stack_counter = 0;
	
	while ((c = getchar()) != EOF) {

		if (string_state == STRING_END) {

			/* parentheses: (, ) */
			
			if (c == 40) {
				stack_counter = push(stack, c, stack_counter);
			}

			if (c == 41) {
				stack_counter = close_search(stack, c, stack_counter);
			}
		
			/* Curly braces: {, }  */

			if (c == 123) {
				stack_counter = push(stack, c, stack_counter);
			}

			if (c == 125) {
				stack_counter = close_search(stack, c, stack_counter);
			}
			
			/* Brackets: [, ] */

			if (c == 91) {
				stack_counter = push(stack, c, stack_counter);
			}

			if (c == 93) {
				stack_counter = close_search(stack, c, stack_counter);
			}
			
			/* Stars: * * */

			if (c == 42) {
				stack_counter = close_search(stack, c, stack_counter);
			}

			/* Forward slash: // */

			if (c == 47) {
				stack_counter = close_search(stack, c, stack_counter);
			}
			
			/* Single quote: ' ' */
			
			if (c == 39) {
				stack_counter = close_search(stack, c, stack_counter);
			}

			/* Opening double quote : " */

			if (c == 34) {
				stack_counter = push(stack, c, stack_counter);
				string_state = STRING_START;	
			}
		}
		else {
			if (c == 34) {
				stack_counter = close_search(stack, c, stack_counter);
				string_state = STRING_END;
			}
			else if (c == 92) {
				stack_counter = close_search(stack, c, stack_counter);
			} 
			else if ((c == 110 || c == 116) && stack[stack_counter] == 92) {
				stack_counter = pop(stack, stack_counter);
			}		
		}
	}		

	error(stack, stack_counter);

	printf("stack counter: %d\n", stack_counter);

}

int close_search(char stack[], char c, int sc)
{
	int i;

	for(i = sc; i >= 0; --i) {
		
		/* parentheses ( ) */
		if (c == 41 && stack[i] == 40) {
			organize_stack(stack, sc, i);
			--sc;
			break;
		}
		/* Curly braces { } */
		else if (c == 125 && stack[i] == 123) {
			organize_stack(stack, sc, i);
			--sc;
			break;
		}
		/* Brackets [ ] */
		else if (c == 93 && stack[i] == 91) {
			organize_stack(stack, sc, i);
			--sc;
			break;
		}
		else if (c == 42 && stack[i] == 42) {
			organize_stack(stack, sc, i);
			--sc;
			break;
		}
		else if (c == 47 && stack[i] == 47) {
			organize_stack(stack, sc, i);
			--sc;
			break;
		}
		else if (c == 39 && stack[i] == 39) {
			organize_stack(stack, sc, i);
			--sc;
			break;
		}
		else if (c == 34 && stack[i] == 34) {
			organize_stack(stack, sc, i);
			--sc;
			break;
		}
		else if (c == 92 && stack[i] == 92) {
			organize_stack(stack, sc, i);
			--sc;
			break;
		}
		else {
			sc = push(stack, c, sc);
			break;	
		}
		
	}
	return sc;
}

void organize_stack(char stack[], int sc, int loc) 
{
	int i;
	printf("Organizing Stack\n");	
	
	if(sc == loc)
	{
		pop(stack, sc);
	}
	
	for(i = loc + 1; i <= sc; ++i) {
		stack[i - 1] = stack[i];
	}
}


int pop (char stack[], int sc)
{
	printf("POPPING %c\n", stack[sc]);	
	--sc;
	return sc;
}

int push (char stack[], char c, int sc)
{
	printf("PUSHING %c\n", c);
	++sc;
	stack[sc] = c;

	return sc;
}

void error (char stack[], int sc)
{
	int i;

	if(sc > 0) {
		for (i = 1; i <= sc; ++i) {
			printf("Mismatched %c\n", stack[i]);
		}
	}
}
