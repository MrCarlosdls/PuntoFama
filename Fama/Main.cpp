#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>

using namespace std;

bool checkDigits(string param);
void checkEquality(string random, string valor);

int main()
{
	srand(time(NULL));

	string cadena;
	bool x;

	do
	{
		int num = 1000 + rand() % 9999;
		cadena = to_string(num);
		x = checkDigits(cadena);
		if (x == true)
		{
			cout << "Paso" << endl;
			cout << cadena << endl;
		}
	} while (x != true);

	string valor;
	int oportunidad = 1;
	do
	{
		cout << "Digite el valor" << endl;
		cin >> valor;
		checkEquality(cadena, valor);

		oportunidad++;
	} while (valor != cadena && oportunidad != 10);

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
	char p = 'p';
	char f = 'f';
	int x = 0;

	for (int i = 0; i < random.length(); i++)
	{
		if (random.at(i) == valor.at(0) || random.at(i) == valor.at(1) || random.at(i) == valor.at(2) || random.at(i) == valor.at(3))
		{
			if (random.at(i) == valor.at(0))
			{
				x = 0;
			}
			else if (random.at(i) == valor.at(1))
			{
				x = 1;
			}
			else if (random.at(i) == valor.at(2))
			{
				x = 2;
			}
			else if (random.at(i) == valor.at(3))
			{
				x = 3;
			}
			if (i != x)
			{
				cout << "p" << endl;
			}
			else
			{
				cout << "f" << endl;
			}
		}

	}
}