//
// Created by Amhed on 30/11/2024.
//

// graph.cpp
#include "graph.h"
#include <algorithm>
#include <queue>
#include <numeric>
#include <limits>

// Función de Kruskal para el Árbol de Expansión Mínima
std::vector<Edge> kruskal(int n, const std::vector<Edge>& edges) {
    std::vector<int> parent(n);
    std::iota(parent.begin(), parent.end(), 0);  // Inicializar Union-Find
    std::vector<int> rank(n, 0);
    std::vector<Edge> mst;

    auto find = [&](int u) {
        while (u != parent[u]) {
            parent[u] = parent[parent[u]];
            u = parent[u];
        }
        return u;
    };

    auto unionSets = [&](int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    };

    std::vector<Edge> sortedEdges = edges;
    std::sort(sortedEdges.begin(), sortedEdges.end());

    for (const auto& edge : sortedEdges) {
        if (find(edge.u) != find(edge.v)) {
            mst.push_back(edge);
            unionSets(edge.u, edge.v);
        }
    }

    return mst;
}

// Algoritmo de Ford-Fulkerson para Flujo Máximo
int fordFulkerson(int n, const std::vector<std::vector<int>>& capacity, int source, int sink) {
    std::vector<std::vector<int>> residual = capacity;
    std::vector<int> parent(n, -1);  // Inicialización explícita de 'parent' con -1
    int maxFlow = 0;

    auto bfs = [&]() {
        std::vector<bool> visited(n, false);
        std::queue<int> q;

        q.push(source);
        visited[source] = true;
        parent[source] = -1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v = 0; v < n; v++) {
                if (visited[v] || residual[u][v] <= 0) continue; // Salida temprana
                parent[v] = u;
                visited[v] = true;
                if (v == sink) return true; // Salida temprana si encontramos el nodo destino
                q.push(v);
            }
        }
        return false;
    };

    while (bfs()) {
        int pathFlow = std::numeric_limits<int>::max();
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = std::min(pathFlow, residual[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residual[u][v] -= pathFlow;
            residual[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

