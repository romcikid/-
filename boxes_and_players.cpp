#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	// Объявление и инициализация переменных.
	int m, players = 0, boxes[10] = {},
		random_nomer = 0, null = 0;
	bool nulls = false;

	// Запрос у пользователя числа M.
	cout << "\n Write your value of M: "; cin >> m;

	// Перевод на новую строку.
	cout << '\n' << endl;

	// Инициализация генератора слуайных чисел.
	srand(time(0));

	cout << "	Boxes: \n" << endl;

	/* Запуск цикла для заполнения шкатулок  
	и вывода их содержимого на экран */

	for (int i = 0; i < 10; i++)
	{
		/* Если все деньги израсходованы раньше, то
		оставшиеся шкатулки остаются пустыми  */

		if (m <= 0)
			boxes[i] = 0;

		/* Если мы дошли до последней шкатулки, то
		заполняем ее оставишимися деньгами. */

		else if (i == size(boxes) - 1)
			boxes[i] = m;

		/* Иначе заполняем шкатулки
		стандартным способом*/

		else
		{
			boxes[i] = rand() % (m / 15 + 1);
			m -= boxes[i];
		}

		// Вывод содержимого очередной шкатуки на экран.
		cout << setw(5) << boxes[i];
	}
	
	// Завершение строки и заголовок таблицы участников.
	cout << "\n\n	Our players: \n" << endl;

	// Запускаем бесконечный цикл.
	while (1)
	{
		random_nomer = rand() % size(boxes);

		// Если шкатуока не пуста, то ...
		if (boxes[random_nomer] != 0)
		{

			// инкрементация кол-ва игроков,
			players++;

			// вывод на экран победителя и его выигрыша,
			cout << setw(5) << players <<
				setw(5) << boxes[random_nomer] << " p." << endl;

			// "опустошение" шкатулки.
			boxes[random_nomer] = 0;
		}
		else
		{
			/* Запускаем цикл для проверки шкатулок
			 на пустоту */
			for (int i = 0; i < size(boxes); i++)
			{
				/* Если шкатулка пуста, то увеличиваем
				счетчик пустых шкатулок */

				if (boxes[i] == 0)
					null++;

				// иначе прекращаем просмотр шкатулок.
				else
				{
					null = 0;
					break;
				}
			}
		}

		/* Если все шкатулки пусты,
			то прекращаем игру */

		if (null == size(boxes))
			break;
	}
			
	// Завершение строки.
	cout << endl;

	system("pause");
	return 0;
}
