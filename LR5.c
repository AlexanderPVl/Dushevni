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

string InverseString(string Str)
{

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
			DeleteNumber(Str);
			DeleteElement(Str, i);
		}
	}
}

int CreateString(string Str)
{
	char c;

	while ((c = getchar()) != '.')
	{
		Str.size++;
		Str.adres = realloc(Str.adres, Str.size*sizeof(char));
		Str.adres[Str.size-1] = c;
	}
}

int main()
{
	string str1 = { NULL, 0 };

	return 0;
}
