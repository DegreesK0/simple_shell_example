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

		// function called to execute commands
		parse_and_execute(input);
	}

	return (0);
}


/**
 * parse_and_execute - Parse and execute a given input.
 *
 * @command: The commands to execute.
 *
 * Description: Parses the input into tokenized strings then forks a child 
 * process to execute the command and waits for it to complete.
 */

void parse_and_execute(const char *command)
{
	char *executable;
    int i = 0;
    char *args[64]; // array to hold arguments
    
    // Tokenize the input using space as the delimiter 
    char *token = strtok((char *)command, " ");
    
    // Assign each token a place in the array args
    while (token != NULL)
    {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    // set the item following the last command to NULL, marking the end of arguments
    args[i] = NULL;

    // Execute your command and give an error if it fails
    if (execvp(args[0], args) == -1)
    {
        perror("Command execution failed");
        exit(EXIT_FAILURE);
    }

}
