#include <stdio.h>
#include <malloc.h>

typedef char* string;

typedef struct
{
	int IndIn;
	int IndOut;
} Word;

typedef struct
{
	Word* WordArr;
	int CouWord;
	int StrLeng;
	string Strin;
} String;

void EnterString(String* Str)
{
	char c, c1 = ' ';
	int flag = 0;
	do
	{
		c = getchar();
		if (c == ' ' && c1 == ' '){
			if (flag == 1)
			{
				Str->WordArr[Str->CouWord-1].IndOut = Str->StrLeng-1;
			}
			flag = 0;
			continue;
		}
		if (flag == 0)
		{
			Str->CouWord++;
			Str->WordArr = (Word*)realloc(Str->WordArr, (Str->CouWord)*sizeof(Word));
			Str->WordArr[Str->CouWord-1].IndIn = Str->StrLeng-1;
		}
		Str->StrLeng++;
		Str->Strin = (string)realloc(Str->Strin, (Str->StrLeng)*sizeof(string*));
		Str->Strin[Str->StrLeng - 1] = c;
		c1 = c;
		flag = 1;
	} while (c != '.');
}

void PrintString(String Str)
{
	int i = 0;
	for (; i < Str.StrLeng; i++)
	{
		printf("%c", Str.Strin[i]);
	}
}

void PrintWord(String Str, int Number)
{
	int i1 = Str.WordArr[Number-1].IndIn;
	int i2 = Str.WordArr[Number-1].IndOut;

	printf("\nWORD:  ");

	for (; i1 <= i2; i1++)
		printf("%c", Str.Strin[i1]);
}

int main()
{
	String Str = { NULL, 0, 0, NULL };

	EnterString(&Str);
	PrintString(Str);
	PrintWord(Str, 1);

	free(Str.WordArr);
	free(Str.Strin);
	return 0;
}
