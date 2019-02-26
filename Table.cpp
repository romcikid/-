#include <iostream>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//	Прототип функции суммы ряда.
float Sum_of_row(int t);

/*	Прототип процедуры для записи значений в массив
и вывода ввиде таблицы.*/

void Back_to_the_array(float array[], int tn, int tk, int tx);

//	Прототип процедуры запроса у пользователя значений.
void Give_me_boundaries();

//	Прототип процедуры для вывода на экран таблицы.
void Table(int t, float array_element);

//	Глобальная переменная для количества.
int N, p1, p2;

int main()
{
	//	 Вызов процедуры для запроса значений у пользователя.
	Give_me_boundaries();

	float array[5+5/2];
	//	Запуск постройки таблицы.
	Back_to_the_array(array,-5, 5, 2);

	system("pause");
	return 0;
}

//	Функция для нахождения суммы ряда.

float Sum_of_row(int t)
{
	//	Первый элемент суммы.
	float element = pow(2 * t, -2) / 2.;

	//	Объявляем и инициализируем переменные.
	float sum = element;

	for (int i = 1; i < N; i++)
	{
		//	Вычисляем очередной элементы суммы.
		element *= 2. * t / ((2. * i + 1.) * (2. * i + 2.));

		//	Прибавим его к сумме.
		sum += element;
	}

	//	Возвращаем значение суммы.
	return sum;
}

// Процедура "красивого" вывода.
void Back_to_the_array(float array[], int tn, int tk, int tx)
{
	//	Шапка для, возможно, будующей таблицы.
	printf("\n t   |	S");

	//	Объявляем и инициализируем переменные.
	float S;
	int n = 0, counter = 0;

	/*	Запуск цикла. 
		Заполнение массива вычисленной суммой.
		Проверка на принадлежность границам
	(при принадлежности вывод на экран).
		Подсчет кол-ва элементов, выведенных
	на экран.
		Если таких элементов нет, то выводим
	сообщение об ошибке.
	*/

	for (int t = tn; t <= tk; t += tx)
	{
		S = Sum_of_row(t);
		array[n] = S;
		if (p1 <= array[n] &&
			p2 >= array[n])
		{
			counter++;
			Table(t, array[n]);
		}
		n++;
	}
	
	if (counter == 0)
		cout << "\n Sorry, but i haven'values in your boundaries."
		" Please, try again :)"<< endl;

	cout << '\n' << endl;
}

void Give_me_boundaries()
{
	//	Запрос у пользователя конечного числа.
	cout << " Please, give me your value of N: ";
	cin >> N;

	//	Запрос у пользователя значений границ.
	cout << " Please, give me your value of [p1, p2]: ";
	cin >> p1 >> p2;
}

void Table(int t, float array_element)
{
	printf("\n %3d |  %.2e", t, array_element);
}




