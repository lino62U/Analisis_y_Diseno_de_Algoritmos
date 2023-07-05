// Para resolver este problema con un algoritmo greedy, podemos seguir los siguientes pasos:

// 1. Ordenar las licencias de manera descendente según sus tasas de incremento de precio (∆pi).
// 2. Comprar una licencia cada mes, comenzando por la más costosa según la tasa de incremento.
// 3. Actualizar el precio de cada licencia después de cada mes transcurrido.

// Al comprar las licencias en orden descendente de tasas de incremento, aseguramos que adquirimos primero las licencias que tendrán mayores aumentos de precio en el futuro, lo que nos permite minimizar los costos.

// **Algoritmo Greedy:**
// 1. Crear una lista de tuplas (i, ∆pi) para representar cada licencia i y su tasa de incremento ∆pi.
// 2. Ordenar la lista en orden descendente según las tasas de incremento ∆pi.
// 3. Inicializar una variable para el costo total, por ejemplo, `totalCost = 0`.
// 4. Por cada mes, desde `mes = 1` hasta `mes = n`:
//    a. Comprar la licencia con la tasa de incremento más alta en ese momento (primera de la lista).
//    b. Actualizar su precio utilizando la fórmula: `precio_i = 100 * pow(1 + ∆pi, mes)`.
//    c. Incrementar `totalCost` con el nuevo precio de la licencia.

// **Código en C++:**
// ```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

bool compareLicense(const std::pair<int, double>& a, const std::pair<int, double>& b) {
    return a.second > b.second; // Ordenar en orden descendente por tasa de incremento ∆pi
}

double minimizeCost(int n, std::vector<std::pair<int, double>>& licenses) {
    std::sort(licenses.begin(), licenses.end(), compareLicense);

    double totalCost = 0;
    for (int month = 1; month <= n; month++) {
        int licenseIndex = 0;
        double maxIncrement = licenses[0].second;
        
        // Buscar la licencia con la mayor tasa de incremento en ese momento
        for (int i = 1; i < licenses.size(); i++) {
            if (licenses[i].second > maxIncrement) {
                maxIncrement = licenses[i].second;
                licenseIndex = i;
            }
        }

        // Calcular el precio de la licencia y actualizar su tasa de incremento
        double licensePrice = 100 * pow(1 + maxIncrement, month);
        licenses[licenseIndex].second *= 1 + licenses[licenseIndex].second;
        
        totalCost += licensePrice;
    }

    return totalCost;
}

int main() {
    int n = 12; // Número de meses
    std::vector<std::pair<int, double>> licenses = {{1, 0.02}, {2, 0.03}, {3, 0.01}, {4, 0.05}}; // Ejemplo de tasas de incremento ∆pi

    double minCost = minimizeCost(n, licenses);
    std::cout << "Costo mínimo de adquisición de las licencias: " << minCost << " euros." << std::endl;

    return 0;
}
