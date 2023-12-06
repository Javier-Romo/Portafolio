#include "Figura.h"
#include "Rectangulo.h"
#include "Cuadrado.h"
#include "Caja.h"
#include<iostream>
#include <vector>
using namespace std;

int main(){
    vector<Figura*> figuras;
    figuras.push_back(new Rectangulo());
    figuras.push_back(new Rectangulo(5.0,7.0));
    figuras.push_back(new Cuadrado());
    figuras.push_back(new Cuadrado(8.0));
    figuras.push_back(new Caja());
    figuras.push_back(new Caja(3.0,4.0,6.0));
    figuras.push_back(new Cuadrado(10.0));

    for(int i=0; i<figuras.size();i++)
    {
        Figura* figurita=figuras[i];
        figurita->imprimir();
        cout<<"Perimetro: "<<figurita->perimetro()<<endl;
        cout<<"Area: "<<figurita->area()<<endl;
        cout<<"Volumen: "<<figurita->volumen()<<endl;
        if( Cuadrado* c=dynamic_cast<Cuadrado*>(figurita))
        {
            c->saludar();
        }
        cout<<endl;
    }
   
    /*
    SIN APUNTADORES
    Figura fig1;
    fig1.imprimir();
    cout<<"Perimetro: "<<fig1.perimetro()<<endl;
    cout<<"Area: "<<fig1.area()<<endl;
    cout<<"Volumen: "<<fig1.volumen()<<endl;
    cout<<endl;

    Rectangulo rec1;
    rec1.imprimir();
    cout<<"Perimetro: "<<rec1.perimetro()<<endl;
    cout<<"Area: "<<rec1.area()<<endl;
    cout<<"Volumen: "<<rec1.volumen()<<endl;
    cout<<endl;

    Rectangulo rec2(5.0,7.0);
    rec2.imprimir();
    cout<<"Perimetro: "<<rec2.perimetro()<<endl;
    cout<<"Area: "<<rec2.area()<<endl;
    cout<<"Volumen: "<<rec2.volumen()<<endl;
    cout<<endl;

    Cuadrado cuad1;
    cuad1.imprimir();
    cout<<"Perimetro: "<<cuad1.perimetro()<<endl;
    cout<<"Area: "<<cuad1.area()<<endl;
    cout<<"Volumen: "<<cuad1.volumen()<<endl;
    cout<<endl;

    Cuadrado cuad2(8.0);
    cuad2.imprimir();
    cout<<"Perimetro: "<<cuad2.perimetro()<<endl;
    cout<<"Area: "<<cuad2.area()<<endl;
    cout<<"Volumen: "<<cuad2.volumen()<<endl;
    cout<<endl;

    Caja caja1;
    caja1.imprimir();
    cout<<"Perimetro: "<<caja1.perimetro()<<endl;
    cout<<"Area: "<<caja1.area()<<endl;
    cout<<"Volumen: "<<caja1.volumen()<<endl;
    cout<<endl;

    Caja caja2(4.0,4.0,4.0);
    caja1.imprimir();
    cout<<"Perimetro: "<<caja1.perimetro()<<endl;
    cout<<"Area: "<<caja1.area()<<endl;
    cout<<"Volumen: "<<caja1.volumen()<<endl;
    cout<<endl;
    */
}