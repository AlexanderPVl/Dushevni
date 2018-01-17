#include <stdio.h>
#include <malloc.h>

/*Дана строка, содержащая от 1 до 30 слов, в каждом из которых от 1 до 10 латинских букв
и / или цифр; между соседними словами – не менее одного пробела, за последним словом – точка.
Напечатать все слова, отличные от последнего слова, предварительно преобразовав каждое из них
по следующему правилу: переписать слово задом наперед.*/

typedef struct
{
	char* adres;
	int size;
} string;

void PrintString(string Str)
{
	printf("\nSize = %d\n", Str.size);
	int i;
	for (i = 0; i < Str.size; i++)
	{
		printf("%c", Str.adres[i]);
	}
}

string InverseString(string Str)
{
	return Str;
}

void DeleteElement(string Str, int IndOfElement)
{
	for (int j = IndOfElement + 1; j < Str.size; j++)
	{
		Str.adres[j - 1] = Str.adres[j];
	}
	Str.size--;
	Str.adres = realloc(Str.adres, Str.size*sizeof(char));
}

void DeleteNumbers(string Str)
{
	for (int i = 0; i < Str.size; i++)
	{
		if (0 >= Str.adres[i] - '0' || 9 <= Str.adres[i])
		{
			DeleteNumbers(Str);
			DeleteElement(Str, i);
		}
	}
}

string CreateString(string Str)
{
	char c;

	while ((c = getchar()) != '.')
	{
		Str.adres = realloc(Str.adres, Str.size*sizeof(char));
		Str.adres[Str.size] = '1';
		Str.size++;
	}
	return Str;
}

int main()
{
	string str1 = { NULL, 0 };
	str1 = CreateString(str1);
	PrintString(str1);

	return 0;
}
