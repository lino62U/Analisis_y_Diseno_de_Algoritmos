#include <iostream>

using namespace std;

int condition(int i,int n,int &c){
    c++;
    return i < n;
}

void ON(int n){

    int a=0;
    
    for(int i=0;condition(i,n,a);i++){  //n + 1
        a++; 
        if(i % 2 == 0){ // n 
            a++; 
            cout<<i<<endl; // n/2 (piso) + 1
        }
    }
    cout<<"Resultado: "<<a<<endl;
}

void ON_2(int n){
    
    int a=0;

    for(int i=0;condition(i,n,a);i++){ //n+1
        a++;
        if(i % 2 == 0){ //n
            a++;
            cout<<i<<endl; //n/2 (piso) + 1
        }
    }
    
    for(int i=0;condition(i,n,a);i++){ //n+1
        a++;
        if(i % 2 != 0){ //n
            a++;
            cout<<i<<endl; //n/2 (piso)
        }
    }
    cout<<"Resultado: "<<a<<endl;
    
}

void ON_CUADRADO(int n){
    
    
    int a=0;
    
    for(int i=0;condition(i,n,a);i++){ //n+1
        for(int j=i;condition(j,n,a);j++){ // (n+1)(n)/2 + n
            a++;
            cout<<i<<","<<j<<endl; //n(n+1)/2
        }
    }
    cout<<"Resultado: "<<a<<endl;
    //O(n^2)
}

void LOGN(int n){
    int i=1; //1
    int a=1;
    while(condition(i,n,a)){ //log2n + 1 se redondeda el log2n a techo
        cout<<i<<endl; a++;//log2n 
        i *= 2; a++;//log2n
    }
    cout<<"Resultado: "<<a<<endl;
    
    //O(log2n)
}

void AB(string _a,string _b){
    string A = _a, B = _b; 
    int a=0;
    for(int i=0;i <= A.size()+2;i++){ // A + 1
        for(int j=0;j <= B.size()+1;j++){ // A(B+1)
            a++;
            cout<<A[i]<<","<<B[j]<<endl; // AB
        }
    }
    cout<<"Resultado: "<<a<<endl;
    
    //O(A*B)
}

void NLOGN(int _n){
    int n=_n,j;
    int a=0;
    for(int i=0; condition(i,n,a);i++){ //n+1 
        j=1; a++; // n --9
        while(condition(j,n,a)){ //n(log2n + 1) 
            cout<<j<<endl; a++; //n(log2n)  
            j *= 2; a++; //n(log2n)
        }
    }
    cout<<"Resultado: "<<a<<endl;
    
    //O(nlog2n)
}

void O1(){
    int a=1;
    int n = 1000; a++; //1
    a++;
    if(n % 2 == 0){ //1
        a++;
        cout<<"par"<<endl; //1
    }
    else{ 
        a++;
        cout<<"impar"<<endl;
    }
    //3
    //O(1)
}


int main(){
    
    //ON(12);
     ON_2(5);
    // ON_CUADRADO(33);
    // NLOGN(12);
    // LOGN(12);
    // AB("HOLA","MUNDO");
    // O1();
    
    return 0;
}
