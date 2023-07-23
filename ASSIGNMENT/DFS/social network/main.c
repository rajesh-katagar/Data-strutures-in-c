#include <stdio.h>
#include <stdlib.h>

#define MAX_USERS 100

// Function to perform Depth-First Search (DFS) of the network
void dfs(int user, int network[MAX_USERS][MAX_USERS], int visited[MAX_USERS]) {
    printf("%d -> ", user);
    visited[user] = 1;

    for (int i = 1; i < MAX_USERS; i++) {
        if (network[user][i] && !visited[i]) {
            dfs(i, network, visited);
        }
    }
}

int main() {
    FILE* fp = fopen("network.txt", "r");
    if (fp == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    int user1, user2;
    int network[MAX_USERS][MAX_USERS] = {0};
    int visited[MAX_USERS] = {0};

    // Read user connections from the file and create an adjacency matrix
    while (fscanf(fp, "%d %d", &user1, &user2) == 2) {
        network[user1][user2] = 1;
        network[user2][user1] = 1;
    }

    fclose(fp);

    int user = 1; // User ID to find friends for (Change as per requirement)

    printf("Friends of User %d:\n", user);
    dfs(user, network, visited);

    return 0;
}
