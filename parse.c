#include <string.h>
#include "main.h"

/**
 * parse_command - for command
 * @u_command: commands
 * @args: arguments
 */

void parse_command(char *u_command, char **args)
{
	char *command = strtok(u_command, " \t");
	int i = 0;

	args[0] = NULL;
	while (command != NULL && i < MAX_LEN - 1)
	{
		args[i] = command;
		i++;
		command = strtok(NULL, " \t");
	}
	args[i] = NULL;
}
