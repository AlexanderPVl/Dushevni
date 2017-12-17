#include <stdio.h>
#include <math.h>
#include <locale.h>
#define N 3

int Tochka(int* adres)
{
	double s = 0;
	double sm = 0;
	int nomer = 0;
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (i == 0)
			{
				sm += sqrt(pow(*(adres + i) - *(adres + j), 2) + pow(*(adres + N + i) - *(adres + N + j), 2));
			}
			s += sqrt(pow(*(adres + i) - *(adres + j), 2) + pow(*(adres + N + i) - *(adres + N + j), 2));
		}
		if (s < sm)
		{
			sm = s;
			nomer = i;
		}
		s = 0;
	}
	return (nomer);
}

void main()
{
	setlocale(LC_ALL, "rus");

	int A[2][N];

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < N; j++)
		{
			if (i == 0)
			{
				printf("Введите x%d\n", j + 1);
				scanf("%d", &A[i][j]);
			}
			if (i == 1)
			{
				printf("Введите y%d\n", j + 1);
				scanf("%d", &A[i][j]);
			}
		}

	printf("A%d\n", Tochka(&A)+1);

}
