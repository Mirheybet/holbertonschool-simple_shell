#include "main.h"
#define MAX_LEN 100

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
		if (wait(&ststaus) == -1)
		{
			free(path);
			perror("wait failed");
			exit(EXIT_FAILURE);
		}
	}
}
/**
 * entry_command - func for parsing command
 * @u_command: command to be parsed
 * @args: arguments to command
*/
void entry_command(char *u_command, char **args)
{
	char *command = strtok(u_command, " \t");
	int i = 0;

	args[0] = NULL;
	while (command != NULL && i < MAX_LEN - 1)
	{
		args[i] = command;
		i++;
		command = strtok(NULL, "\t");
	}
	args[i] = NULL;
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
 * handle_commands_array - func for handling array of commands
 * @commands_array: array of commands
 */
void handle_commands_array(char **commands_array)
{
	int a = 0;
	char *command;
	if (strcmp(commands_array[a], "exit") == 0)
		exit(0);
	else if (strcmp(commands_array[a], "env") == 0)
		print_env();
	else
		while (commands_array[a] != NULL)
		{
			command = commands_array[a];
			if (strcmp(command, "exit") == 0 && a > 0)
				exit(2);
			handle_commands_array(commands_array);
			a++;
		}
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
