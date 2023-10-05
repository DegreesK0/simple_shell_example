#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

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
        // sets last character in array to null character
        input[strlen(input) - 1] = '\0'; 
	}

	return (0);
}