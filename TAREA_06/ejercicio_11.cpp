// El algoritmo greedy para optimizar el uso de las aulas se puede diseñar de la siguiente manera:

// 1. Ordenar las clases en orden creciente de la hora de finalización (fi).
// 2. Inicializar un conjunto vacío de aulas disponibles.
// 3. Recorrer cada clase en orden:
//    a. Si no hay ninguna aula disponible, asignar un aula nueva para esa clase.
//    b. Si hay aulas disponibles, asignar la clase a la primera aula que esté disponible en ese momento y actualizar el horario de disponibilidad del aula.
//    c. Si ninguna aula está disponible en ese momento, asignar un aula nueva para esa clase.
// 4. El número de aulas utilizado será igual al tamaño del conjunto de aulas disponibles al final del proceso.

// **Código del Algoritmo Greedy:**

// ```cpp
#include <iostream>
#include <vector>
#include <algorithm>

struct Class {
    int start_time;
    int end_time;
};

bool sortByEndTime(const Class& c1, const Class& c2) {
    return c1.end_time < c2.end_time;
}

int minimizeAulasNecesarias(const std::vector<Class>& classes) {
    std::vector<Class> sortedClasses = classes;
    std::sort(sortedClasses.begin(), sortedClasses.end(), sortByEndTime);

    std::vector<int> availableAulas;
    int aulasNecesarias = 0;

    for (const Class& clase : sortedClasses) {
        int current_class_start = clase.start_time;
        int current_class_end = clase.end_time;

        bool aula_asignada = false;

        for (int i = 0; i < availableAulas.size(); ++i) {
            if (current_class_start >= availableAulas[i]) {
                availableAulas[i] = current_class_end;
                aula_asignada = true;
                break;
            }
        }

        if (!aula_asignada) {
            availableAulas.push_back(current_class_end);
            aulasNecesarias++;
        }
    }

    return aulasNecesarias;
}

int main() {
    // Ejemplo de clases con sus horas de inicio y finalización
    std::vector<Class> classes = {
        {8, 10},
        {9, 11},
        {10, 12},
        {13, 14},
        {12, 14},
        {14, 15}
    };

    int aulas_necesarias = minimizeAulasNecesarias(classes);
    std::cout << "Número de aulas necesarias: " << aulas_necesarias << std::endl;

    return 0;
}