#include <stdio.h>
#include "help.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

static void error_handling(int ac, char *av[])
{
    if (ac != 2){
        display_help();
        exit (84);
    }
    if (ac == 2 && strcmp(av[1], "-h") == 0){
        display_help();
    }
}

static void check_valid_file(struct stat *file_stat, char *path)
{
    int errno;
    int errnum;
    chdir("quizz_sheet");
    int fd = open(path, O_RDONLY);
    errnum = errno;
    if (fd == -1){
        fprintf(stderr, "Error opening file: %s\n", strerror( errnum ));
        exit(84);
    }
    stat(path, file_stat);
    char *buf = malloc(sizeof(char) * file_stat->st_size + 1);
    read(fd, buf, file_stat->st_size);
    buf[file_stat->st_size] = '\0';
    printf("%s\n", buf);
    free(buf);
}

int main(int ac, char *av[])
{
    error_handling(ac, av);
    struct stat file_stat;
    check_valid_file(&file_stat, av[1]);
}