#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 11 // Prime number representing the size of the hash table
#define MAX_NAME_LENGTH 50

typedef struct PhonebookEntry {
    long long int phone_number;
    char name[MAX_NAME_LENGTH];
} PhonebookEntry;

int hash_function(long long int key) {
    return key % TABLE_SIZE;
}

int quadratic_probe(int index, int i) {
    return (index + i * i) % TABLE_SIZE;
}

int main() {
    FILE* fp = fopen("phonebook.txt", "r");
    if (fp == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    PhonebookEntry hash_table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i].phone_number = -1; // Set all phone numbers to -1 to indicate an empty slot
    }

    long long int phone_number;
    char name[MAX_NAME_LENGTH];

    while (fscanf(fp, "%lld %s", &phone_number, name) == 2) {
        int index = hash_function(phone_number);
        int i = 0;

        // Quadratic probing to handle collisions
        while (hash_table[quadratic_probe(index, i)].phone_number != -1) {
            i++;
        }

        hash_table[quadratic_probe(index, i)].phone_number = phone_number;
        strcpy(hash_table[quadratic_probe(index, i)].name, name);
    }

    fclose(fp);

    long long int search_phone_number;
    while (1) {
        printf("Enter Phone Number to search (or -1 to exit): ");
        scanf("%lld", &search_phone_number);

        if (search_phone_number == -1) {
            break;
        }

        int index = hash_function(search_phone_number);
        int i = 0;

        // Quadratic probing to find the user with the given phone number
        while (hash_table[quadratic_probe(index, i)].phone_number != search_phone_number) {
            if (hash_table[quadratic_probe(index, i)].phone_number == -1) {
                printf("Phone Number %lld not found.\n", search_phone_number);
                break;
            }
            i++;
        }

        if (hash_table[quadratic_probe(index, i)].phone_number == search_phone_number) {
            printf("Phone Number: %lld\nName: %s\n", search_phone_number, hash_table[quadratic_probe(index, i)].name);
        }
    }

    return 0;
}
