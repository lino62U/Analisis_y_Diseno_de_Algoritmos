#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

vector<vector<int>> memo; // Tabla de memoización

int knapSack(int W, vector<int>& wt, vector<int>& val, int n) {
    if (n == 0 || W == 0)
        return 0;

    if (memo[n][W] != -1)
        return memo[n][W];

    if (wt[n - 1] > W)
        memo[n][W] = knapSack(W, wt, val, n - 1);
    else
        memo[n][W] = max(
            val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
            knapSack(W, wt, val, n - 1)
        );

    return memo[n][W];
}

int main() {
    vector<int> profit = {1, 2, 3, 4};
    vector<int> weight = {2, 3, 4, 5};
    int W = 7;
    int n = profit.size();

    memo.assign(n + 1, vector<int>(W + 1, -1)); // Inicializamos la tabla de memoización con -1

    int maxProfit = knapSack(W, weight, profit, n);

    // Impresión de la tabla de opciones
    cout << "Tabla de Programación Dinámica:" << endl;
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                memo[i][w] = 0;
            else if (weight[i - 1] <= w)
                memo[i][w] = max(profit[i - 1] + memo[i - 1][w - weight[i - 1]], memo[i - 1][w]);
            else
                memo[i][w] = memo[i - 1][w];
            cout << memo[i][w] << " ";
        }
        cout << endl;
    }

    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}
