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
	} 
	while (x != true);

	string valor;
	int oportunidad = 1;
	do
	{
		cout << "Digite el valor" << endl;
		cin >> valor;

		oportunidad++;
	} 
	while (valor != cadena && oportunidad != 10);

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

}