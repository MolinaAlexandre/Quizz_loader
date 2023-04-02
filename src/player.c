#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void clear_screen(char **env)
{
    pid_t pid;
    int status;
    pid = fork();
    if (pid == 0) {
        execve("/bin/clear", NULL, env);
    } else {
        waitpid(pid, &status, 0);
    }
}

void free_struct(quizz_t *quizz)
{
    for (int i = 0; i < quizz->question[0].num_of_question; i++){
        free(quizz->question[i].name_of_question);
    }
}

void player(quizz_t *quizz, char **env)
{
    char *ptr = NULL;
    size_t len;
    int score = 0;
    int u = 0;
    while (u < quizz->question[0].num_of_question){
        printf("%s\n",quizz->question[u].name_of_question);
        for (int i = 0; i < 4; i++){
            printf("%i. %s\n",i + 1, quizz->question[u].answer[i]);
        }
        getline(&ptr, &len, stdin);
        int rep = atoi(ptr);
        if (rep == quizz->question[u].real_answer + 1){
            score += 1;
        }
        u++;
        clear_screen(env);
    }
    free(ptr);
    printf("\n\n\n ///voici votre score final : %i/%i///\n\n\n", score, quizz->question[0].num_of_question);
    printf("score sur 20 : %.2f/20\n", (float)(1.0 *score/ quizz->question[0].num_of_question) * 20);
    free_struct(quizz);
    exit(0);
}
