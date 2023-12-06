class ListaEnteros
{
    private:
        int* valores;
        int length;  //Capcacidad del Arrgelo. Cuantos elementos se puedem guardar
        int size; //Cuántos elementos tiene actualmente el arreglo
        void swap(int& a, int& b);
        void mergeSort(int inicio, int fin);
        void mezcla(int inicio, int fin);
    public:
        ListaEnteros(int length);
        ListaEnteros(int length, int valores[]);
        void imprime();
        int busquedaSec(int valor);
        int busquedaBin(int valor);
        void bubbleSort();
        void selectionSort();
        void insertionSort();
        void mergeSort();
};