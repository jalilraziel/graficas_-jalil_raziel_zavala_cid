// proyecto 1.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "vector"
#include "conio.h"
using namespace std;

struct Puntos
{
	float X, Y, Z;
};

int main()
{
	long i = 0, i2 = 0, i3 = 0, Tamaño ;
	int contador;
	fstream  Modelo;
	char a[16], buffer2 [] = "Mesh mesh";
	Modelo.open("Pig.X", ios_base::in, ios_base::binary);
	
	if (Modelo.is_open())
	{
		cout << "buffer craedo" << endl;
	}
	else
	{
		cout << "No se pudo cargar el archivo" << endl;
	}
	
	Modelo.seekg(0, Modelo.end);
	Tamaño = Modelo.tellg();
	Modelo.seekg(0, Modelo.beg);	
	char * buffer = new char[Tamaño];
	Modelo.read(buffer, Tamaño);
	cout << Tamaño << endl;
  	
	cout << "enter de 1 en 1, espaciadora y enter para imprimir todo" << endl;
	while (i2 != 9)
	{

		if (buffer[i] == buffer2[i2])
		{
			i++;
			i2++;
		}
		else
		{
			i++;
			i2 = 0;
		}
		if (i == Tamaño)
		{
			i2 = 9;
			cout << "no localizadao" << endl;
			return 0;
		}
	}
	while (buffer[i] != '{')
	{
		i++;
	}
	i = i + 4;
	for (int i3 = 0; i3 < 4; i3++)
	{
		a[i3] = buffer[i];
		i++;
	} 
	i++;
	contador = atoi(a);
	
	Puntos Coordenada;
	char c = 0;
	do
	{
		for (i3 = 0; buffer[i] != ';'; i3++)
		{
			a[i3] = buffer[i];
			i++;
		}
		i++;
		Coordenada.X = atof(a);
		for (i3 = 0; buffer[i] != ';'; i3++)
		{
			a[i3] = buffer[i];
			i++;
		}
		i++;
		Coordenada.Y = atof(a);
		for (i3 = 0; buffer[i] != ';'; i3++)
		{
			a[i3] = buffer[i];
			i++;
		}
		i++;
		i++;
		Coordenada.Z = atof(a);
		cout << Coordenada.X << ", " << Coordenada.Y << ", " << Coordenada.Z << endl;
		c = getchar();
	} while (c != 32);


	for (int w = 0; w < contador; w++)
	{
		for (i3 = 0; buffer[i] != ';'; i3++)
		{
			a[i3] = buffer[i];
			i++;
		}
		i++;
		Coordenada.X = atof(a);
		for (i3 = 0; buffer[i] != ';'; i3++)
		{
			a[i3] = buffer[i];
			i++;
		}
		i++;
		Coordenada.Y = atof(a);
		for (i3 = 0; buffer[i] != ';'; i3++)
		{
			a[i3] = buffer[i];
			i++;
		}
		i++;
		i++;
		Coordenada.Z = atof(a);
		cout << Coordenada.X << ", " << Coordenada.Y << ", " << Coordenada.Z << endl;
	}

	system("pause");

    return 0;

}

