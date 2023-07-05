#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

struct Ciudad {
    double x, y;
};

// Función que calcula la distancia euclídea entre dos ciudades
double distanciaEntreCiudades(const Ciudad& ciudad1, const Ciudad& ciudad2) {
    double dx = ciudad1.x - ciudad2.x;
    double dy = ciudad1.y - ciudad2.y;
    return std::sqrt(dx * dx + dy * dy);
}

// Función que encuentra la ciudad más cercana a un conjunto de ciudades ya conectadas
int encontrarCiudadMasCercana(const std::vector<Ciudad>& ciudades, const std::vector<bool>& conectadas) {
    int ciudad_mas_cercana = -1;
    double distancia_minima = std::numeric_limits<double>::max();

    for (int i = 0; i < ciudades.size(); ++i) {
        if (!conectadas[i]) {
            for (int j = 0; j < ciudades.size(); ++j) {
                if (conectadas[j] && i != j) {
                    double distancia = distanciaEntreCiudades(ciudades[i], ciudades[j]);
                    if (distancia < distancia_minima) {
                        distancia_minima = distancia;
                        ciudad_mas_cercana = i;
                    }
                }
            }
        }
    }

    return ciudad_mas_cercana;
}

// Función que conecta las ciudades minimizando el coste de la red de interconexión
std::vector<std::pair<int, int>> interconectarCiudades(const std::vector<Ciudad>& ciudades) {
    int num_ciudades = ciudades.size();
    std::vector<bool> conectadas(num_ciudades, false);
    std::vector<std::pair<int, int>> conexiones;

    // Empezamos interconectando la primera ciudad con la más cercana
    conectadas[0] = true;
    int ciudad_actual = 0;

    while (conexiones.size() < num_ciudades - 1) {
        int ciudad_mas_cercana = encontrarCiudadMasCercana(ciudades, conectadas);
        conectadas[ciudad_mas_cercana] = true;
        conexiones.push_back(std::make_pair(ciudad_actual, ciudad_mas_cercana));
        ciudad_actual = ciudad_mas_cercana;
    }

    return conexiones;
}

int main() {
    std::vector<Ciudad> ciudades = {
        {0, 0},   // Ciudad 0
        {1, 1},   // Ciudad 1
        {3, 1},   // Ciudad 2
        {2, 4},   // Ciudad 3
        {4, 5}    // Ciudad 4
    };

    std::vector<std::pair<int, int>> conexiones = interconectarCiudades(ciudades);

    std::cout << "Conexiones entre ciudades para minimizar el coste de la red:" << std::endl;
    for (const auto& conexion : conexiones) {
        std::cout << "Ciudad " << conexion.first << " conectada con Ciudad " << conexion.second << std::endl;
    }

    return 0;
}
