#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct QueueNode {
    int node;
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

void enqueue(Queue* queue, int node) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->node = node;
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

    int node = temp->node;
    free(temp);
    return node;
}

int main() {
    FILE* fp = fopen("power_grid.txt", "r");
    if (fp == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    int numNodes = 0;
    char node1[100], node2[100];
    char nodes[MAX_NODES][100] = {0};
    int adjacencyMatrix[MAX_NODES][MAX_NODES] = {0};

    // Read power grid connections from the file and create an adjacency matrix
    while (fscanf(fp, "%s %s", node1, node2) == 2) {
        int index1 = -1, index2 = -1;

        for (int i = 0; i < numNodes; i++) {
            if (strcmp(nodes[i], node1) == 0) {
                index1 = i;
            }
            if (strcmp(nodes[i], node2) == 0) {
                index2 = i;
            }
        }

        if (index1 == -1) {
            strcpy(nodes[numNodes], node1);
            index1 = numNodes;
            numNodes++;
        }
        if (index2 == -1) {
            strcpy(nodes[numNodes], node2);
            index2 = numNodes;
            numNodes++;
        }

        adjacencyMatrix[index1][index2] = 1;
        adjacencyMatrix[index2][index1] = 1;
    }

    fclose(fp);

    int startNode = 0; // Index of the power station (Change as per requirement)

    int* visited = (int*)malloc(numNodes * sizeof(int));
    int* queue = (int*)malloc(numNodes * sizeof(int));
    int front = 0, rear = 0;
    int linesNeeded = 0;

    for (int i = 0; i < numNodes; i++)
        visited[i] = 0;

    visited[startNode] = 1;
    queue[rear++] = startNode;

    while (front < rear) {
        int node = queue[front++];
        for (int i = 0; i < numNodes; i++) {
            if (adjacencyMatrix[node][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
                linesNeeded++;
            }
        }
    }

    free(visited);
    free(queue);

    printf("Minimum number of power transmission lines needed: %d\n", linesNeeded);

    return 0;
}
