#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;


void initialize(Stack *s)
{
    s->top = -1;
}

int isFull(Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack overflow.\n");
    } else {
        s->top++;
        s->items[s->top] = value;
    }
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow.\n");
        return -1;
    } else {
        int value = s->items[s->top];
        s->top--;
        return value;
    }
}

void display(Stack *s)
{
    int i;
    printf("Stack: ");
    for (i = 0; i <= s->top; i++)
    {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main()
{
    FILE *file = fopen("random_numbers.txt", "w");
    if (file == NULL)
    {
        printf("Failed to open the file.\n");
        return 1;
    }
    FILE *outputFile = fopen("Untitled.txt", "w");
    if (outputFile == NULL) {
        printf("Failed to open the output file.\n");
        return 1;
    }
    srand(time(NULL));
    Stack stack;
    initialize(&stack);
    int i;
    for (i = 0; i < 5; i++)
    {
        int random_number = rand();
        fprintf(file, "%d\n", random_number);
        push(&stack, random_number);
    }
    while (!isEmpty(&stack))
    {
        int number = pop(&stack);
        fprintf(outputFile, "%d\n", number);
    }



    fclose(file);
    fclose(outputFile);

    printf("Random numbers are stored in the file 'random_numbers.txt'.\n");
    printf("Random numbers from stack are stored in the file 'output.txt'.\n");
}
