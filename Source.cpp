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
		cout << "������� 1 - ������� ������\n"
			"������� 2 - ���������� ������\n"
			"������� 3 - ������� ������ �� �����\n"
			"������� 4 - �������� �����\n"
			"������� 5 - �����\n\n";

		cin >> num;
		cout << "\n";
		switch (num)
		{
			// �������� �������
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
				cout << "������� ���������� ����� ������� ";
				cin >> n;
				cout << "������� ���������� �������� ������� ";
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
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < m; j++)
					{
						cin >> a[i][j];
					}
				}
			}
			break;

			case (2):  // ���������� ������� �������� 
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
				cout << "������ ������ ���� ���!\n\n";
			}
		}
		break;

		case (2): // ��������� �������
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

					for (int i = 0; i < m; i++) // ���������������� �������
					{
						for (int j = 0; j < n; j++)
						{
							mas[i][j] = a[j][i];
						}
					}
				}
				if (k == 0)
				{
					cout << "����������������� �������: \n";
					for (int i = 0; i < m; i++) // ����� �� ����� ����������������� �������
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
					cout << "����������������� �������: \n";
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
				cout << "������� �������� ������!\n\n";
			}
		}
		break;

		case (3): // ����� ������� �� �����
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
				cout << "������� �������� ������!\n\n";
			}
		}
		break;

		case(4):
			system("cls");
			break;

		case (5): // ����� �� ���������
			b = 0;
			break;

		default:
			cout << "������ ������ ���� ���!\n\n";
		}
	}
	return 0;
}