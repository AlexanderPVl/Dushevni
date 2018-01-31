#include <stdio.h>

int Calc(short int x, char y, char z)
{
	printf("\nRESULTS:\n");
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("z = %d\n", z);
	short int v_asm = 0;
	short int v_c = 0;
	v_c = ((z - 3)*x + 1) / (y - 1) + 1;
	__asm
	{
		mov eax, 0 // clean register
		sub z, 3
		mov al, z
		cbw
		imul x // результат умножения запишется в eax
		add ax, 1
		mov bx, ax
		sub y, 1
		mov al, y
		cbw
		xchg ax, bx
		idiv bx
		add ax, 1
		mov v_asm, ax
	}
	printf("Assembler calculation: v_asm = %d\n", v_asm);
	printf("C calculation: v_c = %d\n", v_c);
	return v_asm;
}

void main()
{
	int v; // word



	v = Calc(-3, 3, 6);
	v = Calc(2835, 37, -126);
}
