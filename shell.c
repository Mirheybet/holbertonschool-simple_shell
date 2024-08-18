#define PATH "PATH="
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#define MAX_LEN 100
#define PROMPT ">> "
/**
 * execute_command - func for executing command
 * @args: arguments to path
 * @path: path
 */
void execute_commands(char **args, char *path)
{
	pid_t pid;
	int ststaus;


	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(path, args, environ) == -1)
		{
			free(path);
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (wait(&status) == -1)
		{
			free(path);
			perror("wait failed");
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * devide_commands - commands processor func
 * @commands: commands
 * @commands_array: array for all commands
*/
void devide_commands(char* commands, char** commands_array)
{
	char *command;
	int a = 0;

	command = strtok(commands,"\n");
	while (command != NULL)
	{
		commands_array[a] = command;
		command = strtok(NULL, "\n");
		a++;
	}
	commands_array[a] = NULL;
}

/**
 * main - main func to process all functions
 * Return: integer
 */

int main (void){
	char command[MAX_LEN];
	char *commands_array[MAX_LEN];

	while (1)
	{
		write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
		if (fgets(command, MAX_LEN, stdin) == NULL)
		{
			if (feof(stdin))
				break;
			perror("Error reading command");
			continue;
		}
		
		command[strcspn(command, "\n")] = '\0';
		devide_commands(command, commands_array);
	}
	return (0);
}
