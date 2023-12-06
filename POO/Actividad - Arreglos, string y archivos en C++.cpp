#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

using namespace std;
string linea;
string linea1;
string linea2;

ifstream archivo("codigos.txt");

int cont_alemania;
int cont_brasil;
int cont_canada;
int cont_chile;
int cont_china;
int cont_espana;
int cont_japon;
int cont_mexico;

int sumando;

int alemania(string linea1);
int brasil(string linea2);
int canada(string linea2);
int chile(string linea2);
int china(string linea1);
int espana(string linea2);
int japon(string linea2);
int mexico(string linea2);

int main()
{
    cont_alemania = 0;
    cont_brasil = 0;
    cont_canada = 0;
    cont_chile = 0;
    cont_china = 0;
    cont_espana = 0;
    cont_japon = 0;
    cont_mexico = 0;
    sumando = 0;
    cout<<"Matriculas y contadores"<<endl;
    while (getline(archivo,linea))
    {
        linea1 = linea.substr(0,1);
        linea2 = linea.substr(0,2);
        sumando = alemania(linea1);
        cont_alemania = cont_alemania + sumando;
        sumando = brasil(linea2);
        cont_brasil = cont_brasil + sumando;
        sumando = canada(linea2);
        cont_canada = cont_canada + sumando;
        sumando = chile(linea2);
        cont_chile = cont_chile + sumando;
        sumando = china(linea1);
        cont_china = cont_china + sumando;
        sumando = espana(linea2);
        cont_espana = cont_espana + sumando;
        sumando = japon(linea2);
        cont_japon = cont_japon + sumando;
        sumando = mexico(linea2);
        cont_mexico = cont_mexico + sumando;
        cout<<linea<<endl;
    }
    cout<<"Alemania: "<<cont_alemania<<endl;
    cout<<"Brasil: "<<cont_brasil<<endl;
    cout<<"Canada: "<<cont_canada<<endl;
    cout<<"Chile: "<<cont_chile<<endl;
    cout<<"China: "<<cont_china<<endl;
    cout<<"Espana: "<<cont_espana<<endl;
    cout<<"Japon: "<<cont_japon<<endl;
    cout<<"Mexico: "<<cont_mexico<<endl;
    return 0;
}
int alemania(string linea1)
{
    if(linea1 == "D")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int brasil(string linea2)
{
    if(linea2 == "PP")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int canada(string linea2)
{
    if(linea2 == "CF")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int chile(string linea2)
{
    if(linea2 == "CC")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int china(string linea1)
{
     if(linea1 == "B")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int espana(string linea2)
{
    if(linea2 == "EC")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int japon(string linea2)
{
    if(linea2 == "JA")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int mexico(string linea2)
{
    if(linea2 == "XA")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



