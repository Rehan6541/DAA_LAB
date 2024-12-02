#include <iostream>
#include <climits>
using namespace std;

const int N = 8; // Number of cities

// Distance matrix
int dist[N][N] = {
    {0, 4, 1, 3, 6, 7, 8, 2},
    {4, 0, 5, 2, 7, 6, 3, 4},
    {1, 5, 0, 6, 3, 5, 4, 7},
    {3, 2, 6, 0, 5, 2, 6, 3},
    {6, 7, 3, 5, 0, 4, 2, 6},
    {7, 6, 5, 2, 4, 0, 5, 3},
    {8, 3, 4, 6, 2, 5, 0, 1},
    {2, 4, 7, 3, 6, 3, 1, 0}
};

// Greedy TSP function
void tspGreedy() {
    bool visited[N] = {false}; // Track visited cities
    int totalCost = 0;         // Total travel cost
    int currentCity = 0;       // Start from city 0

    cout << "Path: " << currentCity + 1;

    visited[currentCity] = true;

    for (int i = 1; i < N; i++) {
        int nearestCity = -1;
        int minDist = INT_MAX;

        // Find the nearest unvisited city
        for (int j = 0; j < N; j++) {
            if (!visited[j] && dist[currentCity][j] < minDist) {
                minDist = dist[currentCity][j];
                nearestCity = j;
            }
        }

        visited[nearestCity] = true;
        totalCost += minDist;
        currentCity = nearestCity;

        cout << " -> " << currentCity + 1;
    }

    // Return to the starting city
    totalCost += dist[currentCity][0];
    cout << " -> " << 1 << endl;

    cout << "Total travel cost = " << totalCost << endl;
}

int main() {
    tspGreedy();
    return 0;
}
