#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//	Прототип процедуры для запроса значений у пользователя.
void Give_me_numbers(int& A, int& B, int& C, int& D);

//	Прототип процедуры для вызова процедур для пар.
void Couple(int& A, int& B, int& C, int& D, float& Amean, float& Gmean);

//	Прототип процедуры Mean.
void Mean(int X, int Y, float& Amean, float& Gmean);

//	Прототип процедуры "красивого" вывода.
void Print_me(char X, char Y, float& Amean, float& Gmean);

int main()
{
	//	Объявляем переменные для хранения.
	float Amean, Gmean;
	int A, B, C, D;

	//	Вызываем процедуру для запроса значений.
	Give_me_numbers(A, B, C, D);

	//	Запускаем расчет средних для пар.
	Couple(A, B, C, D, Amean, Gmean);

	system("pause");
	return 0;
}

//	Процедура для запроса у пользователя значений.
void Give_me_numbers(int& A, int& B, int& C, int& D)
{
	/*	Запрос у пользователя значений для
	A, B, C, D. */

	while (A <= 0 && B <= 0 && C <= 0 && D <= 0)
	{
		cout << "\n Please, give me, your \n A: ";
		cin >> A;

		cout << " B: ";
		cin >> B;

		cout << " C: ";
		cin >> C;

		cout << " D: "; cin >> D;
		cout << endl;
	}
}

//	Процедура для запуска средних для пар (A,B), (A,C) и (A,D).
void Couple(int& A, int& B, int& C, int& D, float& Amean, float& Gmean)
{
	for (char chr = 'B'; chr < 'E'; chr++)
	{
		switch (chr)
		{
		case 'B':

			//	Вызов процедуры для средних.
			Mean(A, B, Amean, Gmean);

			//	Печать.
			Print_me('A', 'B', Amean, Gmean);

			break;

		case 'C':

			//	Вызов процедуры для средних.
			Mean(A, C, Amean, Gmean);

			//	Печать.
			Print_me('A', 'C', Amean, Gmean);

			break;
		case 'D':

			//	Вызов процедуры для средних.
			Mean(A, D, Amean, Gmean);

			//	Печать.
			Print_me('A', 'D', Amean, Gmean);

			break;
		}
	}
}

/*	Процедура для нахождения среднего арифметического
	и  среднего геометрического*/

void Mean(int X, int Y, float& Amean, float& Gmean)
{
	//	Рассчет среднего арифметического.
	Amean = float(X + Y) / 2.;

	//	Рассчет среднего геометрического.
	Gmean = sqrt(float(X * Y));

}

// Процедура "красивого" вывода.
void Print_me(char X, char Y, float& Amean, float& Gmean)
{
	cout << "	Couple (" << X << ',' << Y <<
		") has average = " << Amean <<
		" and geometric mean = " << Gmean << endl;
}



