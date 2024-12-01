// main.cpp
#include <iostream>
#include <vector>
#include "graph.h"
#include "algorithms.h"
#include "utilities.h"


int main() {
    int n;
    std::cin >> n;

    std::vector graph(n, std::vector<int>(n));
    std::vector capacity(n, std::vector<int>(n));
    std::vector<Point> centrals(n);

    // Leer el grafo con distancias
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> graph[i][j];
        }
    }

    // Leer la matriz de capacidades máximas
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> capacity[i][j];
        }
    }

    // Leer las coordenadas de las centrales
    for (int i = 0; i < n; i++) {
        readPoint(centrals[i]);
        std::cout << "Central " << i << ": (" << centrals[i].x << ", " << centrals[i].y << ")\n";
    }

    // Leer la ubicación de la nueva casa
    Point newHouse;
    readPoint(newHouse);
    std::cout << "Nueva casa: (" << newHouse.x << ", " << newHouse.y << ")\n";

    // Resolver el Árbol de Expansión Mínima (Kruskal)
    std::vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] > 0) {
                edges.push_back({i, j, graph[i][j]});
            }
        }
    }
    std::vector<Edge> mst = kruskal(n, edges);

    std::cout << "\n1.\n";
    for (const auto& edge : mst) {
        std::cout << "(" << char('A' + edge.u) << ", " << char('A' + edge.v) << ")\n";
    }

    // Resolver el problema del vendedor viajero (TSP)
    auto [route, minDistance] = travelingSalesman(n, graph);
    std::cout << "2.\n";
    for (int city : route) {
        std::cout << char('A' + city) << " ";
    }
    std::cout << char('A' + route[0]) << "\n";

    // Resolver el flujo máximo (Ford-Fulkerson)
    int maxFlow = fordFulkerson(n, capacity, 0, n - 1);
    std::cout << "3.\n" << maxFlow << "\n";

    // Encontrar la central más cercana
    int nearestCentral = findNearestCentral(newHouse, centrals);
    std::cout << "4.\n (" << centrals[nearestCentral].x << ", " << centrals[nearestCentral].y << ")\n";

    return 0;
}
