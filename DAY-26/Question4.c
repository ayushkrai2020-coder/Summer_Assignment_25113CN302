/* Write a program to Create quiz application */

#include <stdio.h>
#include <ctype.h>

typedef struct {
    char questionText[256];
    char options[4][64];
    char correctAnswer;
} QuizQuestion;

int main() {
    QuizQuestion quiz[3] = {
        {
            "Which programming language is known as the mother of all languages?",
            {"A. Java", "B. Python", "C. C", "D. C++"},
            'C'
        },
        {
            "What is the only even prime number?",
            {"A. 2", "B. 4", "C. 6", "D. 8"},
            'A'
        },
        {
            "Which planet is closest to the Sun?",
            {"A. Earth", "B. Venus", "C. Mars", "D. Mercury"},
            'D'
        }
    };

    int totalQuestions = sizeof(quiz) / sizeof(quiz[0]);
    int score = 0;
    char userAnswer;

    printf("=========================================\n");
    printf("     WELCOME TO THE CONSOLE QUIZ APP     \n");
    printf("=========================================\n\n");

    for (int i = 0; i < totalQuestions; i++) {
        printf("Question %d: %s\n", i + 1, quiz[i].questionText);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", quiz[i].options[j]);
        }
        printf("Your answer (A, B, C, or D): ");
        scanf(" %c", &userAnswer); 
        userAnswer = toupper(userAnswer);
        if (userAnswer == quiz[i].correctAnswer) {
            printf("\n Correct!\n\n");
            score++;
        } else {
            printf("\n Incorrect. The correct answer was %c.\n\n", quiz[i].correctAnswer);
        }
        printf("-----------------------------------------\n");
    }
    printf("\n=========================================\n");
    printf("               QUIZ OVER!                \n");
    printf("=========================================\n");
    printf("Your final score is: %d out of %d\n", score, totalQuestions);
    if (score == totalQuestions) {
        printf("Excellent! Perfect score!\n");
    } else if (score >= totalQuestions / 2) {
        printf("Good job! You passed.\n");
    } else {
        printf("Better luck next time!\n");
    }
    printf("=========================================\n");
    return 0;
}
