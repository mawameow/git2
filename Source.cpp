#include <iostream>
#include <ctime>
using namespace std;

void createArray(int ***a, int ***mas, int *n, int *m, int *k)
{
	*k = 0;
	if ((*a) != NULL)
	{
		for (int i = 0; i < *n; i++)
		{
			delete[](*a)[i];
		}
		delete[](*a);
	}

	if ((*mas) != NULL)
	{
		for (int j = 0; j < *m; j++)
		{
			delete[](*mas)[j];
		}
		delete[] * mas;
		*mas = NULL;
	}

	do
	{
		cout << "������� ���������� ����� ������� ";
		cin >> *n;
		cout << "������� ���������� �������� ������� ";
		cin >> *m;
		cout << "\n";
	} while (*n < 1 || *m < 1 || (*m == 1 && *n == 1));

	(*a) = new int*[*n];
	for (int i = 0; i < *n; i++)
	{
		(*a)[i] = new int[*m];
	}

	int num = 0;
	do
	{
		cout << "\n������ �������� ������� ������� - ������� 1\n"
			"��������� ������� ���������� ������� - ������� 2\n\n";
		cin >> num;
		if (num != 1 && num != 2)
			cout << "������ ������ ���� ���!";
	} while (num != 1 && num != 2);

	cout << "\n";

	switch (num)
	{
	case (1): // ���������� ������� ������ ������� � ����������
	{
		cout << "������� �������� �������\n";
		for (int i = 0; i < *n; i++)
		{
			for (int j = 0; j < *m; j++)
			{
				cin >> (*a)[i][j];
			}
		}
	}
	break;

	case (2):  // ���������� ������� �������� 
	{
		srand(time(0));
		for (int i = 0; i < *n; i++)
		{
			for (int j = 0; j < *m; j++)
			{
				(*a)[i][j] = rand() % 101 - 50;
			}
		}
	}

	break;
	default:
		cout << "������ ������ ���� ���!\n\n";
	}
}

void handleArray(int ***a, int ***mas, int *n, int *m, int *k)
{
	if ((*a) != NULL)
	{
		if (*mas == NULL)
		{
			(*mas) = new int*[*m];
			for (int i = 0; i < *m; i++)
			{
				(*mas)[i] = new int[*n];
			}
			cout << "\n";

			for (int i = 0; i < *m; i++) // ���������������� �������
			{
				for (int j = 0; j < *n; j++)
				{
					(*mas)[i][j] = (*a)[j][i];
				}
			}
		}
		if (*k == 0)
		{
			cout << "����������������� �������: \n";
			for (int i = 0; i < *m; i++) // ����� �� ����� ����������������� �������
			{
				for (int j = 0; j < *n; j++)
				{
					cout << (*mas)[i][j] << " ";
				}
				cout << "\n";
			}
			cout << "\n";
		}
		else
		{
			cout << "����������������� �������: \n";
			for (int i = 0; i < *n; i++)
			{
				for (int j = 0; j < *m; j++)
				{
					cout << (*a)[i][j] << " ";
				}
				cout << "\n";
			}
			cout << "\n";
		}
		if (*k == 0)
		{
			*k = 1;
		}
		else
		{
			*k = 0;
		}
	}
	else
	{
		cout << "������ ��� �� �����!\n";
	}

}

void printArray(int ***a, int ***mas, int *n, int *m, int *k)
{
	if ((*a) != NULL)
	{

		if (*k == 0)
		{
			for (int i = 0; i < *n; i++)
			{
				for (int j = 0; j < *m; j++)
				{
					cout << (*a)[i][j] << " ";
				}
				cout << "\n";
			}
		}
		else
		{
			for (int i = 0; i < *m; i++)
			{
				for (int j = 0; j < *n; j++)
				{
					cout << (*mas)[i][j] << " ";
				}
				cout << "\n";
			}
			cout << "\n";
		}
	}
	else
	{
		cout << "������� �������� ������!\n\n";
	}
}



int main()
{
	setlocale(LC_ALL, "rus");
	int **a = NULL;
	int **mas = NULL;
	int n = 0, m = 0, num = 0, k = 0;

	while (true)
	{
		cout << "1. ������� �������\n"
			"2. ���������� �������\n"
			"3. ������� ������� �� �����\n"
			"4. �������� �����\n"
			"5. �����\n";


		cin >> num;

		switch (num)
		{
			// �������� �������
		case (1):
			createArray(&a, &mas, &n, &m, &k);
			break;

			// ��������� �������
		case (2):
			handleArray(&a, &mas, &n, &m, &k);

			break;

			// ����� �������
		case (3):
			printArray(&a, &mas, &n, &m, &k);
			break;

			// ������� ������
		case (4):
			system("cls");
			break;

			// �����
		case (5):
			return 0;

			// ���� num ������� �����������
		default:
			cout << "������ ������ ���� ���!\n";
		}
	}
}
