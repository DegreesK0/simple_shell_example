#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void parse_and_execute(const char *command);

/**
 * main - Entry point of the shell program.
 *
 * Description: Reads user input, executes commands, and exits on "exit" command.
 *
 * Return: Always returns 0.
 */

int main(void)
{
	char input[BUFFER_SIZE];

	while (1)
	{
		// printing the prompt
		printf("$ ");
		// getting input from the user
		fgets(input, BUFFER_SIZE, stdin);
		// getting input from the user
		input[strlen(input) - 1] = '\0';

		// Creating an exception for the input "exit"
		if (strncmp(input, "exit", 4) == 0)
		{
			printf("Exiting the shell...\n");
			break;
		}
	}

	return (0);
}
