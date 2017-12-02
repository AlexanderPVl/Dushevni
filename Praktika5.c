#include <stdio.h>
#define N 5
int Array[N];

void uporyadpovozrastan(int *adr, int d)
{
	int i, j, c;
	for (i = 0; i < d; i++)
		for (j = 1; j < d; j++){
			if (*(adr + j - 1)>*(adr + j)){
				c = *(adr + j);
				*(adr + j) = *(adr + j - 1);
				*(adr + j - 1) = c;
			}
		}
}

int indexofelement(int *array, int d, int c)
{
	int i = 0, max = *array, ind = -1;
	while (i < d)
	{
		if (array[i] == c)
		{
			ind = i;
			break;
		}
		i++;
	}
	return ind;
}

int maxelement(int *adr, int d)
{
	int i, max = *adr;
	for (i = 0; i < d; i++)
	{
		if (adr[i] > max)
			max = adr[i];
	}
	return max;
}

int minafter(int *arr, int c, int d)
{
	int i;
	int result = c;
	for (i = 0; i < d; i++)
	{
		if (arr[i] > c)
		{
			result = arr[i];
			break;
		}
	}
	return result;
}

void identarr(int* arr1, int* arr2, int C)
{
	for (int i = 0; i < C; i++)
	{
		*(arr1 + i) = *(arr2 + i);
	}
}

int equalarr(int* arr1, int* arr2, int C)
{
	int j = 0;
	for (int i = 0; i < C; i++)
	{
		if (*(arr1 + i) == *(arr2 + i))
			j++;
	}
	if (j == C)
		return(0);
	else
		return(1);
}

int ObshiyElement(int* arr, int C, int d)
{
	int k = 0;
	for (int i = 0; i < d; i++)
	{
		if (C == *(arr + i))
			k++;
	}
	return((k == 0) ? 1 : 0);
}


void Printarr(int* arr, int C)
{
	for (int a = 0; a < C; a++)
	{
		printf("%d ", *(arr + a));
	}
}

void Perestanovki(int* arr1, int* arr2, int k)
{
	for (int i = 0; i < N; i++)
	{
		if (k < N)
		{
			if (ObshiyElement(arr1, *(arr2 + i), k))
			{
				*(arr1 + k) = *(arr2 + i);
				Perestanovki(arr1, arr2, k + 1);

				if (k == N - 1)
				{
					Printarr(arr1, N);
					printf("\n");
				}

			}
		}
	}



}

void Razmesheniya(int* arr1, int* arr2, int k, int m)
{
	for (int i = 0; i < N; i++)
	{
		if (k < N)
		{
			if (ObshiyElement(arr1, *(arr2 + i), k))
			{
				*(arr1 + k) = *(arr2 + i);
				Razmesheniya(arr1, arr2, k + 1, m);

				if (k == N - 1)
				{
					if (equalarr(Array, arr1, m))
					{
						identarr(Array, arr1, m);
						Printarr(arr1, m);
						printf("\n");
					}
				}

			}
		}
	}



}

void Sochetaniya(int* arr1, int* arr2, int k, int m, int count)
{
	int i;
	for (i = k; i < N / (2 - count) + 1 && i < N; i++)
		{
			if (k < N)
			{
				if (ObshiyElement(arr1, *(arr2 + i), k)) /* true if there are no equal elements*/
				{
					*(arr1 + k) = *(arr2 + i);
					Sochetaniya(arr1, arr2, k+1, m, 1);

					if (i == N - 1)
					{
						if (equalarr(Array, arr1, m))
						{
							identarr(Array, arr1, m);
							Printarr(arr1, m);
							printf("\n");
						}
					}

				}
			}
		}
}

void Sochetaniya2(int* arr1, int* arr2, int k, int m, int count)
{
	int i = 0, j, max2, min, maxind;
	max2 = maxelement(arr2, N);
	identarr(arr1, arr2, m);
	while (*arr1 < N / 2 + 1)
	{
		Printarr(arr1, m);
		printf("\n");
		maxind = indexofelement(arr1, m, max2);
		if (maxind != -1) /* true if there are no equal elements*/
		{
			min = *(arr1 + maxind - 1);
			for (j = 0; j < N; j++){
				min = minafter(arr2, min, N);
				if (ObshiyElement(arr1, min, m)){
					min = *(arr2 + j);
					break;
				}
			}
			if (min == *(arr1 + maxind - 1) || maxind == 0)
			{
				//return;
			}
			else
			{
				*(arr1 + maxind - 1) = max2;
				*(arr1 + maxind) = min;
			}
		}
		else
		{
			*(arr1 + m - 1) = minafter(arr2, *(arr1 + m - 1), N);
		}
	}
}

void main()
{
	int A[N], B[N], m, n;

	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &B[i]);
		A[i] = 0;
	}

	printf("Perestanovki:\n");

	Perestanovki(A, B, 0);

	printf("Vvedite kolichestvo elementov, dlya kotorogo naidem vse razmesheniya:\n");

	scanf_s("%d", &m);

	Razmesheniya(A, B, 0, m);

	printf("Vvedite kolichestvo elementov, dlya kotorogo naidem vse sochetaniya:\n");

	scanf_s("%d", &n);

	Sochetaniya2(A, B, 0, n, 0);
}
