#include <iostream>
#include <vector>

std::vector<int> cambioMonedas(int cantidad, std::vector<int> monedas) {
    std::vector<int> solucion;
    int i = monedas.size() - 1; // Comenzar con la moneda de mayor valor
    
    while (cantidad > 0 && i >= 0) {
        if (monedas[i] <= cantidad) {
            int numMonedas = cantidad / monedas[i];
            cantidad -= numMonedas * monedas[i];
            for (int j = 0; j < numMonedas; j++) {
                solucion.push_back(monedas[i]);
            }
        }
        i--;
    }
    
    return solucion;
}

int main() {
    int cantidad = 68;
    std::vector<int> monedas = {1, 2, 5, 10, 20, 50}; // Valores de las monedas disponibles
    
    std::vector<int> resultado = cambioMonedas(cantidad, monedas);
    
    std::cout << "Cambio para " << cantidad << " unidades: ";
    for (int i = 0; i < resultado.size(); i++) {
        std::cout << resultado[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
