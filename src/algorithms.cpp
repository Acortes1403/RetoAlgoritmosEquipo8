//
// Created by Amhed on 30/11/2024.
//

// algorithms.cpp
#include "algorithms.h"
#include <vector>
#include <limits>
#include <algorithm>
#include <numeric> // Para std::iota

// Función para resolver el problema del vendedor viajero (TSP)
std::pair<std::vector<int>, int> travelingSalesman(int n, const std::vector<std::vector<int>>& graph) {
    std::vector<int> cities(n);
    std::iota(cities.begin(), cities.end(), 0);

    std::vector<int> bestRoute;
    int minDistance = std::numeric_limits<int>::max();

    do {
        int currentDistance = 0;
        for (int i = 0; i < n - 1; i++) {
            currentDistance += graph[cities[i]][cities[i + 1]];
        }
        currentDistance += graph[cities[n - 1]][cities[0]];

        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            bestRoute = cities;
        }
    } while (std::next_permutation(cities.begin(), cities.end()));

    return {bestRoute, minDistance};
}

