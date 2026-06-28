/* Write a program to Create marksheet generation system */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50

typedef struct {
    char name[MAX_NAME];
    int max_marks;
    int pass_marks;
    int obtained_marks;
} Subject;

typedef struct {
    char name[MAX_NAME];
    int roll_no;
    int total_subjects;
    Subject *subjects;
    int grand_total_max;
    int grand_total_obtained;
    float percentage;
    char grade[3];
    int is_passed; 
} Marksheet;

void calculate_results(Marksheet *ms);
void generate_display(const Marksheet *ms);
void clean_memory(Marksheet *ms);

int main() {
    Marksheet student;
    printf("=============================================\n");
    printf("      MARKSHEET GENERATION SYSTEM IN C      \n");
    printf("=============================================\n\n");
    printf("Enter Student Full Name: ");
    fgets(student.name, sizeof(student.name), stdin);
    student.name[strcspn(student.name, "\n")] = '\0'; 
    printf("Enter Roll Number: ");
    if (scanf("%d", &student.roll_no) != 1) {
        printf("Error: Invalid Roll Number entered.\n");
        return 1;
    }
    printf("Enter Total Number of Subjects: ");
    if (scanf("%d", &student.total_subjects) != 1 || student.total_subjects <= 0) {
        printf("Error: Subject count must be a positive integer.\n");
        return 1;
    }
    student.subjects = (Subject *)malloc(student.total_subjects * sizeof(Subject));
    if (student.subjects == NULL) {
        printf("Error: System failed to allocate memory.\n");
        return 1;
    }
    student.grand_total_max = 0;
    student.grand_total_obtained = 0;
    student.is_passed = 1;
    for (int i = 0; i < student.total_subjects; i++) {
        getchar(); 
        printf("\n--- Entry Detail for Subject [%d] ---\n", i + 1);
        printf("Subject Name: ");
        fgets(student.subjects[i].name, sizeof(student.subjects[i].name), stdin);
        student.subjects[i].name[strcspn(student.subjects[i].name, "\n")] = '\0';
        printf("Maximum Marks allowed: ");
        scanf("%d", &student.subjects[i].max_marks);
        printf("Minimum Passing Marks required: ");
        scanf("%d", &student.subjects[i].pass_marks);
        do {
            printf("Obtained Marks: ");
            scanf("%d", &student.subjects[i].obtained_marks);
            if (student.subjects[i].obtained_marks < 0 || student.subjects[i].obtained_marks > student.subjects[i].max_marks) {
                printf("Error: Obtained marks must lie between 0 and %d. Re-enter:\n", student.subjects[i].max_marks);
            }
        } while (student.subjects[i].obtained_marks < 0 || student.subjects[i].obtained_marks > student.subjects[i].max_marks);
        student.grand_total_max += student.subjects[i].max_marks;
        student.grand_total_obtained += student.subjects[i].obtained_marks;
        if (student.subjects[i].obtained_marks < student.subjects[i].pass_marks) {
            student.is_passed = 0;
        }
    }
    calculate_results(&student);
    generate_display(&student);
    clean_memory(&student);
    return 0;
}

void calculate_results(Marksheet *ms) {
    if (ms->grand_total_max > 0) {
        ms->percentage = ((float)ms->grand_total_obtained / ms->grand_total_max) * 100.0;
    } else {
        ms->percentage = 0.0;
    }
    if (ms->percentage >= 90.0) strcpy(ms->grade, "A+");
    else if (ms->percentage >= 80.0) strcpy(ms->grade, "A");
    else if (ms->percentage >= 70.0) strcpy(ms->grade, "B");
    else if (ms->percentage >= 60.0) strcpy(ms->grade, "C");
    else if (ms->percentage >= 50.0) strcpy(ms->grade, "D");
    else if (ms->percentage >= 40.0) strcpy(ms->grade, "E");
    else strcpy(ms->grade, "F");
}

void generate_display(const Marksheet *ms) {
    printf("\n\n");
    printf("#################################################################\n");
    printf("#                    ACADEMIC PERFORMANCE REPORT                #\n");
    printf("#################################################################\n");
    printf("  Student Name: %-25s Roll Number: %-10d\n", ms->name, ms->roll_no);
    printf("-----------------------------------------------------------------\n");
    printf("  %-20s %-12s %-12s %-12s\n", "SUBJECT", "MAX MARKS", "PASS MARKS", "OBTAINED");
    printf("-----------------------------------------------------------------\n");
    for (int i = 0; i < ms->total_subjects; i++) {
        printf("  %-20s %-12d %-12d %-12d", 
               ms->subjects[i].name, 
               ms->subjects[i].max_marks, 
               ms->subjects[i].pass_marks, 
               ms->subjects[i].obtained_marks);
        
        if (ms->subjects[i].obtained_marks < ms->subjects[i].pass_marks) {
            printf(" [!] Failed");
        }
        printf("\n");
    }
    printf("-----------------------------------------------------------------\n");
    printf("  %-20s %-12d %-12s %-12d\n", "AGGREGATE METRICS", ms->grand_total_max, "", ms->grand_total_obtained);
    printf("-----------------------------------------------------------------\n");
    printf("  Percentage Secured: %.2f%%\n", ms->percentage);
    printf("  Assigned Grade     : %s\n", ms->grade);
    printf("  Final Outcome      : %s\n", (ms->is_passed) ? "PASSED" : "FAILED (Unmet subject baseline)");
    printf("#################################################################\n");
}

void clean_memory(Marksheet *ms) {
    if (ms->subjects != NULL) {
        free(ms->subjects);
        ms->subjects = NULL;
    }
}
