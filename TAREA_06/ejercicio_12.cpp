// El algoritmo greedy para minimizar el retraso máximo de las tareas se puede diseñar de la siguiente manera:

// 1. Ordenar las tareas en orden creciente de la hora de finalización di.
// 2. Inicializar una variable "current_time" para llevar un seguimiento del tiempo actual.
// 3. Inicializar una variable "max_retraso" para mantener el valor máximo de retraso encontrado hasta ahora.
// 4. Recorrer cada tarea en orden:
//    a. Calcular la hora de inicio si de la tarea i como si = di - ti.
//    b. Actualizar "current_time" como el máximo entre el tiempo de inicio si y el tiempo actual current_time.
//    c. Calcular el retraso de la tarea i como max(0, current_time - di).
//    d. Actualizar "max_retraso" como el máximo entre el retraso de la tarea i y el valor actual de "max_retraso".
//    e. Actualizar "current_time" como current_time + ti.
// 5. El valor de "max_retraso" al final del proceso será el retraso máximo mínimo obtenido.

// **Código del Algoritmo Greedy:**

// ```cpp
#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    int ti; // Unidades de tiempo requeridas para la tarea
    int di; // Hora máxima de finalización de la tarea
};

bool sortByDi(const Task& t1, const Task& t2) {
    return t1.di < t2.di;
}

int minimizeMaxRetraso(const std::vector<Task>& tasks) {
    std::vector<Task> sortedTasks = tasks;
    std::sort(sortedTasks.begin(), sortedTasks.end(), sortByDi);

    int current_time = 0;
    int max_retraso = 0;

    for (const Task& task : sortedTasks) {
        int si = std::max(current_time, task.di - task.ti);
        int retraso = std::max(0, current_time - task.di);

        max_retraso = std::max(max_retraso, retraso);
        current_time = si + task.ti;
    }

    return max_retraso;
}

int main() {
    // Ejemplo de tareas con unidades de tiempo requeridas y horas máximas de finalización
    std::vector<Task> tasks = {
        {4, 10},
        {2, 5},
        {6, 15},
        {3, 7}
    };

    int min_max_retraso = minimizeMaxRetraso(tasks);
    std::cout << "Retraso máximo mínimo: " << min_max_retraso << std::endl;

    return 0;
}
