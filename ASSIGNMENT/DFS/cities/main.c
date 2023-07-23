#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 100

// Function to perform Depth-First Search (DFS) of the city map
void dfs(int city, int** cityMap, char** cityNames, int* visited, int numCities) {
    printf("%s -> ", cityNames[city]);
    visited[city] = 1;

    for (int i = 0; i < numCities; i++) {
        if (cityMap[city][i] && !visited[i]) {
            dfs(i, cityMap, cityNames, visited, numCities);
        }
    }
}

int main() {
    FILE* fp = fopen("cities.txt", "r");
    if (fp == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    char** cityNames = (char**)malloc(MAX_CITIES * sizeof(char*));
    int cityMap[MAX_CITIES][MAX_CITIES] = {0};
    int visited[MAX_CITIES] = {0};
    int numCities = 0;

    // Read city connections from the file and create an adjacency matrix
    char city1[100], city2[100];
    while (fscanf(fp, "%s %s", city1, city2) == 2) {
        int index1 = -1, index2 = -1;

        for (int i = 0; i < numCities; i++) {
            if (strcmp(cityNames[i], city1) == 0) {
                index1 = i;
            }
            if (strcmp(cityNames[i], city2) == 0) {
                index2 = i;
            }
        }

        if (index1 == -1) {
            cityNames[numCities] = strdup(city1);
            index1 = numCities;
            numCities++;
        }
        if (index2 == -1) {
            cityNames[numCities] = strdup(city2);
            index2 = numCities;
            numCities++;
        }

        cityMap[index1][index2] = 1;
        cityMap[index2][index1] = 1;
    }

    fclose(fp);

    int startCityIndex = -1;
    // Find the index of the starting city (New York in this case)
    for (int i = 0; i < numCities; i++) {
        if (strcmp(cityNames[i], "MUMBAI") == 0) {
            startCityIndex = i;
            break;
        }
    }

    if (startCityIndex == -1)
    {
        printf("Starting city 'MUMBAI' not found in the input file.\n");
        return 1;
    }

    printf("Cities reachable from %s:\n", cityNames[startCityIndex]);
    dfs(startCityIndex, cityMap, cityNames, visited, numCities);

    // Free the allocated memory
    for (int i = 0; i < numCities; i++) {
        free(cityNames[i]);
    }
    free(cityNames);

    return 0;
}
