#include <ctime>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");

	int k = 0, n = 0, m = 0;
	int b = 1, num = 0;
	int **a = NULL;
	int **mas = NULL;

	while (b)
	{
		cout << "Введите 1 - создать массив\n"
			"Введите 2 - обработать массив\n"
			"Введите 3 - вывести массив на экран\n"
			"Введите 4 - очистить экран\n"
			"Введите 5 - выход\n\n";

		cin >> num;
		cout << "\n";
		switch (num)
		{
			// Создание массива
		case (1):
		{
			k = 0;
			if (a != NULL)
			{
				for (int i = 0; i < n; i++)
				{
					delete[] a[i];
				}
				delete[] a;
			}

			if (mas != NULL)
			{
				for (int j = 0; j < m; j++)
				{
					delete[] mas[j];
				}
				delete[] mas;
				mas = NULL;
			}

			do
			{
				cout << "Введите количество строк матрицы ";
				cin >> n;
				cout << "Введите количество столбцов матрицы ";
				cin >> m;
				cout << "\n";
			} while (n < 1 || m < 1 || (m == 1 && n == 1));

			a = new int*[n];
			for (int i = 0; i < n; i++)
			{
				a[i] = new int[m];
			}

			do
			{
				cout << "\nВвести элементы матрицы вручную - введите 1\n"
					"Заполнить матрицу случайными числами - введите 2\n\n";
				cin >> num;
				if (num != 1 && num != 2)
					cout << "Такого пункта меню нет!";
			} while (num != 1 && num != 2);

			cout << "\n";

			switch (num)
			{
			case (1): // Заполнение матрицы целыми числами с клавиатуры
			{
				cout << "Введите элементы матрицы\n";
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < m; j++)
					{
						cin >> a[i][j];
					}
				}
			}
			break;

			case (2):  // Заполнение матрицы рандомно 
			{
				srand(time(0));
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < m; j++)
					{
						a[i][j] = rand() % 101 - 50;
					}
				}
			}

			break;
			default:
				cout << "Такого пункта меню нет!\n\n";
			}
		}
		break;

		case (2): // Обработка массива
		{
			if (a != NULL)
			{
				if (mas == NULL)
				{
					mas = new int*[m];
					for (int i = 0; i < m; i++)
					{
						mas[i] = new int[n];
					}
					cout << "\n";

					for (int i = 0; i < m; i++) // Транспонирование матрицы
					{
						for (int j = 0; j < n; j++)
						{
							mas[i][j] = a[j][i];
						}
					}
				}
				if (k == 0)
				{
					cout << "Транспонированная матрица: \n";
					for (int i = 0; i < m; i++) // Вывод на экран транспонированной матрицы
					{
						for (int j = 0; j < n; j++)
						{
							cout << mas[i][j] << "  ";
						}
						cout << "\n";
					}
					cout << "\n";
					k = 1;
				}
				else
				{
					cout << "Транспонированная матрица: \n";
					for (int i = 0; i < n; i++)
					{
						for (int j = 0; j < m; j++)
						{
							cout << a[i][j] << " ";
						}
						cout << "\n";
					}
					cout << "\n";
					k = 0;
				}

			}
			else
			{
				cout << "Сначала создайте массив!\n\n";
			}
		}
		break;

		case (3): // Вывод матрицы на экран
		{
			if (a != NULL)
			{

				if (k == 0)
				{
					for (int i = 0; i < m; i++)
					{
						for (int j = 0; j < n; j++)
						{
							cout << a[i][j] << " ";
						}
						cout << "\n";
					}
				}
				else
				{
					for (int i = 0; i < n; i++)
					{
						for (int j = 0; j < m; j++)
						{
							cout << mas[i][j] << " ";
						}
						cout << "\n";
					}
					cout << "\n";
				}
			}
			else
			{
				cout << "Сначала создайте массив!\n\n";
			}
		}
		break;

		case(4):
			system("cls");
			break;

		case (5): // Выход из программы
			b = 0;
			break;

		default:
			cout << "Такого пункта меню нет!\n\n";
		}
	}
	return 0;
}