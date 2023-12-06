#include <iostream>

using namespace std;

int multiplica(int a, int b);

int main()
{
    int numero1,numero2,resultado;
    cout<<"Dame el número 1 a multiplicar: ";
    cin>>numero1;
    cout<<"Dame el número 2 a multiplicar: ";
    cin>>numero2;
    resultado = multiplica(numero1,numero2);
    cout << <<endl;
    return 0;
}

int mutiplica(int a, int b)
{
    int x;
    x=a*b;
    return x;
}
