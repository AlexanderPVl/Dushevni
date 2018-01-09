#include <stdio.h>

void EnterNums(int* x, int* y, int* z)
{
	do{
		printf("Enter x:\n");
		scanf_s("%d", x);
	} while (*x < -32767 || *x > 32767);
	do{
		printf("Enter y:\n");
		scanf_s("%d", y);
	} while (*y < -127 || *y > 127 || *y == 1);
	do{
		printf("Enter z:\n");
		scanf_s("%d", z);
	} while (*z < -127 || *z > 127);
}

int Calc(short int x, char y, char z)
{
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("z = %d\n", z);
	short int v = 0;

	__asm
	{
		mov eax, 0
		add z, -3
		add y, -1
		mov al, z
		cbw
		mul x // результат умножения запишется в eax
		add eax, 1
		mov edx, 0
		mov ebx, eax
		mov eax, 0
		mov al, y
		cbw
		cwde
		xchg eax, ebx
		div ebx
		add eax, 1

		mov v, ax
	}
	printf("v = %d\n", v);

	return v;
}

void main()
{
	int y, z; // byte
	int x, v; // word

	//EnterNums(&x, &y, &z);
	v = Calc(-3, 3, 6);
	//v = Calc(2835, 37, -126);
}
