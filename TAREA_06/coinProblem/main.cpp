#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCoins(vector<int>& monedas, int cantidad) {
    int n = monedas.size();
    vector<vector<int>> dp(n + 1, vector<int>(cantidad + 1, INT_MAX));
    
    // Caso base: No se necesita ninguna moneda para hacer cambio de 0.
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= cantidad; j++) {
            if (monedas[i - 1] <= j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - monedas[i - 1]] + 1);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Impresión de la tabla de opciones
    cout << "Tabla de Programación Dinámica:" << endl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= cantidad; j++) {
            if (dp[i][j] == INT_MAX) {
                cout << "INF ";
            } else {
                cout << dp[i][j] << " ";
            }
        }
        cout << endl;
    }

    return dp[n][cantidad];
}

int main() {
    vector<int> monedas = {1, 4, 6}; // Monedas disponibles, por ejemplo: centavos de dólar
    int cantidad = 8; // Cantidad para la que queremos dar el cambio
    
    cout<<"**Datos: **"<<endl;
    cout<<"P: "<<cantidad<<endl;
    cout<<"Monedas: {"; for(auto i: monedas) cout<<i<<", ";cout<<"}"<<endl<<endl;
    int minimo = minCoins(monedas, cantidad);
    cout << "Cantidad mínima de monedas necesarias: " << minimo << endl;

    return 0;
}
