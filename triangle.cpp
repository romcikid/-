#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

/* Прототип функции,
выдающей случайную координату x.*/
int give_me_x(int begin_border, int end_border);

/* Прототип функции,
выпрашивающей координату y.*/
int give_me_y(int begin_border, int end_border);

/* Прототип функции,
выдающей коэффициент а, либо b.*/
double give_me_a_or_b(int x1, int y1, int x2, int y2, char your_choice);

// Главная функция.
int main()
{
	// Объявление массиваю
	char area[24][44];

	// Объявление переменных координат треугольника.
	int x_1, y_1, x_2, y_2, x_3, y_3;

	// Объявление коэффициентов a и b для трех точек.
	double a_1, b_1, a_2, b_2, a_3, b_3;

	// Вызов функции для получения координат.

	// Первой точки.
	x_1 = give_me_x(15, 30);
	y_1 = give_me_y(0, 8);

	// Второй точки.
	x_2 = give_me_x(0, 15);
	y_2 = give_me_y(16, 24);

	// Третьей точки.
	x_3 = give_me_x(30, 44);
	y_3 = give_me_y(8, 16);

	// Вызов функции для получения коэффициентов.

	// первой прямой.
	a_1 = give_me_a_or_b(x_1, y_1, x_2, y_2, 'a');
	b_1 = give_me_a_or_b(x_1, y_1, x_2, y_2, 'b');

	// Второй прямой.
	a_2 = give_me_a_or_b(x_1, y_1, x_3, y_3, 'a');
	b_2 = give_me_a_or_b(x_1, y_1, x_3, y_3, 'b');

	// Третьей прямой.
	a_3 = give_me_a_or_b(x_2, y_2, x_3, y_3, 'a');
	b_3 = give_me_a_or_b(x_2, y_2, x_3, y_3, 'b');

	// Вывод строки с координатами.
	cout << '\n' << " Point 1( "<< x_1 << ", " << y_1 << 
		" ), point 2( " << x_2 << ", " << y_2 <<
		") , point 3( " << x_3 << ", " << y_3 <<
		" ).\n" << endl;

	/* Вызов фукции для заполнения
	области точками.*/
	for (int i = 0; i < 24; i++)
	{
		cout << '\t';
		for (int j = 0; j < 44; j++)
		{
			// Проверка координат на принадлежность прямым.
			if ((i <= a_2 * j + b_2) ||
				(i <= a_1 * j + b_1) ||
				(i >= a_3 * j + b_3))
			{
				// Если совпадает, то оставляем область пустой.
				area[i][j] = '*';
			}
			else
				// Иначе заполняем '*'.
				area[i][j] = ' ';
			cout << area[i][j];
		}
		cout << endl;
	}

	// Пустая строка.
	cout << '\n' << endl;

	system("pause");
	return 0;
}

// Генерируем случайную координату.
int give_me_x(int begin_border, int end_border)
{
	srand(time(0));
	while (1)
	{
		int random = begin_border + rand() % end_border;

		/* Проверка случайного значения на вхождение в рамки
		(рандом чудит иногда у меня)*/

		if (random < end_border && random >= begin_border)
		{
			break;
			return random;
		}
	}
}

// Выдаем координату.
int give_me_y(int begin_border, int end_border)
{
	int i_gave;
	while (1)
	{
		// Запрос у пользователя значения координаты y.
		cout << " Please, give me your value of coordinate y between " <<
			begin_border << " and " << end_border << " : ";
		cin >> i_gave;

		/* Проверка введенного пользователем значения.
		Если есть совпадение, то возвращаем значение, иначе
		продолжаем выпрашивать */

		if ((i_gave <= end_border) && (i_gave >= begin_border))
		{
			break;
			return i_gave;
		}
	}
}

// Вычисляем коэффициенты.
double give_me_a_or_b(int x1, int y1, int x2, int y2, char your_choice)
{
	// Вычисление коэффициента а.
	double a = double(y1 - y2) / (x1 - x2),

		// Вычисление коэффициента b.
		b = y1 - a * x1;

	// Проверка варианта вывода значения.
	if (your_choice == 'a')
		return a;
	else if (your_choice == 'b')
		return b;
	else
		cout << "\n	Check your choice twice, please!" << endl;
}
