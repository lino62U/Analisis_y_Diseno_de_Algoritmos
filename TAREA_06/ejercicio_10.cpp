// Para resolver el problema de minimizar el número de monedas empleado para dar cambio al cliente en una máquina expendedora, podemos utilizar un algoritmo greedy. El enfoque consiste en siempre dar la moneda de mayor valor posible en cada paso, hasta completar el cambio necesario. A continuación, se presenta el algoritmo y el código en C++ para implementarlo:

// **Algoritmo Greedy para Minimizar el Número de Monedas:**

// 1. Inicializar un vector con los valores de las monedas disponibles en la máquina (0.01, 0.02, 0.05, 0.10, 0.20, 0.50 y 1).
// 2. Ordenar el vector de monedas en orden descendente (de mayor a menor valor).
// 3. Inicializar un vector para almacenar la cantidad de cada tipo de moneda a devolver como cambio, inicializándolo con ceros.
// 4. Calcular el cambio a devolver al cliente.
// 5. Mientras quede cambio por devolver:
//    a. Iterar por cada valor de moneda disponible:
//       - Si el valor de moneda es menor o igual que el cambio restante y hay monedas de ese valor disponibles:
//          - Incrementar la cantidad de esa moneda en el vector de cambio.
//          - Restar el valor de la moneda al cambio restante.
// 6. Devolver el vector de cambio como resultado.

// **Código en C++:**

// ```cpp
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> darCambio(double total, const std::vector<double>& monedas_disponibles) {
    std::vector<double> monedas = monedas_disponibles;
    std::sort(monedas.rbegin(), monedas.rend()); // Ordenar de mayor a menor valor
    std::vector<int> cambio(monedas.size(), 0);

    int cambio_centavos = static_cast<int>(total * 100);

    for (int i = 0; i < monedas.size(); ++i) {
        while (cambio_centavos >= static_cast<int>(monedas[i] * 100) && cambio[i] < 99) {
            cambio_centavos -= static_cast<int>(monedas[i] * 100);
            cambio[i]++;
        }
    }

    return cambio;
}

int main() {
    double total = 23.75; // Cambio a devolver
    std::vector<double> monedas_disponibles = {1, 0.5, 0.20, 0.10, 0.05, 0.02, 0.01};

    std::vector<int> cambio = darCambio(total, monedas_disponibles);

    std::cout << "Cambio a devolver: " << total << " euros" << std::endl;
    for (int i = 0; i < monedas_disponibles.size(); ++i) {
        if (cambio[i] > 0) {
            std::cout << "Monedas de " << monedas_disponibles[i] << " euros: " << cambio[i] << std::endl;
        }
    }

    return 0;
}





/*
El problema de dar cambio en una máquina expendedora de sellos de correos es un caso diferente al problema original de dar cambio en una máquina expendedora de monedas. En este caso, tenemos denominaciones de sellos de correos (0.54, 0.32, 0.17 y 0.01 euros) y queremos minimizar el número de sellos de cada denominación que se devuelven al cliente. Utilizar el mismo algoritmo greedy que antes (dar siempre el sello de mayor valor posible) no garantizará una solución óptima en este caso.

**Contraejemplo:**

Supongamos que necesitamos dar cambio de 1.36 euros. Con el algoritmo greedy original, daríamos un sello de 1 euro y dos sellos de 0.17 euros, lo que suma un total de 3 sellos. Sin embargo, una solución óptima sería dar un sello de 0.54 euros, uno de 0.32 euros, y dos sellos de 0.25 euros, lo que sumaría solo 4 sellos.

**Código del Algoritmo Greedy (que no proporciona una solución óptima):**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> darCambio(double total, const std::vector<double>& denominaciones) {
    std::vector<double> monedas = denominaciones;
    std::sort(monedas.rbegin(), monedas.rend()); // Ordenar de mayor a menor valor
    std::vector<int> cambio(monedas.size(), 0);

    int cambio_centavos = static_cast<int>(total * 100);

    for (int i = 0; i < monedas.size(); ++i) {
        while (cambio_centavos >= static_cast<int>(monedas[i] * 100) && cambio[i] < 99) {
            cambio_centavos -= static_cast<int>(monedas[i] * 100);
            cambio[i]++;
        }
    }

    return cambio;
}

int main() {
    double total = 1.36; // Cambio a devolver
    std::vector<double> denominaciones = {0.54, 0.32, 0.17, 0.01};

    std::vector<int> cambio = darCambio(total, denominaciones);

    std::cout << "Cambio a devolver: " << total << " euros" << std::endl;
    for (int i = 0; i < denominaciones.size(); ++i) {
        if (cambio[i] > 0) {
            std::cout << "Sellos de " << denominaciones[i] << " euros: " << cambio[i] << std::endl;
        }
    }

    return 0;
}
```

El código anterior es el mismo que antes, pero con denominaciones de sellos de correos en lugar de monedas. Puedes ver que, aunque el código puede encontrar una solución para dar cambio en sellos, no garantiza que esa solución sea óptima. En este caso, el algoritmo greedy podría dar una cantidad mayor de sellos de mayor valor en lugar de una combinación óptima con menos sellos.

*/