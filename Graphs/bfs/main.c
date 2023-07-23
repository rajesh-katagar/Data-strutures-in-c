#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

struct Queue
{
    int items[SIZE];
    int front;
    int rear;
};

struct Queue* createQueue();
void enqueue(struct Queue* q, int value);
int dequeue(struct Queue* q);
int isEmpty(struct Queue* q);

void bfs(int graph[][SIZE], int numVertices, int startVertex);

// Create a queue
struct Queue* createQueue()
{
    struct Queue* q = malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Adding elements into the queue
void enqueue(struct Queue* q, int value)
{
    if (q->rear == SIZE - 1)
        printf("\nQueue is full!");
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Removing elements from the queue
int dequeue(struct Queue* q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!");
        return -1;
    }

    int item = q->items[q->front];
    q->front++;

    if (q->front > q->rear)
        q->front = q->rear = -1;

    return item;
}

// Check if the queue is empty
int isEmpty(struct Queue* q)
{
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

// BFS traversal
void bfs(int graph[][SIZE], int numVertices, int startVertex)
{
    struct Queue* q = createQueue();
    int visited[SIZE] = { 0 };

    visited[startVertex] = 1;
    enqueue(q, startVertex);

    printf("BFS Traversal: ");

    while (!isEmpty(q))
    {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        for (int i = 0; i < numVertices; i++)
        {
            if (graph[currentVertex][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
    printf("\n");
}

int main()
{
    int numVertices = 6;
    int graph[SIZE][SIZE] = {
        { 0, 1, 0, 0, 0, 1 },
        { 1, 0, 1, 0, 0, 0 },
        { 1, 0, 0, 1, 0, 0 },
        { 0, 0, 1, 0, 1, 0 },
        { 0, 0, 0, 1, 0, 1 },
        { 1, 0, 0, 0, 1, 0 }
    };

    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    bfs(graph, numVertices, startVertex);

    return 0;
}
































