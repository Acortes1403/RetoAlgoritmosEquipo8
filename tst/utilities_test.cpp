//
// Created by Amhed on 30/11/2024.
//
// utilities_test.cpp
#include <gtest/gtest.h>
#include "utilities.h"
#include <vector>

// Solo tienes las pruebas (TEST) que definiste

TEST(UtilitiesTest, ReadPoint) {
    std::istringstream input("(3,4)");
    std::streambuf* originalCin = std::cin.rdbuf();  // Guardar el buffer original
    std::cin.rdbuf(input.rdbuf());  // Redirigir std::cin

    Point p;
    readPoint(p);  // Llamar a la función que leerá la coordenada

    // Aserciones para verificar el resultado
    EXPECT_EQ(p.x, 3);  // Verificar que x sea 3
    EXPECT_EQ(p.y, 4);  // Verificar que y sea 4

    std::cin.rdbuf(originalCin);  // Restaurar el buffer original de std::cin
}


TEST(UtilitiesTest, CalculateDistance) {
    Point p1 = {0, 0};
    Point p2 = {3, 4};

    double distance = calculateDistance(p1, p2);

    EXPECT_DOUBLE_EQ(distance, 5.0);  // La distancia entre (0, 0) y (3, 4) debe ser 5
}

TEST(UtilitiesTest, FindNearestCentral) {
    std::vector<Point> centrals = {{0, 0}, {5, 5}, {10, 10}};
    Point newHouse = {2, 3};

    int nearestCentral = findNearestCentral(newHouse, centrals);

    EXPECT_EQ(nearestCentral, 0);  // La central más cercana es la que está en (0, 0)
}
