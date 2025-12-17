//Agustin Tapia

#include <iostream>
#include <algorithm> // for next_permutation

using namespace std;

int main() {
    // City names
    string cities[4] = { "Riverside", "Moreno Valley", "Perris", "Hemet" };

    // Distance between cities
    int distance[4][4] = {
        {0, 10, 20, 30},
        {10, 0, 15, 25},
        {20, 15, 0, 18},
        {30, 25, 18, 0}
    };

    // Cost between cities
    int cost[4][4] = {
        {0, 5, 8, 12},
        {5, 0, 4, 9},
        {8, 4, 0, 6},
        {12, 9, 6, 0}
    };

    // Permutation array for destination cities (1,2,3)
    int dest[3] = { 1, 2, 3 };

    int minDistance = 9999;
    int minCost = 9999;
    int bestDistanceRoute[4];
    int bestCostRoute[4];

    cout << "All possible travel routes:\n\n";

    // Generate permutations
    do {
        int route[4] = { 0, dest[0], dest[1], dest[2] }; // Start from Riverside
        int totalDistance = 0;
        int totalCost = 0;

        // Calculate total distance and cost
        for (int i = 0; i < 3; i++) {
            totalDistance += distance[route[i]][route[i + 1]];
            totalCost += cost[route[i]][route[i + 1]];
        }

        // Display route
        for (int i = 0; i < 4; i++) {
            cout << cities[route[i]];
            if (i != 3) cout << " -> ";
        }
        cout << "  Distance: " << totalDistance << "  Cost: $" << totalCost << endl;

        // Check for shortest distance
        if (totalDistance < minDistance) {
            minDistance = totalDistance;
            for (int i = 0; i < 4; i++) bestDistanceRoute[i] = route[i];
        }

        // Check for lowest cost
        if (totalCost < minCost) {
            minCost = totalCost;
            for (int i = 0; i < 4; i++) bestCostRoute[i] = route[i];
        }

    } while (next_permutation(dest, dest + 3));

    // Display shortest distance route
    cout << "\nShortest Distance Route:\n";
    for (int i = 0; i < 4; i++) {
        cout << cities[bestDistanceRoute[i]];
        if (i != 3) cout << " -> ";
    }
    cout << "  Distance: " << minDistance << endl;

    // Display lowest cost route
    cout << "\nLowest Cost Route:\n";
    for (int i = 0; i < 4; i++) {
        cout << cities[bestCostRoute[i]];
        if (i != 3) cout << " -> ";
    }
    cout << "  Cost: $" << minCost << endl;

    return 0;
}
