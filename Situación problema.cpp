//Sistema de reservacion de vuelos.
//Francisco Javier Romo Juárez A01643189
// 01/12/2022

#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

using namespace std;

class Clients //Clase que obtiene los datos del cliente.
{
    private:
        string username;
        string pass;
        int kilometers;

    public:
        Clients() //Constructor
        {

        }
        string getUsername() //setters
        {

            return username;
        }
        string getPass()
        {

            return pass;
        }
        int getKilometers()
        {

            return kilometers;
        }
        void setGlobal(string new_username, string new_pass,int new_kilometers) //getters
        {
            username = new_username;
            pass = new_pass;
            kilometers = new_kilometers;
        }




};

class Flights //Clase que obtiene los datos del vuelo.
{
    private:
        string number;
        string date;
        int price;
        string destination;
        string duration;
        int kilometers;
        string airline;
    public:
        Flights(){ } //constructor
        string getNumber() //setters
        {
            return number;
        }
        string getDate()
        {
            return date;
        }
        int getPrice()
        {
            return price;
        }
        string getDestination()
        {
            return destination;
        }
        string getDuration()
        {
            return duration;
        }
        int getKilometers()
        {
            return kilometers;
        }
        string getAirline()
        {
            return airline;
        }
        void setGlobal(string new_number, string new_date, int new_price, string new_destination, string new_duration, int new_kilometers, string new_airline) //getters
        {
            number = new_number;
            date = new_date;
            price = new_price;
            destination = new_destination;
            duration = new_duration;
            kilometers = new_kilometers;
            airline = new_airline;
        }
};


int main()
{
    string linea;
    fstream archivo1("clients.txt"); //Archivo con datos de los clientes.
    fstream archivo2("flights.txt"); //Archivo con datos de los vuelos.
    fstream archivo3("reservacion.txt"); //Archivo donde se haran las reservaciones.

    //Atributos de la clase Clients
    string username;
    string pass;
    int kilometers_c;
    Clients cliente[3];

    //Atributos de la clase Flights
    string number;
    string date;
    int price;
    string destination;
    string duration;
    int kilometers_v;
    string airline;
    Flights vuelo[5];

    int cont_total=0; //Determina el numero de reservaciones realizadas previamente.

    cout<<"Seleccione algunas de las siguientes opciones: "<<endl;
    int option;
    option = 0;
    while (option != 3)
    {
        cout<<"1. Reservar"<<endl<<"2. Cancelar"<<endl<<"3. Salir"<<endl<<endl; //Menu
        cin>>option;
        cout<<endl;
        if (option == 1) //Reservar
        {
            fstream archivo1("clients.txt");
            fstream archivo2("flights.txt");
            int cont = 0;
            int cont_cliente=0;
            while (getline(archivo1,linea)) //Obtiene los datos del archivo clients y los pasa al objeto clientes.
            {
                if (cont == 3)
                {
                    cliente[cont_cliente].setGlobal(username, pass, kilometers_c);
                    cont = 0;
                    cont_cliente++;
                }
                if (cont == 0)
                {
                    username = linea;
                }
                if (cont == 1)
                {
                    pass = linea;
                }
                if (cont == 2)
                {
                    std::stoi(linea);
                    kilometers_c = stoi(linea);
                }
                cont++;
            }

            cont = 0;
            string username_text;
            string pass_text;
            while (cont == 0) //Comprueba que el usuario ingrese de forma correcta, una vez que ingresa añade el usuario al archivo reservaciones.
            {
                cout<<"Usuario: "<<endl;
                cin>>username_text;
                cout<<"Contrasena: "<<endl;
                cin>>pass_text;
                if (cliente[0].getUsername() == username_text && cliente[0].getPass() == pass_text)
                {
                    archivo3<<cliente[0].getUsername()<<endl;
                    kilometers_c = cliente[0].getKilometers();
                    cont = 1;
                }
                if (cliente[1].getUsername() == username_text && cliente[1].getPass() == pass_text)
                {
                    archivo3<<cliente[1].getUsername()<<endl;
                    kilometers_c = cliente[1].getKilometers();
                    cont = 1;
                }
                if (cliente[2].getUsername() == username_text && cliente[2].getPass() == pass_text)
                {
                    archivo3<<cliente[2].getUsername()<<endl;
                    kilometers_c = cliente[0].getKilometers();
                    cont = 1;
                }
                if (cliente[0].getUsername() != username_text && cliente[1].getUsername() != username_text &&  cliente[2].getUsername() != username_text)
                {
                    cout<<"Usuario o Contrasena incorrectos"<<endl;
                }
                if (cliente[0].getPass() != pass_text && cliente[1].getPass() != pass_text && cliente[2].getPass() != pass_text)
                {
                    cout<<"Usuario o Contrasena incorrectos"<<endl;
                }
            }
            int cont_vuelo=0;
            cont = 0;
            while (getline(archivo2,linea)) //Obtiene los datos del archivo flights y los pasa al objeto flights.
            {
                if (cont == 7)
                {
                    vuelo[cont_vuelo].setGlobal(number, date, price, destination, duration, kilometers_v, airline);
                    cont = 0;
                    cont_vuelo++;
                }
                if (cont == 0)
                {
                    destination = linea;
                }
                if (cont == 1)
                {
                    number = linea;
                }
                if (cont == 2)
                {
                    date = linea;
                }
                if (cont == 3)
                {
                    airline = linea;
                }
                if (cont == 4)
                {
                    duration = linea;
                }
                if (cont == 5)
                {
                    std::stoi(linea);
                    price = stoi(linea);
                }
                if (cont == 6)
                {
                    std::stoi(linea);
                    kilometers_v = stoi(linea);
                }
                cont++;
            }
            int option_vuelo=0;
            int cont_vuelo2=0;
            int cont_opcion=1;
            while (cont_vuelo2 < 5) //Despliega los vuelos disponibles.
            {
                cout<<"Opcion: "<<cont_opcion<<endl<<endl;
                cout<<vuelo[cont_vuelo2].getDestination()<<endl;
                cout<<vuelo[cont_vuelo2].getNumber()<<endl;
                cout<<vuelo[cont_vuelo2].getDate()<<endl;
                cout<<vuelo[cont_vuelo2].getAirline()<<endl;
                cout<<vuelo[cont_vuelo2].getDuration()<<endl;
                cout<<vuelo[cont_vuelo2].getPrice()<<endl;
                cout<<vuelo[cont_vuelo2].getKilometers()<<endl<<endl;
                cont_vuelo2++;
                cont_opcion++;
            }
            cout<<"¿Cual vuelo quieres reservar?"<<endl;
            cin>>option_vuelo;
            int cont_vuelo_registrar=0;
            int kilometers_total;
            int descuento;
            while (cont_vuelo_registrar == 0) //Registra el vuelo que el usuario elija al archivo reservaciones.
            {
                if (option_vuelo == 1)
                {
                    kilometers_v = vuelo[0].getKilometers();
                    kilometers_total = kilometers_c + kilometers_v;
                    price = vuelo[0].getPrice();
                    if (kilometers_total > 50000) //Saca el descuento si el usuario posee mas de 50000 km.
                    {
                        descuento = price * .40;
                        price = price - descuento;
                    }
                    archivo3<<kilometers_total<<endl<<vuelo[0].getDestination()<<endl<<vuelo[0].getNumber()<<endl<<vuelo[0].getDate()<<endl<<vuelo[0].getAirline()<<endl<<vuelo[0].getDuration()<<endl<<price<<" $"<<endl;
                    cont_vuelo_registrar = 1;
                }
                if (option_vuelo == 2)
                {
                    kilometers_v = vuelo[1].getKilometers();
                    kilometers_total = kilometers_c + kilometers_v;
                    price = vuelo[1].getPrice();
                    if (kilometers_total > 50000)
                    {
                        descuento = price * .40;
                        price = price - descuento;
                    }
                    archivo3<<kilometers_total<<endl<<vuelo[1].getDestination()<<endl<<vuelo[1].getNumber()<<endl<<vuelo[1].getDate()<<endl<<vuelo[1].getAirline()<<endl<<vuelo[1].getDuration()<<endl<<price<<" $"<<endl;
                    cont_vuelo_registrar = 1;
                }
                if (option_vuelo == 3)
                {
                    kilometers_v = vuelo[2].getKilometers();
                    kilometers_total = kilometers_c + kilometers_v;
                    price = vuelo[2].getPrice();
                    if (kilometers_total > 50000)
                    {
                        descuento = price * .40;
                        price = price - descuento;
                    }
                    archivo3<<kilometers_total<<endl<<vuelo[2].getDestination()<<endl<<vuelo[2].getNumber()<<endl<<vuelo[2].getDate()<<endl<<vuelo[2].getAirline()<<endl<<vuelo[2].getDuration()<<endl<<price<<" $"<<endl;
                    cont_vuelo_registrar = 1;
                }
                if (option_vuelo == 4)
                {
                    kilometers_v = vuelo[3].getKilometers();
                    kilometers_total = kilometers_c + kilometers_v;
                    price = vuelo[3].getPrice();
                    if (kilometers_total > 50000)
                    {
                        descuento = price * .40;
                        price = price - descuento;
                    }
                    archivo3<<kilometers_total<<endl<<vuelo[3].getDestination()<<endl<<vuelo[3].getNumber()<<endl<<vuelo[3].getDate()<<endl<<vuelo[3].getAirline()<<endl<<vuelo[3].getDuration()<<endl<<price<<" $"<<endl;
                    cont_vuelo_registrar = 1;
                }
                if (option_vuelo == 5)
                {
                    kilometers_v = vuelo[4].getKilometers();
                    kilometers_total = kilometers_c + kilometers_v;
                    price = vuelo[4].getPrice();
                    if (kilometers_total > 50000)
                    {
                        descuento = price * .40;
                        price = price - descuento;
                    }
                    archivo3<<kilometers_total<<endl<<vuelo[4].getDestination()<<endl<<vuelo[4].getNumber()<<endl<<vuelo[4].getDate()<<endl<<vuelo[4].getAirline()<<endl<<vuelo[4].getDuration()<<endl<<price<<" $"<<endl;
                    cont_vuelo_registrar = 1;
                }
            }
            cont_total++;
            cout<<"Se ha reservado con exito"<<endl<<endl;



        }
        if (option == 2) //Cancela las reservaciones.
        {
            string option2;
            while (option2 != "Y" && option2 != "N")
            {
                cout<<"Se borraran todas las reservaciones previas, desas continuar? Y/N"<<endl; //Confirma si el usuario desea cancelar.
                cin>>option2;
                if (option2 == "Y")
                {
                    fstream archivo3_1("reservacion.txt");
                    int i=0;
                    while (i != cont_total) //Cambia los datos por espacios segun la cantidad de reservaciones realizadas.
                    {
                        archivo3_1 <<" "<<endl;
                        archivo3_1 <<" "<<endl;
                        archivo3_1 <<" "<<endl;
                        archivo3_1 <<" "<<endl;
                        archivo3_1 <<" "<<endl;
                        archivo3_1 <<" "<<endl;
                        archivo3_1 <<" "<<endl;
                        archivo3_1 <<" "<<endl;
                        archivo3_1 <<" "<<endl;
                        archivo3_1 <<" "<<endl;
                        archivo3_1 <<" "<<endl;
                        archivo3_1 <<" "<<endl;
                        archivo3_1 <<" "<<endl;
                        archivo3_1 <<" "<<endl;
                        archivo3_1 <<" "<<endl;
                        archivo3_1 <<" "<<endl;
                        archivo3_1 <<" "<<endl;
                        archivo3_1 <<" "<<endl;
                        archivo3_1 <<" "<<endl;
                        archivo3_1 <<" "<<endl;
                        archivo3_1 <<" "<<endl;
                        archivo3_1 <<" "<<endl;
                        archivo3_1 <<" "<<endl;
                        archivo3_1 <<" "<<endl;
                        archivo3_1 <<" "<<endl;
                        archivo3_1 <<" "<<endl;
                        i++;
                    }
                    cont_total = 0;
                }
                if (option2 != "N" && option2 != "Y")
                {
                    cout<<"Opcion invalida, solo se puede (Y) o (N), recuerde escribir en MAYUSCULAS"<<endl;
                }
            }
        }
        if (option > 3)
        {
            cout<<"Opcion invalida"<<endl;
        }
        if (option < 1)
        {
            cout<<"Opcion invalida"<<endl;
        }
    }
    fstream archivo3_2("reservacion.txt");
    cout<<"Reservacion:"<<endl<<endl;
    while (getline(archivo3_2,linea)) //Muestra el archivo de reservaciones.
    {
        cout<<linea<<endl;
    }
    return 0;
}
