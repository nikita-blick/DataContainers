#include<iostream>
using namespace std;

void elevator(int floor);
int Factorial(int n);
double Power(double a, int n);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите номер этажа: "; cin >> n;
	elevator(n);
	//cout << "Recusion";
	//main();
}
void elevator(int floor)
{
	if (floor == 0)
	{
		cout << "Вы в подвале" << endl;
		return;
	}
	cout << "Вы на " << floor << " этаже" << endl;
	elevator(floor - 1);
	cout << "Вы на " << floor << " этаже" << endl;
}

int Factorial(int n)
{
	if (n == 0)
		return 1;
	else
		return n * Factorial(n - 1);
}
double Power(double a, int n)
{
	if (n == 0) return 1;
	if (n > 0) return a * Power(a, n - 1);
	return 1 / Power(a, -n);
}