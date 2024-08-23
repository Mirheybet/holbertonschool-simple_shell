#include <stdio.h>




void print_env() {
    extern char **environ;
    for (char **current = environ; *current; ++current) {
        printf("%s\n", *current);
    }
}

