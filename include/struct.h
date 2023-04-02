#ifndef STRUCT_H_
    #define STRUCT_H_
typedef struct question_s{
    char *name_of_question;
    int num_of_question;
    char *answer[4];
    int real_answer;
}question_t;

typedef struct quizz_s{
    question_t *question;
}quizz_t;


#endif /* !STRUCT_H_ */
