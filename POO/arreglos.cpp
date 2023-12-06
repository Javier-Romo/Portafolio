#include<iostream>
using namespace std;

int main(){
    int mes;
    string mes_final;
    string meses[12] = {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
    cout<<"Ingrese un numero del 1 al 12"<<endl;
    cin>>mes;
    mes = mes-1;
    mes_final = meses[mes];
    cout<<"Este es tu mes: "<<mes_final<<endl;
    return 0;
}
