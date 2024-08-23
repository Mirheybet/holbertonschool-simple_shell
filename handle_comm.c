#include "main.h"

/**
 * handle_commands_array - for handle
 * @commands_array: for commands
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
	{
		while (commands_array[a] != NULL)
		{
			command = commands_array[a];
			if (strcmp(command, "exit") == 0 && a > 0)
				exit(2);
			handle_command(command);
			a++;
		}
	}
}
