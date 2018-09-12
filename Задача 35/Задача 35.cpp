// Задача 35.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	do
	{
		cout << "Введіть розмірність масиву. n = "; cin >> n;
	} 
	while (n <= 0);
	cout << endl;
	double *a;
	a = new double[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Введіть елемент масиву " << i << " = "; cin >> a[i];
	}

	int k;
	do
	{
		cout << endl;
		cout << "Виберіть пункт меню (від 0 до 4), де: " << endl;
		cout << "1 - зміна масиву" << endl;
		cout << "2 - визначення мінімального елементу масиву" << endl;
		cout << "3 - обчислення кількості додатних елементів масиву" << endl;
		cout << "4 - обчислення добутку від’ємних елементів масиву" << endl;
		cout << "0 - завершення роботи програми" << endl;
		cout << "Ваш вибір - "; cin >> k;
		cout << endl;

		switch (k)
		{
			/*case 0:
			cout << "Завершення роботи програми..." << endl;
			break;*/
		case 1:
		{
			delete[] a;
			do
			{
				cout << "Введіть розмірність масиву. n = "; cin >> n;
			} 
			while (n <= 0);
			cout << endl;
			a = new double[n];
			for (int i = 0; i < n; i++)
			{
				cout << "Введіть елемент масиву " << i << " = "; cin >> a[i];
			}
		}
		break;
		case 2:
		{
			double min_value = a[0];
			int numb_min_value = 0;
			for (int i = 0; i < n; i++)
			{
				if (a[i] < min_value)
				{
					min_value = a[i];
					numb_min_value = i;
				}
			}
			cout << "Найменший елемент масиву а[" << numb_min_value << "] = " << min_value << endl;
		}
		break;
		case 3:
		{
			int kd = 0;
			for (int i = 0; i < n; i++)
			{
				if (a[i] > 0)
					kd++;
			}
			cout << "Кількість додатних елементів масиву = " << kd << endl;
		}
		break;
		case 4:
		{
			int l = 0;
			for (int i = 0; i < n; i++)
			{
				if (a[i] < 0)
					l++;
			}
			double *b = new double[l];
			int j = 0;
			for (int i = 0; i < n; i++)
			{
				if (a[i] < 0)
				{
					b[j] = a[i];
					j++;
				}
			}
			double PV = 1.0;
			if (j != 0)
			{

				for (int j = 0; j < l; j++)
				{
					PV *= b[j];
				}
			}
			else
				PV = 0;
			cout << "Добуток від'ємних елементів масиву = " << PV << endl;

			delete[] b;
		}
		break;
		/*default:
		cout << "Ви ввели невірний номер пункту меню. Зробіть Ваш вибір знову." << endl;*/
		}
	} 
	while (k != 0);
	cout << "Дякуємо за користування програмою!" << endl;

	delete[] a;
	system("pause");
	return 0;
}


