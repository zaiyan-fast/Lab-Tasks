#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
};

struct Instructor {
    int id;
    char name[50];
};

struct Course {
    int code;
    char title[50];
    struct Instructor instructor;
    struct Student students[20];
    int studentCount;
};

struct Department {
    char name[50];
    struct Course courses[5];
    int courseCount;
};

void addDepartment(struct Department *departments, int *departmentCount) {
    struct Department newDept;
    printf("Enter department name: ");
    scanf(" %s", newDept.name);
    newDept.courseCount = 0;
    departments[*departmentCount] = newDept;
    (*departmentCount)++;
    printf("Department added successfully!\n");
}

void addCourse(struct Department *department) {
    struct Course newCourse;
    printf("Enter course code: ");
    scanf("%d", &newCourse.code);  
    printf("Enter course title: ");
    scanf(" %s", newCourse.title);
    printf("Enter instructor ID: ");
    scanf("%d", &newCourse.instructor.id);
    printf("Enter instructor name: ");
    scanf(" %s", newCourse.instructor.name);
    newCourse.studentCount = 0;
    department->courses[department->courseCount] = newCourse;
    department->courseCount++;
    printf("Course added\n");
}

void addStudent(struct Course *course) {
    struct Student newStudent;
    printf("Enter student ID: ");
    scanf("%d", &newStudent.id);
    printf("Enter student name: ");
    scanf(" %s", newStudent.name);
    course->students[course->studentCount] = newStudent;
    course->studentCount++;
    printf("Student added!\n");
}

void displayDepartments(struct Department *departments, int departmentCount) {
    for (int i = 0; i < departmentCount; i++) {
        struct Department dept = departments[i];
        printf("\nDepartment: %s\n", dept.name);
        for (int j = 0; j < dept.courseCount; j++) {
            struct Course course = dept.courses[j];
            printf("Course Code: %d , Title: %s , Instructor: %s\n",
                   course.code, course.title, course.instructor.name);
            for (int k = 0; k < course.studentCount; k++) {
                struct Student student = course.students[k];
                printf("Student ID: %d , Name: %s\n", student.id, student.name);
            }
        }
    }
}

int main() {
    struct Department departments[10];
    int departmentCount = 0;
    int choice;

    do {
        printf("\n--- University Management System ---\n");
        printf("1. Add Department\n");
        printf("2. Add Course to a Department\n");
        printf("3. Add Student to a Course\n");
        printf("4. Display Departments and Courses\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addDepartment(departments, &departmentCount);
                break;
            case 2:
                if (departmentCount > 0) {
                    int deptIndex;
                    printf("Enter department index: ");
                    scanf("%d", &deptIndex);
                    if (deptIndex >= 0 && deptIndex < departmentCount) {
                        addCourse(&departments[deptIndex]);
                    } else {
                        printf("Invalid index\n");
                    }
                } else {
                    printf("No departments available\n");
                }
                break;
            case 3:
                if (departmentCount > 0) {
                    int deptIndex, courseIndex;
                    printf("Enter department index: ");
                    scanf("%d", &deptIndex);
                    if (deptIndex >= 0 && deptIndex < departmentCount) {
                        printf("Enter course index: ");
                        scanf("%d", &courseIndex);
                        if (courseIndex >= 0 && courseIndex < departments[deptIndex].courseCount) {
                            addStudent(&departments[deptIndex].courses[courseIndex]);
                        } else {
                            printf("Invalid index\n");
                        }
                    } else {
                        printf("Invalid department index\n");
                    }
                } else {
                    printf("No departments available\n");
                }
                break;
            case 4:
                displayDepartments(departments, departmentCount);
                break;
            case 0:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);
    return 0;
}