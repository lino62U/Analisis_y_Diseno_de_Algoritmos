/*

Para resolver este problema y encontrar la solución óptima, utilizaremos un enfoque greedy. El algoritmo se basará en seleccionar la gasolinera más lejana que aún sea alcanzable con el combustible restante en el tanque. De esta manera, minimizaremos el número de paradas necesarias para repostar.
*/

#include <iostream>
#include <vector>

// Función que determina en qué gasolineras tiene que repostar el autobús
std::vector<int> elegirGasolineras(int distancia_total, int autonomia, std::vector<int>& gasolineras) {
    std::vector<int> gasolineras_repostar;
    int distancia_recorrida = 0;
    int gasolinera_anterior = 0;

    for (int i = 0; i < gasolineras.size(); ++i) {
        int distancia_a_gasolinera = gasolineras[i] - gasolinera_anterior;

        // Si no podemos llegar a la siguiente gasolinera sin repostar
        if (distancia_a_gasolinera > autonomia) {
            // Repostamos en la última gasolinera alcanzable
            gasolineras_repostar.push_back(gasolineras[i - 1]);
            distancia_recorrida = gasolineras[i - 1];
        }

        gasolinera_anterior = gasolineras[i];

        // Si hemos llegado a la última gasolinera sin repostar
        if (i == gasolineras.size() - 1) {
            int distancia_ultima_gasolinera = distancia_total - gasolineras[i];
            // Si no podemos llegar a la ciudad final sin repostar
            if (distancia_ultima_gasolinera > autonomia) {
                // Repostamos en la última gasolinera alcanzable
                gasolineras_repostar.push_back(gasolineras[i]);
                distancia_recorrida = gasolineras[i];
            }
        }
    }

    return gasolineras_repostar;
}

int main() {
    int distancia_total = 300; // Distancia total entre las ciudades (en kilómetros)
    int autonomia = 100; // Autonomía del autobús (en kilómetros)
    std::vector<int> gasolineras = {50, 120, 180, 250}; // Posiciones de las gasolineras en la ruta

    std::vector<int> gasolineras_repostar = elegirGasolineras(distancia_total, autonomia, gasolineras);

    std::cout << "Gasolineras en las que debe repostar:" << std::endl;
    for (int gasolinera : gasolineras_repostar) {
        std::cout << gasolinera << " km" << std::endl;
    }

    return 0;
}
