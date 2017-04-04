#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>

using namespace std;

bool checkDigits(string param);

int main()
{
	srand(time(NULL));

	string cadena;
	int num = rand() % (9999 - 1000);

	cadena = to_string(num);

	cout << cadena << endl;

	bool x = checkDigits(cadena);
	if (x == false)
		cout << "dos se repiten " << endl;
	else
		cout << "no se repiten" << endl;
		

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