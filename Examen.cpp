#include <iostream>

using namespace std;

class Fecha
{
    private:
        int dia;
        int mes;
    public:
        Fecha(){ }
        ~Fecha(){ }
        int getDia()
        {
            return dia;
        }
        int getMes()
        {
            return mes;
        }
        void setGlobal(int nuevo_dia, int nuevo_mes)
        {
            dia = nuevo_dia;
            mes = nuevo_mes;
        }

};

class Empleado
{
    private:
        string nombreEmp;
        float sueldoEmp;
        //Fecha cumpleAnios;
    public:
        Empleado(){ }
        ~Empleado(){ }
        string getNombreEmp()
        {
            return nombreEmp;
        }
        float getSueldoEmp()
        {
            return sueldoEmp;
        }
        //Fecha getCumpleAnios()
        //{

            //cumpleAnios = Fecha.getDia() + Fecha.getMes()
            //return cumpleAnios;
        //}
        //void setGlobal(string nuevo_nombreEmp, float nuevo_sueldoEmp, Fecha nuevo_cumpleAnios)
        void setGlobal(string nuevo_nombreEmp, float nuevo_sueldoEmp)
        {
            nombreEmp = nuevo_nombreEmp;
            sueldoEmp = nuevo_sueldoEmp;
//            cumpleAnios = nuevo_cumpleAnios;
        }
        int subeSueldo(float porcentaje)
        {
            if (porcentaje >=1 && porcentaje <= 10)
            {
                sueldoEmp = sueldoEmp + (sueldoEmp*(porcentaje*.01));
            }
            else
            {
                cout<<"Porcentaje invalido, no hay incremento salarial"<<endl;
            }
            cout<<sueldoEmp<<endl;
            return sueldoEmp;
        }
};

int main()
{
    int dia;
    int mes;
    string nombreEmp;
    float sueldoEmp;
    Fecha cumpleAnios;
    Empleado emp1;
    Empleado emp2;
    cout<<"Nombre del primer empleado: "<<endl;
    cin>>nombreEmp;
    cout<<"Sueldo del primer empleado: "<<endl;
    cin>>sueldoEmp;
    cout<<"Dia de su cumpleaños: "<<endl;
    cin>>dia;
    cout<<"Mes de su cumpleaños: "<<endl;
    cin>>mes;
    cumpleAnios.setGlobal(dia, mes);
    emp1.setGlobal(nombreEmp, sueldoEmp);
    cout<<"Nombre del segundo empleado: "<<endl;
    cin>>nombreEmp;
    cout<<"Sueldo del segundo empleado: "<<endl;
    cin>>sueldoEmp;
    cout<<"Dia de su cumpleaños: "<<endl;
    cin>>dia;
    cout<<"Mes de su cumpleaños: "<<endl;
    cin>>mes;
    cumpleAnios.setGlobal(dia, mes);
    emp2.setGlobal(nombreEmp, sueldoEmp);
    //cout<<emp1.getNombreEmp()<<" gana "<<emp1.getSueldoEmp()<<" y cumple el "<<emp1.getCumpleAnios()<<endl;
    //cout<<emp2.getNombreEmp()<<" gana "<<emp2.getSueldoEmp()<<" y cumple el "<<emp2.getCumpleAnios()<<endl;
    int opcion=0;
    while (opcion != 2)
    {
        cout<<"Menu:"<<endl<<"1.Subir Sueldo"<<endl<<"2.Salir"<<endl;
        cin>>opcion;
        if (opcion == 1)
        {
            cout<<"Empleado: 1 o 2"<<endl;
            int opcion2;
            cin>>opcion2;
            if (opcion2 == 1)
            {
                cout<<"porcentaje:"<<endl;
                int porcentaje;
                cin>>porcentaje;
                emp1.subeSueldo(porcentaje);
            }
            if (opcion2 == 2)
            {
                cout<<"porcentaje:"<<endl;
                int porcentaje;
                cin>>porcentaje;
                emp2.subeSueldo(porcentaje);

            }

        }
    }


}
