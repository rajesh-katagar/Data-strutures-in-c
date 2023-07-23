#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FORTIFICATIONS 100

typedef struct QueueNode {
    int fortification;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(Queue* queue, int fortification) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->fortification = fortification;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

int dequeue(Queue* queue) {
    if (queue->front == NULL)
        return -1;

    QueueNode* temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    int fortification = temp->fortification;
    free(temp);
    return fortification;
}

int bfs(int startFortification, int** enemyTerritory, int numFortifications) {
    int* visited = (int*)calloc(numFortifications, sizeof(int));
    Queue* queue = createQueue();
    int* parent = (int*)malloc(numFortifications * sizeof(int));
    int* discoveryTime = (int*)malloc(numFortifications * sizeof(int));
    int* minDiscoveryTime = (int*)malloc(numFortifications * sizeof(int));
    int criticalLines = 0;

    for (int i = 0; i < numFortifications; i++) {
        parent[i] = -1;
        discoveryTime[i] = -1;
        minDiscoveryTime[i] = -1;
    }

    visited[startFortification] = 1;
    enqueue(queue, startFortification);
    discoveryTime[startFortification] = minDiscoveryTime[startFortification] = 0;

    while (queue->front != NULL) {
        int currentFortification = dequeue(queue);
        int childrenCount = 0;

        for (int i = 0; i < numFortifications; i++) {
            if (enemyTerritory[currentFortification][i]) {
                if (!visited[i]) {
                    childrenCount++;
                    visited[i] = 1;
                    parent[i] = currentFortification;
                    discoveryTime[i] = minDiscoveryTime[i] = discoveryTime[currentFortification] + 1;
                    enqueue(queue, i);
                } else if (parent[currentFortification] != i) {
                    minDiscoveryTime[currentFortification] =
                            (minDiscoveryTime[currentFortification] != -1) ?
                            (minDiscoveryTime[currentFortification] < discoveryTime[i] ? minDiscoveryTime[currentFortification] : discoveryTime[i]) :
                            discoveryTime[i];
                }
            }
        }

        if (parent[currentFortification] != -1 && minDiscoveryTime[currentFortification] != -1 &&
            minDiscoveryTime[currentFortification] >= discoveryTime[currentFortification]) {
            printf("%d. %s - %s\n", ++criticalLines, fortifications[parent[currentFortification]], fortifications[currentFortification]);
        }
    }

    free(visited);
    free(parent);
    free(discoveryTime);
    free(minDiscoveryTime);
    free(queue);

    return criticalLines;
}

int main() {
    FILE* fp = fopen("enemy_territory.txt", "r");
    if (fp == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    int numFortifications = 0;
    char fortification1[100], fortification2[100];
    char fortifications[MAX_FORTIFICATIONS][100] = {0};
    int enemyTerritory[MAX_FORTIFICATIONS][MAX_FORTIFICATIONS] = {0};

    // Read enemy territory connections from the file and create an adjacency matrix
    while (fscanf(fp, "%s %s", fortification1, fortification2) == 2) {
        int index1 = -1, index2 = -1;

        for (int i = 0; i < numFortifications; i++) {
            if (strcmp(fortifications[i], fortification1) == 0) {
                index1 = i;
            }
            if (strcmp(fortifications[i], fortification2) == 0) {
                index2 = i;
            }
        }

        if (index1 == -1) {
            strcpy(fortifications[numFortifications], fortification1);
            index1 = numFortifications;
            numFortifications++;
        }
        if (index2 == -1) {
            strcpy(fortifications[numFortifications], fortification2);
            index2 = numFortifications;
            numFortifications++;
        }

        enemyTerritory[index1][index2] = 1;
        enemyTerritory[index2][index1] = 1;
    }

    fclose(fp);

    int startFortification = 0; // Index of the starting fortification (Change as per requirement)

    printf("Critical Communication Lines:\n");
    int numCriticalLines = bfs(startFortification, enemyTerritory, numFortifications);
    printf("Number of Critical Communication Lines: %d\n", numCriticalLines);

    return 0;
}
