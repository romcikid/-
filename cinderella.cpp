#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	// Объявление и инициализация переменных.
	int  minutes = 0, hours = 0, days = 0, time = 0, birds = 3452; long long seeds = 5345453567;
	float q = 0.05;

	/* Запускаем цикл для подсчета времени (в минутах),
	необходимого птицам для выполнения работы Золушки */

	while (seeds - birds > 0)
	{
		seeds -= birds;
		birds += birds * q;
		time += 5;
	} 

	/* Разбиение времени, полученного выше на дни,
	часы и минуты. */

	while (time > 0)
	{
		// Проверка на количетсво дней.
		if (time >= 1440)
		{
			days++;
			time -= 1440;
		}

		// Проверка на количество часов.
		else if (time >= 60)
		{
			hours++;
			time -= 60;
		}

		// Иначе переводим в минуты.
		else
		{
			minutes = time;
			break;
		}
	}

	/* Вывод на экран кол-во времени, необходимого птицам
	для выполнения работы Золушки */

	cout << "\n Birds need " << days << " days, " << hours <<
		" hours and " << minutes << " minutes to do Cinderella's job." << endl;

	system("pause");
	return 0;
}
