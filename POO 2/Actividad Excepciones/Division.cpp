#include <iostream>
using namespace std;

double divide(double num,double den) {
    //Si el denominador es 0 entonces arrojar una instancia de invalid_argument y poner como mensaje que el denominador no puede ser 0.
    if (den == 0)
    {
        throw invalid_argument("El denomindaor no puede ser 0, introduzca otro valor");
    }
    return num/den;

}

int main(){
    //Intentará realizar la división pero si se pasa un valor como numerador o denominador que no sea un numero
    //o si el denominador es cero volverá a pedir los datos hasta que todos los datos sean correctos.
    //Basta con que un dato esté incorrecto para que vuelva a pedir otra vez todos los datos.
    try
    {
        double  num,
            den,
            res;
            cin.exceptions(ios::failbit|ios::badbit); //Aquí activamos que si hay una excepción con el cin la arroje
            cout<<"Escribe el numerador: ";
            cin>>num;
            cout<<"Escribe el denominador: ";
            cin>>den;
            res=divide(num,den);
            cout<<"La division de "<<num<<"/"<<den<<" es: "<<res<<endl;
    }

    catch(invalid_argument& e)
    {
        cout<<e.what()<<endl;
        main();
    }

    catch(ios_base::failure& e)
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"Recuerde que el numerador y el denominador debe contener valores numericos, introduzca de nuevo los valores "<<endl;
        main();
    }

    
    //Cachar por separados los dos tipos de excepciones. 
    //- invalid_argument que es cuando se pasa 0 como denominador e imprimir el mensaje de la excepción

    //- ios_base::failure que es cuando en el cin hacia un valor numérico se introduce un valor no numérico.
    //  en el catch donde se atrapa la excepcion ios_base::failure se debe resetear el cin con las siguientes instrucciones
    //  cin.clear(); //Esto lo que hace es quitar la bandera de que hubo un error
    //  cin.ignore(1000,'\n'); //Esto lo que hace es ignorar los caracteres que se pudiero haber quedado en el buffer.
    //  Finalmente en este catch imprimir un mensaje que diga algo como que el numerador y denominador deben ser numéricos
    return 0;
} 