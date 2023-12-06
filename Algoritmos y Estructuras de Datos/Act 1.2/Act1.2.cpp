//Francisco Javier Romo Juárez
//A01643189
//05/09/2023

#include <iostream>
#include "vector"
using namespace std;


int ordenaInsercion(vector<int> &a)//Orden (n^2)
{
	int tmp;
	int c=0;
	for(int i=1;i < a.size();i++)
	{
		for(int j=i-1;j >= 0;j--)
		{
			c = c+1;
			if(a[j+1] < a[j])
			{
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
			else
			{
				break;
			}
		}
	}
	return c;
}

int ordenaBurbuja(vector<int> &a) //Orden (n^2)
{
	bool bandera = true;
	int tmp;
	int c=0;
	for(int i=0;i<a.size()-1 && bandera;i++)
	{
		bandera = false;
		for(int j=0;j<a.size()-i-1;j++)
		{
			c=c+1;
			if(a[j]>a[j+1])
			{
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
				bandera = true;
			}
		}
	}
	return c;
}

int mezcla(int inicio, int fin, vector<int> &a)
{
	int centro = (inicio+fin)/2;
    int j = inicio;
    int k = centro + 1;
    int size = fin - inicio + 1;
    int valoresTmp[size];
	int c=0;

    for(int i=0;i<size;i++)
    {
        if(j <= centro && k <= fin)
        {
			c = c+1;
            if(a[j] < a[k])
            {
                valoresTmp[i] = a[j++];
            }
            else
            {
                valoresTmp[i] = a[k++];
            }
        }
        else if(j <= centro)
        {
            valoresTmp[i] = a[j++];
        }
        else
        {
            valoresTmp[i] = a[k++];
        }
    }

    for(int m=0;m<size;m++)
    {
        a[inicio + m] = valoresTmp[m];
    }
	return c;
}

int mergeSort(int inicio, int fin, vector<int> &a)
{
	int c;
	if(inicio < fin)
    {
        int central=(inicio+fin)/2;
        mergeSort(inicio,central,a);
        mergeSort(central+1,fin,a);
        c=mezcla(inicio,fin,a);
    }
	return c;
}

int ordenaMerge(vector<int> &a) //Orden (n log n)
{
	int c;
	c=mergeSort(0,a.size()-1,a);
	return c;
}

int busqSecuencial(vector<int> &a, int b, int &c)//Orden (n)
{
	for (int i=0;i<a.size();i++)
	{
		c=c+1;
		if(b==a[i])
		{
			return i;
		}
	}
	return -1;
}

int busqBinaria(vector<int> &a, int b, int &c)//Orden (log2 n)
{
	int min = 0;
	int max = a.size()-1;
	int average = (min+max)/2;
	while(min <= max)
	{
		if(b == a[average])
		{
			c = c+1;
			return average;
		}
		else if(b < a[average])
		{
			c = c+1;
			max = average-1;
		}
		else
		{
			c = c+1;
			min = average+1;
		}
		average = (min+max)/2;
	}
	return -1;
}

int main(){
	vector<int> v1, v2, v3;
	int n, dato;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> dato;
		v1.push_back(dato);
		v2.push_back(dato);
		v3.push_back(dato);
	}
	cout << ordenaInsercion(v1) << " " << ordenaBurbuja(v2) << " " << ordenaMerge(v3) << endl;
	int q, pos;
	int cantBS, cantBB;
	cin >> q;
	for (int i=0; i<q; i++){
		cantBS = 0;
		cantBB = 0;
		cin >> dato;
		pos = busqSecuencial(v1, dato, cantBS);
		pos = busqBinaria(v1, dato, cantBB);
		cout << pos << " " << cantBS << " " << cantBB << endl; 
	}
}