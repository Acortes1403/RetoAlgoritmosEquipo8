//
// Created by Amhed on 30/11/2024.
//

// utilities.cpp
#include "utilities.h"
#include <cmath>
#include <sstream>
#include <iostream>
#include <limits>

// Función para leer una coordenada en formato "(x, y)"
void readPoint(Point& p) {
    std::string input;
    std::cin >> input;  // Leer la entrada en formato "(x, y)"
    input = input.substr(1, input.size() - 2);  // Eliminar los paréntesis
    std::stringstream ss(input);  // Crear un stringstream con el contenido
    char comma;  // Para leer la coma
    ss >> p.x >> comma >> p.y;  // Leer las coordenadas x y separadas por la coma
}

// Función para calcular la distancia entre dos puntos
double calculateDistance(const Point& p1, const Point& p2) {
    double dx = (p1.x - p2.x);
    double dy = (p1.y - p2.y);
    return std::sqrt(dx * dx + dy * dy);
}

// Función para encontrar la central más cercana
int findNearestCentral(const Point& newHouse, const std::vector<Point>& centrals) {
    int nearest = -1;
    double minDistance = std::numeric_limits<double>::max(); // Valor inicial de distancia muy grande

    for (size_t i = 0; i < centrals.size(); i++) {
        double distance = calculateDistance(newHouse, centrals[i]);
        if (distance < minDistance) {
            minDistance = distance;
            nearest = static_cast<int>(i);
        }
    }

    return nearest;
}


