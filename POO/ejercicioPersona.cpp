#include <iostream>
using namespace std;

class Persona
{


    private:
     string nombre;
     string apellido;
     int edad;

    public:
     Persona(){ }

     string getNombre()
     {
         return nombre;
     }
     string getApellido()
     {
         return apellido;
     }
     int getEdad()
     {
         return edad;
     }

     void setGlobal(string nuevonombre,string nuevoapellido, int nuevaedad)
     {
         nombre = nuevonombre;
         apellido = nuevoapellido;
         edad = nuevaedad;

     }

};


int main()
{
    string nombre,apellido;
    int edad;
    Persona objeto;

    /*Pedir datos al usuario*/
    cout<<"Dame Nombre: ";
    cin>>nombre;
    cout<<"Dame Apellido: ";
    cin>>apellido;
    cout<<"Dame edad: ";
    cin>>edad;
    /*Fin de pedir datos*/

    //Asignar valores al objeto
    objeto.setGlobal(nombre,apellido,edad);

    //mostrar los valores del objeto
    cout<<endl<<"-------------------------"<<endl;
    cout<<"Los valores capturados son:"<<endl;
    cout<<"Nombre: "<<objeto.getNombre()<<endl;
    cout<<"Apellido: "<<objeto.getApellido()<<endl;
    cout<<"Edad: "<<objeto.getEdad()<<endl;



    return 0;
}
