#include<iostream>

using namespace std;

float Addition(float a, float b) { return a+b;}
float Subtraction(float a, float b) { return a-b;}
float Multiplication(float a, float b) { return a*b;}
float Division(float a, float b) { return a/b;}
int main()
{
    // Code A
    float a, b, c; 
    int opt;
    // enter the operands
    cin >> a >> b;
    // OPT-> 0-Addition, 1-Subtraction, 3-Multiplication, 4-Division
    cin >> opt;
    switch( opt )
    {
    case 0: c = Addition(a, b); break;
    case 1: c = Subtraction(a, b); break;
    case 2: c = Multiplication(a, b); break;
    case 3: c = Division(a, b); break;
    // more cases operations go here
    }
}







