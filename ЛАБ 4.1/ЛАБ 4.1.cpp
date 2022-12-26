// ЛАБ 4.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <clocale>
#include <random>

void f1(int* a, int N1, int n1)
{
	int* c;
	int* d;
	int max = 11;
	std::cout << N1 << " " << n1 << std::endl;
	if (n1 != 0) 
	{
		c = new int[n1];
		d = new int[N1 - n1];
	}
	else
	{
		c = new int[1];
		d = new int[N1 -1 ];
	}
	for (int i = 0; i < n1; i++)
	{
		c[i] = a[i];
		std::cout << "c[" << i << "]= " << c[i] << "\n";
	}
	//int size_d=0; 
	for (int i = n1; i < N1; i++)
	{
		d[i - n1] = a[i];
		std::cout << "d[" << i - n1 << "]= " << d[i - n1] << "\n";
		if (d[i - n1] > max)
			max = d[i - n1];
		// size_d ++;
	}
	std::cout << "Max element in 2nd part of massive= " << max;
	/*for (int i = 0; i < size_d; i++)
	{
		std::cout << "d[" << i << "]= " << d[i] << "\n";
	}*/

	delete []c;
	delete []d;
}

int* searchneg(int* a, int N1)
{
	int n1 = 0;
	int neg = 0;
	for (int i = 0; i < N1; i++)
	{
		if (a[i] < 0) 
		{
			neg = a[i];
			n1 = i;
		}
	}
	std::cout << "Last negative element= " << neg << "\n";
	std::cout << "Index of last negative element= " << n1 << "\n";
	return &n1;
}

int main() 
{
	srand(time(NULL));
	int N1, N2;
	N1 = rand() % 3 + 5;
	N2 = rand() % 3 + 5;
	int* a;
	int* b;
	a = new int[N1];
	b = new int[N2];
	for(int i = 0; i < N1; i++)
	{
		a[i] = rand() % 21 - 10;
		std::cout << "a[" << i << "]= " << a[i]<<"\n";
	}
	std::cout << "\n";
	for (int j = 0; j < N2; j++)
	{
		b[j] = rand() % 21 - 10;
		std::cout << "b[" << j << "]= " << b[j]<<"\n";
	}
	int ret1 = *(searchneg(a, N1));
	int ret2 = *(searchneg(b, N2));
	f1(a, N1, ret1);
	f1(b, N2, ret2);

}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
