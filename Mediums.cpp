#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//	�������� ��������� ��� ������� �������� � ������������.
void Give_me_numbers(int& A, int& B, int& C, int& D);

//	�������� ��������� ��� ������ �������� ��� ���.
void Couple(int& A, int& B, int& C, int& D, float& Amean, float& Gmean);

//	�������� ��������� Mean.
void Mean(int X, int Y, float& Amean, float& Gmean);

//	�������� ��������� "���������" ������.
void Print_me(char X, char Y, float& Amean, float& Gmean);

int main()
{
	//	��������� ���������� ��� ��������.
	float Amean, Gmean;
	int A, B, C, D;

	//	�������� ��������� ��� ������� ��������.
	Give_me_numbers(A, B, C, D);

	//	��������� ������ ������� ��� ���.
	Couple(A, B, C, D, Amean, Gmean);

	system("pause");
	return 0;
}

//	��������� ��� ������� � ������������ ��������.
void Give_me_numbers(int& A, int& B, int& C, int& D)
{
	/*	������ � ������������ �������� ���
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

//	��������� ��� ������� ������� ��� ��� (A,B), (A,C) � (A,D).
void Couple(int& A, int& B, int& C, int& D, float& Amean, float& Gmean)
{
	for (char chr = 'B'; chr < 'E'; chr++)
	{
		switch (chr)
		{
		case 'B':

			//	����� ��������� ��� �������.
			Mean(A, B, Amean, Gmean);

			//	������.
			Print_me('A', 'B', Amean, Gmean);

			break;

		case 'C':

			//	����� ��������� ��� �������.
			Mean(A, C, Amean, Gmean);

			//	������.
			Print_me('A', 'C', Amean, Gmean);

			break;
		case 'D':

			//	����� ��������� ��� �������.
			Mean(A, D, Amean, Gmean);

			//	������.
			Print_me('A', 'D', Amean, Gmean);

			break;
		}
	}
}

/*	��������� ��� ���������� �������� ���������������
	�  �������� ���������������*/

void Mean(int X, int Y, float& Amean, float& Gmean)
{
	//	������� �������� ���������������.
	Amean = float(X + Y) / 2.;

	//	������� �������� ���������������.
	Gmean = sqrt(float(X * Y));

}

// ��������� "���������" ������.
void Print_me(char X, char Y, float& Amean, float& Gmean)
{
	cout << "	Couple (" << X << ',' << Y <<
		") has average = " << Amean <<
		" and geometric mean = " << Gmean << endl;
}



