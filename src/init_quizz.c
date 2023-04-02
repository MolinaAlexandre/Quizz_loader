#include <errno.h>
#include <stdio.h>
#include "help.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include "struct.h"
#include <sys/stat.h>

quizz_t *add_question(char *buffer, quizz_t *quizz, int u, int i)
{
    int a = 0;
    int w = i;
    for (i; buffer[i] != ':'; i++){
        a++;
    }
    char *question = malloc(sizeof(char) * a + 1);
    for (int j = 0; w < i ; j++){
        question[j] = buffer[w];
        w++;
    }
    quizz->question[u].name_of_question = question;
    question = NULL;
    return quizz;
}

quizz_t *add_answer(char *buffer, quizz_t *quizz, int u, int i, int q)
{
    int a = 0;
    int w = i;
    for (i; buffer[i] != '\n'; i++){
        a++;
    }
    char *answer = malloc(sizeof(char) * a + 1);
    for (int j = 0; w < i ; j++){
        answer[j] = buffer[w];
        w++;
    }
    quizz->question[u].answer[q] = answer;
    answer = NULL;
    return quizz;
}

quizz_t *look_if_real_answer(char *buffer, quizz_t *quizz, int u, int i, int q)
{
    i += 3;
    if (buffer[i] == 'x'){
        quizz->question[u].real_answer = q;
    }
    return quizz;
}

void fill_questions(char *buffer, quizz_t *quizz)
{
    int u = 0;
    int q = 0;
    for (int i = 0; buffer[i] != '\0'; i++){
        if (buffer[i] == '#'){
            i += 5;
            add_question(buffer, quizz, u, i);
            u++;
            q = 0;
        }
        if (buffer[i] == '-' && buffer[i - 1] == '\n'){
            quizz = look_if_real_answer(buffer, quizz, u - 1, i, q);
            i += 6;
            quizz = add_answer(buffer, quizz, u - 1, i, q);
            q++;
        }
    }
}

quizz_t *look_nb_question(char *buffer, quizz_t *quizz)
{
    char num[3];
    int nb;
    for (int i = 0; buffer[i] != '\n'; i++){
        num[i] = buffer[i];
    }
    nb = atoi(num);
    quizz->question = malloc(sizeof(question_t) * nb);
    quizz->question[0].num_of_question = nb;
    return quizz;
}

void check_valid_file(struct stat *file_stat, char *path, quizz_t *quizz)
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
    quizz = look_nb_question(buf, quizz);
    fill_questions(buf, quizz);
    close(fd);
    free(buf);
}
