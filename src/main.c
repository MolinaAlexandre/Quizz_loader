#include "help.h"
#include <sys/stat.h>
#include "player.h"
#include "error_handling.h"
#include "init_quizz.h"

int main(int ac, char *av[], char **env)
{
    error_handling(ac, av);
    struct stat file_stat;
    quizz_t quizz;
    check_valid_file(&file_stat, av[1], &quizz);
    player(&quizz, env);3
}