#include <iostream>
using namespace std;

unsigned long figonachi(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return figonachi(n-2)+figonachi(n-1);
    }
}

unsigned long figonachiOptimizado(int n)
{
    unsigned long tabla[n+1];
    for(int i = 0;i<n+1;i++)
    {
        tabla[i]=0;
    }
    tabla[0]=tabla[1]=1;
    figonachiOptimizado(n,tabla);
    return tabla[n];
    
}

unsigned long figonachiOptimizado(int n, unsigned long tabla[])
{
    
}

int main()
{
    int n;
    cout<<"Numero de figonachi: "<<endl;
    cin>>n;
    cout<<"El numero de figonachi de "<<n<<" es: "<<figonachi(n)<<endl;
    return 0;
}