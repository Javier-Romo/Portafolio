#include <iostream>
#include <array>
using namespace std;

class Airport
{
    private:
     int id;
     string date;
     string city;
     string country;
     int totalTransactions;
     int totalDailyIncomes;
     string airlines[3];

    public:
     Airport(){ }

     int getId()
     {
         return id;
     }

     string getDate()
     {
         return date;
     }

     string getCity()
     {
         return city;
     }

     string getCountry()
     {
         return country;
     }



     void setGlobal(int nuevo_id, string nuevo_date, string nuevo_city, string nuevo_country)
     {
         id = nuevo_id;
         date = nuevo_date;
         city = nuevo_city;
         country = nuevo_country;
     }

     void startOperations(string date)
     {
         date = date;
         cout<<"Identificador del aeropuerto: "<<endl;
         cin>>id;
         cout<<"Ciudad de operacion: "<<endl;
         cin>>city;
         cout<<"Pais: "<<endl;
         cin>>country;
     }

     void printAllFlights()
     {
         cout<<"Los vuelos programados para"<<date<<"son: " <<endl;
     }

     int closeOperations()
     {
         cout<<"Numero de vuelos: "<<totalTransactions<<endl;
         cout<<"Ganancias totales: "<<totalDailyIncomes<<endl;
     }
};

class Airline
{
    private:
     string boardingCity;
     string shortName;
     int incomes;
     int flights[5];
     int f;


    public:
     Airline(int f_nuevo)
     {
        f = f_nuevo;
        flights = [f+1];
        for (i=0;i<=f;i++)
        {
            flights[i];
        }
     }

     string getBoardingCity()
     {
         return boardingCity;
     }

     string getShortName()
     {
         return shortName;
     }

     int getIncomes()
     {
         return incomes;
     }

     int getFilas()
     {
         return f;
     }


     void setGlobal(string nuevo_boardingCity, string nuevo_shortName, int nuevo_incomes, int nuevo_f)
     {
         boardingCity = nuevo_boardingCity;
         shortName = nuevo_shortName;
         incomes = nuevo_incomes;
         f = nuevo_f;
     }
     void updateAirline(string name)
     {
         cout<<"Clave de linea aerea: "<<endl;
         cin>>shortName;
         cout<<"Nombre de la linea aerea: "<<endl;
         cin>>name;
     }

     void scheduleFlight()
     {
        while(flights <= 5)
        {
            updateAirline(string name);
            cout<<"Ciudad de embarque: "<<endl;
            cin>>city;
            cout<<"Ciudad destino: "<<endl;
            cin>>fromTo;
            cout<<"Distancia: "<<endl;
            cin>>distance;
            cout<<"Tripulacion: "<<endl;
            cin>>crew;
            cout<<"Hora: "<<endl;
            cin>>hour;
            cout<<"Precio: "<<endl;
            cin>>price;
        }
     }

     int currentIncome()
     {
         incomes = price;
     }

     int closeOperations()
     {
        int totalIncomes;
        totalIncomes = totalIncomes+incomes;
        cout<<totalIncomes<<endl;
     }
};

class Flight
{
    private:
     string date;
     string hour;
     int price;
     string airplaneModel;
     string fromTo;
     int distance;
     string crew;
     int fuel;
     int f,c,seats[30][4];

    public:
     Flight(int f_nuevo, int c_nuevo)
     {
        f = f_nuevo;
        c = c_nuevo;
        seats = [f+1][c+1];
        for (i=0;i<=f;i++)
        {
            for (j=0;j<=c;j++)
            {
                seats[i][j] = 0;
            }
        }
     }

     string getDate()
     {
         return date;
     }

     string getHour()
     {
         return hour;
     }

     int getPrice()
     {
         return price;
     }

     string getAirplaneModel()
     {
         return airplaneModel;
     }

     string getFromTo()
     {
         return fromTo;
     }

     int getDistance()
     {
         return distance;
     }

     string getCrew()
     {
         return crew;
     }

     int getFuel()
     {
         return fuel;
     }

     int Filas()
     {
         return f;
     }

     int Columnas()
     {
         return c;
     }

     int retornaDatoSeats(int fila, int columna)
     {
        return seats[f][c];
     }

     void asignaDatoSeats(int dato, int fila, int columna)
     {
        seats[f][c] = dato;
     }


     void setGlobal(string nuevo_date, string nuevo_hour, int nuevo_price, string nuevo_airplaneModel, string nuevo_fromTo, int nuevo_distance, string nuevo_crew, int nuevo_fuel, int nuevo_f, int nuevo_c)
     {
         date = nuevo_date;
         hour = nuevo_hour;
         price = nuevo_price;
         airplaneModel = nuevo_airplaneModel;
         fromTo = nuevo_fromTo;
         distance = nuevo_distance;
         crew = nuevo_crew;
         fuel = nuevo_fuel;
         f = nuevo_f;
         c = nuevo_c;
     }

     void calculateFuel()
     {
         fuel = (distance * 1200)/100;
     }

};

class Passenger
{
    private:
     string name;
     int phone;

    public:
     Passenger(){ }

     string getName()
     {
         return name;
     }

     int getPhone()
     {
         return phone;
     }

     void setGlobal(string nuevo_name, int nuevo_phone)
     {
         name = nuevo_name;
         phone = nuevo_phone;
     }
};


int main()
{
    Airport aeropuerto;
    Airline aerolinea;
    Flight vuelo;
    Passenger pasajero;
}
