//
// Created by Amhed on 30/11/2024.
//

// utilities.h
#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <vector>

struct Point {
    int x = 0;
    int y = 0;
};

// Función para leer una coordenada en formato "(x, y)"
void readPoint(Point& p);

// Función para calcular la distancia entre dos puntos
double calculateDistance(const Point& p1, const Point& p2);

// Función para encontrar la central más cercana
int findNearestCentral(const Point& newHouse, const std::vector<Point>& centrals);

#endif // UTILITIES_H

