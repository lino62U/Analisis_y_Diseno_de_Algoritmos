#include <bits/stdc++.h>
using namespace std;


int funcion (vector<int> & monedas, int n)
{
    int c = 0, r=0;
    for(int i=0;i<n;i++){
        if(n-1 == i || c+monedas[i]<monedas[i+1]){
            c += monedas[i];
            r++;
        }
    }
    return r;
}
int main() {


    int test,n,v;
    vector<int> monedas;
    cin>>test;
    vector<int> resul;
    for (int i = 0; i < test; i++)
    {
        cin>>n;
        
        for(int i=0;i<n;i++){
            cin >> v;
            monedas.push_back(v);
        }
        monedas.clear();
        resul.push_back(funcion(monedas, n));
    }
    for(auto i: resul)
        cout<<i<<endl;
   
}
