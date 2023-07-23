#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct task
        {
    char name[100];
    struct Task* left;
    struct Task* right;
};

typedef struct task*TASK;

// Function to create a new task node
TASK createTask(const char* name)
{
    TASK newTask = (TASK)malloc(sizeof(struct task));
    strcpy(newTask->name, name);
    newTask->left = NULL;
    newTask->right = NULL;
    return newTask;
}

// Function to insert a task into the binary search tree
TASK insertTask(TASK root, const char* name)
{
    if (root == NULL) {
        return createTask(name);
    }

    int cmp = strcmp(name, root->name);
    if (cmp < 0) {
        root->left = insertTask(root->left, name);
    } else if (cmp > 0) {
        root->right = insertTask(root->right, name);
    }

    return root;
}

// In-order traversal of the binary search tree
void inOrderTraversal(TASK root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%s\n", root->name);
        inOrderTraversal(root->right);
    }
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL)
    {
        printf("Failed to open the file.\n");
        exit(0);
    }

    TASK root = NULL;
    char taskName[100];

    // Read tasks from the file and insert into the binary search tree
    while (fscanf(file, "%99[^\n]%*c", taskName) == 1) {
        root = insertTask(root, taskName);
    }

    fclose(file);

    printf("Tasks in alphabetical order:\n");
    inOrderTraversal(root);

    return 0;
}
