class persona
{
private:
        int edad;
        string nombre;

    public:
        Persona(){}
        ~Persona(){}

        void setEdad(int nuevaedad);
        void setNombre(string nuevonombre);
        int getEdad();
        string getNombre();
};

void Persona::setEdad(int nuevaedad)
{
    edad = nuevaedad;
}

void Persona::setNombre(string nuevonombre)
{
    nombre = nuevonombre;
}

int Persona::getEdad()
{
    return edad;
}
string Persona::getNombre()
{
    return  nombre;
}

