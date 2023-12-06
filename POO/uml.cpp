#include <iostream>
using namespace std;

class Persona
{
    Persona();

    private:
     string nombre;
     string apellido;
     int edad;

    public:
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
    cout<<"nombre: ";
    cin>>nombre;
    cout<<"apellido: ";
    cin>>apellido;
    cout<<"edad: ";
    cin>>edad;

}
