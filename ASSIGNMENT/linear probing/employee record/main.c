#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 11 // Prime number representing the size of the hash table
#define MAX_NAME_LENGTH 50

typedef struct EmployeeRecord {
    int employee_id;
    char employee_name[MAX_NAME_LENGTH];
} EmployeeRecord;

int hash_function(int key) {
    return key % TABLE_SIZE;
}

int linear_probe(int index, int i) {
    return (index + i) % TABLE_SIZE;
}

int main() {
    FILE* fp = fopen("employee_records.txt", "r");
    if (fp == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    EmployeeRecord hash_table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i].employee_id = -1; // Set all employee IDs to -1 to indicate an empty slot
    }

    int employee_id;
    char employee_name[MAX_NAME_LENGTH];

    while (fscanf(fp, "%d %s", &employee_id, employee_name) == 2) {
        int index = hash_function(employee_id);
        int i = 0;

        // Linear probing to handle collisions
        while (hash_table[linear_probe(index, i)].employee_id != -1) {
            i++;
        }

        hash_table[linear_probe(index, i)].employee_id = employee_id;
        strcpy(hash_table[linear_probe(index, i)].employee_name, employee_name);
    }

    fclose(fp);

    int search_id;
    while (1) {
        printf("Enter Employee ID to search (or -1 to exit): ");
        scanf("%d", &search_id);

        if (search_id == -1) {
            break;
        }

        int index = hash_function(search_id);
        int i = 0;

        // Linear probing to find the employee with the given ID
        while (hash_table[linear_probe(index, i)].employee_id != search_id) {
            if (hash_table[linear_probe(index, i)].employee_id == -1) {
                printf("Employee with ID %d not found.\n", search_id);
                break;
            }
            i++;
        }

        if (hash_table[linear_probe(index, i)].employee_id == search_id) {
            printf("Employee with ID %d: %s\n", search_id, hash_table[linear_probe(index, i)].employee_name);
        }
    }

    return 0;
}
