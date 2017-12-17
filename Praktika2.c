#include <stdio.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "rus");
	int x1, y1, x2, y2, x3, y3, x4, y4;
	double x, y, a1, b1, a2, b2;
	printf("Задайте отрезок:\n");
	printf("введите x1:\n");
	scanf("%d", &x1);
	printf("введите y1:\n");
	scanf("%d", &y1);
	printf("введите x2:\n");
	scanf("%d", &x2);
	printf("введите y2:\n");
	scanf("%d", &y2);

	printf("Задайте отрезок:\n");
	printf("введите x3:\n");
	scanf("%d", &x3);
	printf("введите y3:\n");
	scanf("%d", &y3);
	printf("введите x4:\n");
	scanf("%d", &x4);
	printf("введите y4:\n");
	scanf("%d", &y4);

	if ((x2 != x1) && (x3 != x4))
	{
		a1 = (y2 - y1) / (x2 - x1);
		b1 = y1 - x1*a1;
		a2 = (y4 - y3) / (x4 - x3);
		b2 = y3 - x3*a2;
		
		if (a1 != a2)
		{
			x = (b2 - b1) / (a1 - a2);
			y = a1*x + b1;

			if (((x1 <= x && x <= x2) || (x2 <= x && x <= x1)) || ((x3 <= x && x <= x4) || (x4 <= x && x <= x3)))
				printf("Пересекаются");
			else
				printf("Не пересекаются");
		}
		else
			printf("Не пересекаются");
	}
	else if ((x2 != x1)&&(x3=x4))
	{
		a1 = (y2 - y1) / (x2 - x1);
		b1 = y1 - x1*a1;
		if ((y1 <= a1*x3 + b1) && (y2 >= a1*x3 + b1) || (y2 <= a1*x3 + b1) && (y1 >= a1*x3 + b1))
			printf("Пересекаются");
		else
			printf("Не пересекаются");
	}
	else if ((x4 != x3) && (x3 = x4))
	{
		a2 = (y4 - y3) / (x4 - x3);
		b2 = y3 - x3*a2;
		if ((y3 <= a2*x1 + b2) && (y4 >= a2*x1 + b2) || (y4 <= a2*x1 + b2) && (y3 >= a2*x1 + b2))
			printf("Пересекаются");
		else
			printf("Не пересекаются");
	}
	else
		printf("Не пересекаются");

}
