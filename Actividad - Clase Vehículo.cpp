#include <iostream>
using namespace std;

class Vehiculo
{
    private:
     int llantas;
     string motor;
     string bateria;
     string chasis;
     string cofre;
     string interior;
     string vidrios;
     string espejos;
     string luces_delanteras;
     string luces_traseras;
     string tanque_gasolina;
     string aleron;
     string antena;
     string placa;
     string color;

    public:
     Vehiculo(){ }

     int getLlantas()
     {
         return llantas;
     }
     string getMotor()
     {
         return motor;
     }
     string getBateria()
     {
         return bateria;
     }
     string getChasis()
     {
         return chasis;
     }
     string getCofre()
     {
         return cofre;
     }
     string getInterior()
     {
         return interior;
     }
     string getVidrios()
     {
         return vidrios;
     }
     string getEspejos()
     {
         return espejos;
     }
     string getLuces_delanteras()
     {
         return luces_delanteras;
     }
     string getLuces_traceras()
     {
         return luces_traseras;
     }
     string getTanque_gasolina()
     {
         return tanque_gasolina;
     }
     string getAleron()
     {
         return aleron;
     }
     string getAntena()
     {
         return antena;
     }
     string getPlaca()
     {
         return placa;
     }
     string getColor()
     {
         return color;
     }

     void setGlobal(int nuevo_llantas,string nuevo_motor,string nuevo_bateria,string nuevo_chasis,string nuevo_cofre,string nuevo_interior,string nuevo_vidrios,string nuevo_espejos,string nuevo_luces_delanteras,string nuevo_luces_traseras,string nuevo_tanque_gasolina,string nuevo_aleron,string nuevo_antena,string nuevo_placa,string nuevo_color)
     {
         llantas = nuevo_llantas;
         motor = nuevo_motor;
         bateria = nuevo_bateria;
         chasis = nuevo_chasis;
         cofre = nuevo_cofre;
         interior = nuevo_interior;
         vidrios = nuevo_vidrios;
         espejos = nuevo_espejos;
         luces_delanteras = nuevo_luces_delanteras;
         luces_traseras = nuevo_luces_traseras;
         tanque_gasolina = nuevo_tanque_gasolina;
         aleron = nuevo_aleron;
         antena = nuevo_antena;
         placa = nuevo_placa;
         color = nuevo_color;

     }


};

int main()
{
    int llantas;
    string motor;
    string bateria;
    string chasis;
    string cofre;
    string interior;
    string vidrios;
    string espejos;
    string luces_delanteras;
    string luces_traseras;
    string tanque_gasolina;
    string aleron;
    string antena;
    string placa;
    string color;
    Vehiculo objeto;

    cout<<"Numero de llantas del vehiculo: "<<endl;
    cin>>llantas;
    cout<<"Tiene motor? si/no: "<<endl;
    cin>>motor;
    cout<<"Tiene bateria? si/no: "<<endl;
    cin>>bateria;
    cout<<"Tiene chasis? si/no: "<<endl;
    cin>>chasis;
    cout<<"Tiene cofre? si/no: "<<endl;
    cin>>cofre;
    cout<<"Tiene interior? si/no: "<<endl;
    cin>>interior;
    cout<<"Tiene vidrios? si/no: "<<endl;
    cin>>vidrios;
    cout<<"Tiene espejo? si/no: "<<endl;
    cin>>espejos;
    cout<<"Tiene luces delanteras? si/no: "<<endl;
    cin>>luces_delanteras;
    cout<<"Tiene luces traseras? si/no: "<<endl;
    cin>>luces_traseras;
    cout<<"Tiene tanque de gasolina? si/no: "<<endl;
    cin>>tanque_gasolina;
    cout<<"Tiene aleron? si/no: "<<endl;
    cin>>aleron;
    cout<<"Tiene antena? si/no: "<<endl;
    cin>>antena;
    cout<<"Tiene placa? si/no: "<<endl;
    cin>>placa;
    cout<<"Tiene color? si/no: "<<endl;
    cin>>color;
    if (color == "si")
    {
        cout<<"Cual es el color del carro? "<<endl;
        cin>>color;
    }

    objeto.setGlobal(llantas,motor,bateria,chasis,cofre,interior,vidrios,espejos,luces_delanteras,luces_traseras,tanque_gasolina,aleron,antena,placa,color);

    cout<<endl<<"-------------------------"<<endl;
    cout<<"Datos de tu vehiculo: "<<endl;
    cout<<"Llantas: "<<objeto.getLlantas()<<endl;
    cout<<"Motor: "<<objeto.getMotor()<<endl;
    cout<<"Bateria: "<<objeto.getBateria()<<endl;
    cout<<"Chasis: "<<objeto.getChasis()<<endl;
    cout<<"Cofre: "<<objeto.getCofre()<<endl;
    cout<<"Interior: "<<objeto.getInterior()<<endl;
    cout<<"Vidrios: "<<objeto.getVidrios()<<endl;
    cout<<"Espejos: "<<objeto.getEspejos()<<endl;
    cout<<"Luces Delanteras: "<<objeto.getLuces_delanteras()<<endl;
    cout<<"Luces Traseras: "<<objeto.getLuces_traceras()<<endl;
    cout<<"Tanque de Gasolina: "<<objeto.getTanque_gasolina()<<endl;
    cout<<"Aleron: "<<objeto.getAleron()<<endl;
    cout<<"Antena: "<<objeto.getAntena()<<endl;
    cout<<"Placa: "<<objeto.getPlaca()<<endl;
    cout<<"Color: "<<objeto.getColor()<<endl;
    return 0;
}
