#include <stdio.h>
#include <stdlib.h>
struct student {
    int studentID;
    int age;
    int grade;
    struct Student* left;
    struct Student* right;
};

typedef struct student*STUDENT;

STUDENT createStudent(int studentID, int age, int grade)
{
    STUDENT newStudent = (STUDENT)malloc(sizeof(struct student));
    newStudent->studentID = studentID;
    newStudent->age = age;
    newStudent->grade = grade;
    newStudent->left = NULL;
    newStudent->right = NULL;
    return newStudent;
}

STUDENT insertStudent(STUDENT root, int studentID, int age, int grade)
{
    if (root == NULL) {
        return createStudent(studentID, age, grade);
    }

    if (studentID < root->studentID) {
        root->left = insertStudent(root->left, studentID, age, grade);
    } else if (studentID > root->studentID) {
        root->right = insertStudent(root->right, studentID, age, grade);
    }

    return root;
}

// In-order traversal of the binary search tree
void inOrderTraversal(STUDENT root)
{
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("Student ID: %d, Age: %d, Grade: %d\n", root->studentID, root->age, root->grade);
        inOrderTraversal(root->right);
    }
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL)
    {
        printf("Filed does not exist.\n");
        return 1;
    }

    STUDENT root = NULL;
    int studentID, age, grade;

    // Read students from the file and insert into the binary search tree
    while (fscanf(file, "%d %d %d", &studentID, &age, &grade) == 3) {
        root = insertStudent(root, studentID, age, grade);
    }

    fclose(file);

    printf("Students in ascending order of Student ID:\n");
    inOrderTraversal(root);


    return 0;
}
