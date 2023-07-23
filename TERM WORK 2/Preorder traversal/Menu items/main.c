#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a menu item or submenu
struct menuitem {
    char name[50];
    struct menuitem* submenus[10]; // Maximum 10 submenus for each menu item
};

typedef struct menuitem* MENU;

// Preorder traversal
void preorderTraversal(MENU menu)
{
    if (menu == NULL)
    {
        return;
    }

    printf("%s\n", menu->name);

    // Recursively traverse the submenus
    for (int i = 0; menu->submenus[i] != NULL; i++) {
        preorderTraversal(menu->submenus[i]);
    }
}

int main() {
    FILE* fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("File does not exist.");
        exit(0);
    }

    MENU menu = (MENU)malloc(sizeof(struct menuitem));
    fscanf(fp, "%s", menu->name); // Taking input from files.

    int numSubmenus;
    fscanf(fp, "%d", &numSubmenus);

    for (int i = 0; i < numSubmenus; i++) {
        struct menuitem* submenu = (struct menuitem*)malloc(sizeof(struct menuitem));

        fscanf(fp, "%s", submenu->name);

        submenu->submenus[0] = NULL;
        menu->submenus[i] = submenu;
    }
    menu->submenus[numSubmenus] = NULL;

    fclose(fp);

    printf("Preorder traversal of the menu hierarchy:\n");
    preorderTraversal(menu);

    for (int i = 0; i < numSubmenus; i++) {
        free(menu->submenus[i]);
    }
    free(menu);

    return 0;
}
