#include <iostream>
using namespace std;

int main()
{
    int contador;
    for (int i=0;i < 3;i++)
    {
        cout<<i<<endl;
        contador = i;
    }
    for (int i=contador;i < 5;i++)
    {
        cout<<i<<endl;
        contador = i;
    }
    
}