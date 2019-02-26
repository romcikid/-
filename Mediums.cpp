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
	//	Îáúÿâëÿåì ïåðåìåííûå äëÿ õðàíåíèÿ.
	float Amean, Gmean;
	int A, B, C, D;

	//	Âûçûâàåì ïðîöåäóðó äëÿ çàïðîñà çíà÷åíèé.
	Give_me_numbers(A, B, C, D);

	//	Çàïóñêàåì ðàñ÷åò ñðåäíèõ äëÿ ïàð.
	Couple(A, B, C, D, Amean, Gmean);

	system("pause");
	return 0;
}

//	Ïðîöåäóðà äëÿ çàïðîñà ó ïîëüçîâàòåëÿ çíà÷åíèé.
void Give_me_numbers(int& A, int& B, int& C, int& D)
{
	/*	Çàïðîñ ó ïîëüçîâàòåëÿ çíà÷åíèé äëÿ
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

//	Ïðîöåäóðà äëÿ çàïóñêà ñðåäíèõ äëÿ ïàð (A,B), (A,C) è (A,D).
void Couple(int& A, int& B, int& C, int& D, float& Amean, float& Gmean)
{
	for (char chr = 'B'; chr < 'E'; chr++)
	{
		switch (chr)
		{
		case 'B':

			//	Âûçîâ ïðîöåäóðû äëÿ ñðåäíèõ.
			Mean(A, B, Amean, Gmean);

			//	Ïå÷àòü.
			Print_me('A', 'B', Amean, Gmean);

			break;

		case 'C':

			//	Âûçîâ ïðîöåäóðû äëÿ ñðåäíèõ.
			Mean(A, C, Amean, Gmean);

			//	Ïå÷àòü.
			Print_me('A', 'C', Amean, Gmean);

			break;
		case 'D':

			//	Âûçîâ ïðîöåäóðû äëÿ ñðåäíèõ.
			Mean(A, D, Amean, Gmean);

			//	Ïå÷àòü.
			Print_me('A', 'D', Amean, Gmean);

			break;
		}
	}
}

/*	Ïðîöåäóðà äëÿ íàõîæäåíèÿ ñðåäíåãî àðèôìåòè÷åñêîãî
	è  ñðåäíåãî ãåîìåòðè÷åñêîãî*/

void Mean(int X, int Y, float& Amean, float& Gmean)
{
	//	Ðàññ÷åò ñðåäíåãî àðèôìåòè÷åñêîãî.
	Amean = float(X + Y) / 2.;

	//	Ðàññ÷åò ñðåäíåãî ãåîìåòðè÷åñêîãî.
	Gmean = sqrt(float(X * Y));

}

// Ïðîöåäóðà "êðàñèâîãî" âûâîäà.
void Print_me(char X, char Y, float& Amean, float& Gmean)
{
	cout << "	Couple (" << X << ',' << Y <<
		") has average = " << Amean <<
		" and geometric mean = " << Gmean << endl;
}



