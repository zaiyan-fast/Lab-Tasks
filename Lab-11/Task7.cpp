#include <stdio.h>
#include <string.h>

struct Course {
    int id;
    char course_name[20];
    char instructor[20];
    int credits;
};

struct Department {
    char dep_name[20];
    struct Course courses[5];
    int course_count;
};

void addDep(struct Department departments[], int *dep_count) {
    printf("Enter Department's Name: ");
    scanf("%s", departments[*dep_count].dep_name);
    departments[*dep_count].course_count = 0;
    (*dep_count)++;
}

void addCourse(struct Department departments[], int dep_count) {
    if (!dep_count) {
        printf("No departments available\n");
        return;
    }

    printf("Enter Department Number to add a course:\n");
    for (int i = 0; i < dep_count; i++) {
        printf("%d. %s\n", i + 1, departments[i].dep_name);
    }

    int index;
    printf("Enter Number: ");
    scanf("%d", &index);
    index--;

    if (index < 0 || index >= dep_count) {
        printf("Invalid department number.\n");
        return;
    }

    struct Department *dept = &departments[index];

    struct Course *course = &dept->courses[dept->course_count];
    printf("Enter Course ID: ");
    scanf("%d", &course->id);
    printf("Enter Course Name: ");
    scanf("%s", course->course_name);
    printf("Enter Instructor's Name: ");
    scanf("%s", course->instructor);
    printf("Enter Credits: ");
    scanf("%d", &course->credits);

    dept->course_count++;
}

void displayDetails(struct Department departments[], int dep_count) {
    if (dep_count == 0) {
        printf("No details to show.\n");
        return;
    }

    printf("\n--- Department Details ---\n");
    for (int i = 0; i < dep_count; i++) {
        printf("Department %d: %s\n", i + 1, departments[i].dep_name);
        printf("Courses:\n");
        for (int j = 0; j < departments[i].course_count; j++) {
            struct Course course = departments[i].courses[j];
            printf("--Course %d: \n   ID=%d, Name=%s, Instructor=%s, Credits=%d\n",
                   j + 1, course.id, course.course_name, course.instructor, course.credits);
        }
        printf("\n");
    }
}

int main() {
    struct Department departments[10];
    int dep_count = 0;
    int opt = 0;

    while(opt != 4) {
        printf("\n--- University Course Enrollment System ---\n");
        printf("1. Add Department\n");
        printf("2. Add Course to a Department\n");
        printf("3. Display Department and Course Details\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                addDep(departments, &dep_count);
                break;
            case 2:
                addCourse(departments, dep_count);
                break;
            case 3:
                displayDetails(departments, dep_count);
                break;
            case 4:
                printf("Closing Program\n");
                break;
            default:
                printf("Invalid number\n");
        }
    };

    return 0;
}
