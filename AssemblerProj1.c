#include <stdio.h>

void main()
{
	char y, z;
	short int x, v;
	scanf_s("%d%d%d", &x, &y, &z);

	__asm
	{
		mov al, z
		add al, -3
		mov ah, 0
		mov bx, x
		mul bx
		add ax, 1
		mov bl, y
		mov bh, 0
		add bx, -1
		div bx
		add ax, 1
		mov v, ax
	}
	printf("%d", v);
}
