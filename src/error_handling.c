#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "help.h"

void error_handling(int ac, char *av[])
{
    if (ac != 2){
        display_help();
        exit (84);
    }
    if (ac == 2 && strcmp(av[1], "-h") == 0){
        display_help();
    }
}
