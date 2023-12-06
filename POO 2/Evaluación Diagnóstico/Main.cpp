#include "hotel.h"
#include "habitacion.h"
#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;

int main()
{
    //Atributos 
    cout<<"Programa de actividad diagnostica: Hotel"<<endl;

    int numero;
    string nomHuesped;
    int adultos;
    int infantes;
    double credito;
    double cargo;
    Hotel hotel("Aston");

    int opcion;
    opcion = 0;
    while (opcion != 6)
    {
        cout<<"Bienvenido a Hotel Aston"<<endl<<endl<<"1. Hacer CheckIn"<<endl<<"2. Hacer CheckOut"<<endl<<"3. Realizar cargos a habitacion"<<endl<<"4. Ingresos por tarifas"<<endl<<"5. Generar reporte de ocupacion"<<endl<<"6. Salir"<<endl;
        cin>>opcion;
        if (opcion == 1)
        {
            int validacion;
            cout<<"Nombre del huesped: "<<endl;
            cin>>nomHuesped;
            cout<<"Numero de adultos: "<<endl;
            cin>>adultos;
            cout<<"Nombre de ninos: "<<endl;
            cin>>infantes;
            cout<<"Credito: "<<endl;
            cin>>credito;
            validacion = hotel.checkin(nomHuesped,adultos,infantes,credito);
            if (validacion == -1)
            {
                cout<<"No disponible"<<endl;
            }
            else
            {
                cout<<validacion<<endl;
            }
        }

        if (opcion == 2)
        {
            cout<<"Numero de habitacion: "<<endl;
            cin>>numero;
            if (numero > 99 && numero < 150)
            {
                bool validacion;
                validacion = hotel.checkOut(numero);
                if (validacion == true)
                {
                    cout<<"Se ha realizado el CheckOut de manera exitosa"<<endl;
                }
                else
                {
                    cout<<"No se ha podido realizar el CheckOut"<<endl;
                }
            }
            else
            {
                cout<<"Numero de Habitacion invalida"<<endl;
            }
        }

        if (opcion == 3)
        {
            cout<<"Numero de habitacion: "<<endl;
            cin>>numero;
            if (numero > 99 && numero < 150)
            {
                cout<<"Cargo: "<<endl;
                cin>>cargo;
                bool validacion;
                validacion = hotel.realizarCargosHabitacion(numero,cargo);
                if (validacion == false)
                {
                    cout<<"Habitacion no ocupada"<<endl;
                }
            }
            else
            {
                cout<<"Numero de Habitacion invalida"<<endl;
            }
        }

        if (opcion == 4)
        {
            double totalTarifaBase;
            totalTarifaBase = hotel.getTotalXTarifaBase();
            cout<<"Tarifa total: "<<totalTarifaBase<<endl;
        }

        if (opcion == 5)
        {
            hotel.imprimeOcupacion();
            cout<<endl;
        }
    }

    return 0;

}