#define PATH "PATH="
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


int main (void){
	char command[MAX_LEN];

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
	}
	return (0);
}
int main_helper (void){
    int status;
    char *args[2];

    args[0] = "/bin/ls";
    args[1] = NULL;

    if ( fork() == 0 )
        execv( args[0], args );
    else
        wait( &status );

    return 0;
}
