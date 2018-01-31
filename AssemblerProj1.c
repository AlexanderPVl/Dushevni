#include <stdio.h>

int Calc(signed short int x, signed char y, signed char z)
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
		mov eax, 0;
		mov ebx, 0;
		mov ecx, 0;
		mov edx, 0;
		mov al, z;
		cbw;
		sub al, 3;
		//cbw;
		mov bx, x
		imul bx; // результат умножения запишется в eax
		add ax, 1;
		adc dx, 0;
		mov bx, ax;
		mov al, y;
		cbw;
		sub ax, 1
		xchg ax, bx;
		idiv bx;
		add ax, 1;
		mov v_asm, ax;
	}
	printf("Assembler calculation: v_asm = %x\n", v_asm);
	printf("C calculation: v_c = %x\n", v_c);
	return v_asm;
}

void main()
{
	int v; // word



	v = Calc(-0x3, 0x3, 0x6);
	v = Calc(0xB13, 0x25, -0x7E);
}
