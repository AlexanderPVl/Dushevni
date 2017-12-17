#include <stdio.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "rus");
	double x1, y1, x2, y2, a, b;
	printf("Задайте прямую:\n");
	printf("введите a:\n");
	scanf("%lf", &a);
	printf("введите b:\n");
	scanf("%lf", &b);

	printf("Задайте отрезок:\n");
	printf("введите x1:\n");
	scanf("%lf", &x1);
	printf("введите y1:\n");
	scanf("%lf", &y1);
	printf("введите x2:\n");
	scanf("%lf", &x2);
	printf("введите y2:\n");
	scanf("%lf", &y2);

	if (((y2 >= a*x2 + b) && (y1 <= a*x1 + b)) || ((y1 >= a*x1 + b) && (y2 <= a*x2 + b)))
		printf("Пересекает");
	else
		printf("Не пересекает");
}
