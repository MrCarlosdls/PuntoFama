#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>

using namespace std;

bool checkDigits(string param); //Funcion que me chequea si el numero se repite o no
void checkEquality(string random, string valor); //Funcion que me dice si digito un valor que esta dentro de mi
												 //valor aleatorio
int main()
{
	//Declaraciones de variables
	srand(time(NULL));
	string cadena;
	bool x;
	string valorString;
	int oportunidad = 0;
	int valor;

	//Aqui me genera los numeros aleatorios entre 1000 y 9999
	do
	{
		int num = rand() % 1000 + 8999;
		cadena = to_string(num);
		x = checkDigits(cadena);

	} while (x != true);

	//Aqui el programa esta interactuando con el usuario o el jugador
	do
	{
		do
		{
			cout << "Tienes " << (10 - oportunidad) << " oportunidades!!" << endl;
			cout << "Digite el valor de 4 numeros y que no sean iguales: " << endl;
			cin >> valor;
			valorString = to_string(valor);
			x = checkDigits(valorString);
			if (x != true || valor < 1000 || valor > 9999)
			{
				cout << "No se permiten numeros iguales o repetidos o con el cero adelante" << endl;
				system("pause");
				system("cls");
			}
		} while (x != true || valor < 1000 || valor > 9999);
		checkEquality(cadena, valorString);

		oportunidad++;
	} while (valorString != cadena && oportunidad <= 9);

	//Aqui me dice que no pudo ganar y me muestra el valor que habia que digitar
	if (oportunidad == 10)
	{
		cout << "GAME OVER " << endl;
		cout << "El valor que debio ingresar era: " << cadena << endl;
	}
	system("pause");

	return 0;
}

bool checkDigits(string param)
{

	for (int x = 0; x < param.length(); x++)
	{
		for (int y = x + 1; y < param.length(); y++)
		{
			if (param.at(x) == param.at(y))
			{
				return false;
			}
		}
	}
	return true;
}

void checkEquality(string random, string valor)
{
	int x = 0;
	int CountF = 1;

	for (int i = 0; i < random.length(); i++)
	{
		if (random.at(0) == valor.at(i) || random.at(1) == valor.at(i) || random.at(2) == valor.at(i) || random.at(3) == valor.at(i))
		{
			if (random.at(0) == valor.at(i))
			{
				x = 0;
			}
			else if (random.at(1) == valor.at(i))
			{
				x = 1;
			}
			else if (random.at(2) == valor.at(i))
			{
				x = 2;
			}
			else if (random.at(3) == valor.at(i))
			{
				x = 3;
			}
			if (i != x)
			{
				cout << "P" << " ";
			}
			else
			{
				cout << "F" << " ";
				CountF++;
			}

			if (CountF == 4)
			{
				system("cls");
				cout << "YOU WIN!!!!" << endl;
			}
		}
	}
	cout << "\n" << endl;
}