/*
** EPITECH PROJECT, 2023
** Solo
** File description:
** init_quizz
*/

#ifndef INIT_QUIZZ_H_
    #define INIT_QUIZZ_H_
    #include "struct.h"
quizz_t *add_question(char *buffer, quizz_t *quizz, int u, int i);
quizz_t *add_answer(char *buffer, quizz_t *quizz, int u, int i, int q);
quizz_t *look_if_real_answer(char *buffer, quizz_t *quizz, int u, int i, int q);
void fill_questions(char *buffer, quizz_t *quizz);
quizz_t *look_nb_question(char *buffer, quizz_t *quizz);
void check_valid_file(struct stat *file_stat, char *path, quizz_t *quizz);

#endif /* !INIT_QUIZZ_H_ */
