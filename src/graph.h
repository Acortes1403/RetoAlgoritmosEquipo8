//
// Created by Amhed on 30/11/2024.
//
// graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "utilities.h" // Para la estructura Point

// Estructura para representar una arista
struct Edge {
    int u;
    int v;
    int weight;

    friend bool operator<(const Edge& lhs, const Edge& rhs) {
        return lhs.weight < rhs.weight;
    }
};

// Función de Kruskal para el Árbol de Expansión Mínima
std::vector<Edge> kruskal(int n, const std::vector<Edge>& edges);

// Algoritmo de Ford-Fulkerson para Flujo Máximo
int fordFulkerson(int n, const std::vector<std::vector<int>>& capacity, int source, int sink);

#endif // GRAPH_H