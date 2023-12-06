#include <iostream>

using namespace std;

int multiplica(int a, int b);
{

}

int main()
{

    int arreglo[5];
    int arreglo2[2];
    for(int i=0;i<5;i++)
    {
        arreglo[i] = i+2;
    }
    for(int i=0;i<2;i++)
    {
        arreglo2[i] = i+1;
    }
    for(int i=0;i<5;i++)
    {
        cout<<arreglo[i]<<endl;
    }
    for(int i=0;i<2;i++)
    {
        cout<<arreglo2[i]<<endl;
    }
    return 0

}
