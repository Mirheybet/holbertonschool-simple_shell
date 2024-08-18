#ifndef MAINH
#define MAINH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>

#define MAX_LEN 100
#define PROMPT ">> "
#define PATH "PATH="
extern char **environ;
void execute_command(char **args, char *path);
void devide_commands(char* commands, char** commands_array);
#endif
