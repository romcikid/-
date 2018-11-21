#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	// Объявление и инициализация переменных.
	int a1, a2, a3; float d=0, min = 10;

	// Запрос у пользователя значений длин сторон треугольника.
	cout << "\n Please, enter a1, a2 and a3 with whitespaces: ";
	cin >> a1 >> a2 >> a3;

	// Запуск цикла для поиска самой короткой медианы.
	for (int i = 0; i < 3; i++)
	{

		// Выбор одного из трех вариантов для расчета мадианы.
		switch (i)
		{
		case 0: d = (1. / 2)*sqrt(2 * (a3 * a3 + a2 * a2) - a1 * a1); break;
		case 1: d = (1. / 2)*sqrt(2 * (a3 * a3 + a1 * a1) - a2 * a2); break;
		case 2: d = (1. / 2)*sqrt(2 * (a1 * a1 + a2 * a2) - a3 * a3); break;
		}
		if (d < min)
			min = d;
	}

	// Вывод на экран длины самой короткой медианы.
	cout << "\n Length of the shortest median = "<<min<<endl;

	system("pause");
	return 0;
}


