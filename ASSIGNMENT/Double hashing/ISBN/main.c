#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 11 // Prime number representing the size of the hash table
#define PRIME 7 // Another prime number used for double hashing
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_GENRE_LENGTH 50

typedef struct BookRecord {
    long long int isbn;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
} BookRecord;

int hash_function1(long long int key) {
    return key % TABLE_SIZE;
}

int hash_function2(long long int key) {
    return PRIME - (key % PRIME);
}

int double_hashing(int index1, int index2, int i) {
    return (index1 + i * index2) % TABLE_SIZE;
}

int main() {
    FILE* fp = fopen("book_records.txt", "r");
    if (fp == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    BookRecord hash_table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i].isbn = -1; // Set all ISBNs to -1 to indicate an empty slot
    }

    long long int isbn;
    char title[MAX_TITLE_LENGTH], author[MAX_AUTHOR_LENGTH], genre[MAX_GENRE_LENGTH];

    while (fscanf(fp, "%lld %s %s %s", &isbn, title, author, genre) == 4) {
        int index1 = hash_function1(isbn);
        int index2 = hash_function2(isbn);
        int i = 0;

        // Double hashing to handle collisions
        while (hash_table[double_hashing(index1, index2, i)].isbn != -1) {
            i++;
        }

        hash_table[double_hashing(index1, index2, i)].isbn = isbn;
        strcpy(hash_table[double_hashing(index1, index2, i)].title, title);
        strcpy(hash_table[double_hashing(index1, index2, i)].author, author);
        strcpy(hash_table[double_hashing(index1, index2, i)].genre, genre);
    }

    fclose(fp);

    long long int search_isbn;
    while (1) {
        printf("Enter ISBN to search (or -1 to exit): ");
        scanf("%lld", &search_isbn);

        if (search_isbn == -1) {
            break;
        }

        int index1 = hash_function1(search_isbn);
        int index2 = hash_function2(search_isbn);
        int i = 0;

        // Double hashing to find the book with the given ISBN
        while (hash_table[double_hashing(index1, index2, i)].isbn != search_isbn) {
            if (hash_table[double_hashing(index1, index2, i)].isbn == -1) {
                printf("ISBN %lld not found.\n", search_isbn);
                break;
            }
            i++;
        }

        if (hash_table[double_hashing(index1, index2, i)].isbn == search_isbn) {
            printf("ISBN: %lld\nTitle: %s\nAuthor: %s\nGenre: %s\n", search_isbn,
                   hash_table[double_hashing(index1, index2, i)].title,
                   hash_table[double_hashing(index1, index2, i)].author,
                   hash_table[double_hashing(index1, index2, i)].genre);
        }
    }

    return 0;
}
