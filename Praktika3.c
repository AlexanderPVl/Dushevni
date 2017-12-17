#include <stdio.h>
#include <locale.h>
#include <math.h>

int NaOtrezke(double x1, double y1, double x2, double y2, double x, double y) //функция применима в случае, если x1!=x2
{
	double a1 = (y2 - y1) / (x2 - x1);
	double b1 = y1 - a1*x1;

	if (y == x* a1 + b1)
	{
		if (((x1 <= x) && (x2 >= x)) || ((x2 <= x) && (x1 >= x)))
			if (((y1 <= y) && (y2 >= y)) || ((y2 <= y) && (y1 >= y)))
				return(1);
			else
				return (0);
		else
			return (0);

	}
	else
		return(0);
}

double SummaUglov(double x1, double y1, double x2, double y2, double x3, double y3, double x, double y)
{
	double g1 = acos(((x1 - x)*(x2 - x) + (y1 - y)*(y2 - y)) / (sqrt(pow(x1 - x, 2) + pow(y1 - y, 2))*sqrt(pow(x2 - x, 2) + pow(y2 - y, 2))));
	double g2 = acos(((x2 - x)*(x3 - x) + (y2 - y)*(y3 - y)) / (sqrt(pow(x2 - x, 2) + pow(y2 - y, 2))*sqrt(pow(x3 - x, 2) + pow(y3 - y, 2))));
	double g3 = acos(((x3 - x)*(x1 - x) + (y3 - y)*(y1 - y)) / (sqrt(pow(x3 - x, 2) + pow(y3 - y, 2))*sqrt(pow(x1 - x, 2) + pow(y1 - y, 2))));
	int og1 = sgn((x1 - x)*(y2 - y) - (x2 - x)*(y1 - y));
	int og2 = sgn((x2 - x)*(y3 - y) - (x3 - x)*(y2 - y));
	int og3 = sgn((x3 - x)*(y1 - y) - (x1 - x)*(y3 - y));
	return (g1*og1 + g2*og2 + g3*og3);
}

int NaStorone(double x1, double y1, double x2, double y2, double x3, double y3, double x, double y) //функция определяет, лежит ли точка на одной из сторон треугольника.
{
	if (x1 == x2)
	{
		if ((x == x1) && ((y >= y1) && (y <= y2)) || ((y >= y2) && (y <= y1)))
			return (1);
		else if (NaOtrezke(x1, y1, x2, y2, x, y) || NaOtrezke(x2, y2, x3, y3, x, y) || NaOtrezke(x1, y1, x3, y3, x, y))
			return (1);
		else
			return(0);
	}
	else if (x2 == x3)
	{
		if ((x == x2) && ((y >= y2) && (y <= y3) || (y >= y3) && (y <= y2)))
			return (1);
		else if (NaOtrezke(x1, y1, x2, y2, x, y) || NaOtrezke(x2, y2, x3, y3, x, y) || NaOtrezke(x1, y1, x3, y3, x, y))
			return (1);
		else
			return(0);
	}
	else if (x3 == x1)
	{
		if ((x == x1) && ((y >= y1) && (y <= y3) || (y >= y3) && (y <= y1)))
			return (1);
		else if (NaOtrezke(x1, y1, x2, y2, x, y) || NaOtrezke(x2, y2, x3, y3, x, y) || NaOtrezke(x1, y1, x3, y3, x, y))
			return (1);
		else
			return(0);
	}
	else
	{
		if (NaOtrezke(x1, y1, x2, y2, x, y) || NaOtrezke(x2, y2, x3, y3, x, y) || NaOtrezke(x1, y1, x3, y3, x, y))
			return (1);
		else
			return (0);
	}
}

int sgn(double val)
{
	if (val > 0)
		return (1);
	else if (val == 0)
		return(0);
	else if (val < 0)
		return (-1);
}

void main()
{
	setlocale(LC_ALL, "rus");
	int x1, y1, x2, y2, x3, y3;
	double x, y;
	printf("Введите координаты вершин:\n");
	printf("введите x1:\n");
	scanf("%d", &x1);
	printf("введите y1:\n");
	scanf("%d", &y1);
	printf("введите x2:\n");
	scanf("%d", &x2);
	printf("введите y2:\n");
	scanf("%d", &y2);
	printf("введите x3:\n");
	scanf("%d", &x3);
	printf("введите y3:\n");
	scanf("%d", &y3);

	printf("Введите координаты точки а:\n");
	printf("введите x:\n");
	scanf("%lf", &x);
	printf("введите y:\n");
	scanf("%lf", &y);

	x1 = (double)x1;
	y1 = (double)y1;
	x2 = (double)x2;
	y2 = (double)y2;
	x3 = (double)x3;
	y3 = (double)y3;

	if (NaStorone(x1, y1, x2, y2, x3, y3, x, y))
		printf("Точка лежит на стороне треугольника\n");
	else if (fabs(SummaUglov(x1, y1, x2, y2, x3, y3, x, y)) < 0.0001)
		printf("Точка лежит вне треугольника\n");
	else
	{
		printf("%lf\n", SummaUglov(x1, y1, x2, y2, x3, y3, x, y));
		printf("Точка лежит внутри треугольника\n");
	}

}
