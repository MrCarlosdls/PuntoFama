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
	bool x;
	
	do
	{
		int num = rand() % (9999 - 1000);
		cadena = to_string(num);
		x = checkDigits(cadena);
		if (x == true)
		{
			cout << "Paso" << endl;
			cout << cadena << endl;
		}
	} 
	while (x != true);

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