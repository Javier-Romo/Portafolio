#include "Rectangular.h"
#include "Polar.h"
#include <iostream>

using namespace std;

int main()
{
    Rectangular rec1(2.0,3.0);
    Rectangular rec2(1.0,4.0);
    Rectangular rec3(5.0,6.0);

    cout<<"Rectangulo 1: "<<rec1.toString()<<endl;
    cout<<"Rectangulo 2: "<<rec2.toString()<<endl;
    cout<<"Rectangulo 3: "<<rec3.toString()<<endl;

    Rectangular rec4=rec1.suma(rec2).suma(rec3);
    Rectangular rec5=rec1+rec2+rec3+rec4;

    cout<<"Rectangulo 1 + Rectangulo 2: "<<rec4.toString()<<endl;
    cout<<"Rectangulo 1 + Rectangulo 2 + Rectangulo 3 + Rectangulo 4: "<<rec5.toString()<<endl;

    Rectangular recRes=rec1+rec2;

    cout<<rec1<<endl;
    
    Polar pol1(4,30);
    Polar pol2(3,45);

    cout<<"Cordenada polar 1 "<<pol1<<endl;
    

    
}