#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

/* Прототип функции,
проверяющий существование
треугольника.*/

bool Triangle_exists(int a, int b, int c);

/* Прототип функции,
высчитывающей площадь
треугольника*/

double Triangle_square(int a, int b, int c);

/* Прототип функции,
высчитывающей радиус
описанной окружности*/

double circumcircle(int a, int b, int c);

/* Прототип функции,
высчитывающей радиус
вписанной окружности*/

double inscribed_circle(int a, int b, int c);

// Главная функция.
int main()
{
	/* Объявление и инициализация
			переменных			*/
	int a, b, c;
	double value_circumcircle,
		value_inscribed_circle,
		sum_radius, minus_radius;

	// Отступим строчку сверху.
	cout << '\n' << endl;

	for (int i = 0; i < 3; i++)
	{	
		// Генерация случайных значений вершин.
		a = rand()%5, b = rand()%5, c = rand()%5;
		
		// Вызов функции для проверки треугольника.
		if (Triangle_exists(a, b, c))
		{
			// обращения к функциям для расчета радиусов.
			value_circumcircle = circumcircle(a, b, c);
			value_inscribed_circle = inscribed_circle(a, b, c);

			// Вычисление суммы и разности радиусов.
			sum_radius = value_circumcircle + value_inscribed_circle;
			minus_radius = value_circumcircle - value_inscribed_circle;

			// Вывод результатов на экран.
			cout << "\n	For triangle #"<< i+1<<" with tops: a = " <<
				a << ", b = " << b << " and c = " << c <<
				".\n	Radius circumcircle = " << value_circumcircle <<
				", radius inscribed_circle = "<< value_inscribed_circle <<
				".\n	Their sum = "<< sum_radius <<
				", their difference = "<< minus_radius << ".\n" << endl;
		}

		/* В случае несуществования треугольника, повторяем
		генерацию случайных вершин.*/

		else
			i--;
	}

	// Отступим еще одну строчку.
	cout << '\n' << endl;

	system("pause");
	return 0;
}

// Проверяем существование треугольника.
bool Triangle_exists(int a, int b, int c)
{
	if ((a + b > c) &&
		(a + c > b) &&
		(b + c > a))
		return true;
	else
		return false;
}

// Вычисляем площадь треугольника.
double Triangle_square(int a, int b, int c)
{
	// Расчет полупериметра.
	double semi_perimeter = (a + b + c) / 2.,

		// Расчет площади треугольника.
		square = pow(semi_perimeter*(semi_perimeter - a)*
		(semi_perimeter - b)*(semi_perimeter - c), 1. / 2.);
	return square;
}

// Вычисляем радиус описанной окружности.
double circumcircle(int a, int b, int c)
{
	double square = Triangle_square(a, b, c),
		radius = a * b * c / (4 * square);
	return radius;
}

// Вычисляем радиус вписанной окружности.
double inscribed_circle(int a, int b, int c)
{
	double square = Triangle_square(a, b, c),
		radius = square / ((a+b+c)/2.);
	return radius;
}
