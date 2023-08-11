#include <iostream>
#include <vector>

using namespace std;

const int N = 4; // Tamaño del alfabeto Σ

void transitiveClosure(vector<vector<bool>>& orderRelation) {
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                orderRelation[i][j] = orderRelation[i][j] || (orderRelation[i][k] && orderRelation[k][j]);
            }
        }
    }
}

bool precedes(const vector<vector<bool>>& orderRelation, char u, char v) {
    int uIndex = u - 'a';
    int vIndex = v - 'a';
    return orderRelation[uIndex][vIndex];
}

int main() {
    vector<vector<bool>> orderRelation(N, vector<bool>(N, false));

    // Definir la relación de orden aquí (rellenar la matriz orderRelation)

    transitiveClosure(orderRelation);

    char u, v;
    cout << "Ingresa dos elementos del alfabeto (a, b, c, d): ";
    cin >> u >> v;

    if (precedes(orderRelation, u, v)) {
        cout << u << " precede a " << v << " en el orden Φ." << endl;
    } else {
        cout << u << " no precede a " << v << " en el orden Φ." << endl;
    }

    return 0;
}

