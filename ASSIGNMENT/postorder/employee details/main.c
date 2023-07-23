#include <stdio.h>
#include <stdlib.h>

typedef struct Employee {
    int employeeID;
    int age;
    int salary;
    struct Employee* left;
    struct Employee* right;
} Employee;

// Function to create a new employee node
Employee* createEmployee(int employeeID, int age, int salary)
{
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    newEmployee->employeeID = employeeID;
    newEmployee->age = age;
    newEmployee->salary = salary;
    newEmployee->left = NULL;
    newEmployee->right = NULL;
    return newEmployee;
}

// Function to insert an employee into the binary search tree
Employee* insertEmployee(Employee* root, int employeeID, int age, int salary) {
    if (root == NULL) {
        return createEmployee(employeeID, age, salary);
    }

    if (employeeID < root->employeeID) {
        root->left = insertEmployee(root->left, employeeID, age, salary);
    } else if (employeeID > root->employeeID) {
        root->right = insertEmployee(root->right, employeeID, age, salary);
    }

    return root;
}

// Postorder traversal of the binary search tree
void postOrderTraversal(Employee* root)
{
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("Employee ID: %d, Age: %d, Salary: %d\n", root->employeeID, root->age, root->salary);
    }
}

int main() {
    FILE* fp = fopen("employees.txt", "r");
    if (fp == NULL)
    {
        printf("Failed does not exist.\n");
        return 1;
    }

    Employee* root = NULL;
    int employeeID, age, salary;

    // Read employees from the file and insert into the binary search tree
    while (fscanf(fp, "%d %d %d", &employeeID, &age, &salary) == 3) {
        root = insertEmployee(root, employeeID, age, salary);
    }

    fclose(fp);

    printf("Employees in descending order of Employee ID:\n");
    postOrderTraversal(root);


    return 0;
}
