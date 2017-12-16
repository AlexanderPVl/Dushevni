#include <stdio.h>
#include <malloc.h>
#include <math.h>

struct Point
{
	double x, y;
};

struct Straight
{
	/* Straight sets with points P1 and P2 */
	struct Point P1, P2;
};

double DistToCurve(struct Straight Str, struct Point Pnt)
{
	double x1, x2, y1, y2;
	x1 = Str.P1.x;
	x2 = Str.P2.x;
	y1 = Str.P1.y;
	y2 = Str.P2.y;
	double dist = fabs((y2 - y1)*Pnt.x - (x2 - x1)*Pnt.y + x2*y1 - y2*x1) / sqrt(pow((y2 - y1), 2) + pow((x2 - x1), 2));
	printf("x1 = %lf, y1 = %lf, x2 = %lf, y2 = %lf\n\n\n", x1, y1, x2, y2);
	return dist;
}

double Task(struct Point *Poly, struct Point Pnt, int k)
{
	int i = 0;
	k--;
	float dist, mindist;
	struct Straight Str;
	Str.P1 = *(Poly + k);
	Str.P2 = *Poly;
	mindist = DistToCurve(Str, Pnt);
	for (; i < k; i++)
	{
		Str.P1 = *(Poly + i);
		Str.P2 = *(Poly + i + 1);
		dist = DistToCurve(Str, Pnt);
		if (dist < mindist)
			mindist = dist;
	}
	printf("Min distance = %lf", mindist);
	return (mindist);
}

int main()
{
	struct Point *Polygon, A, PolyDot;
	int j, i, k = 0;
	printf("Enter dots coordinates:\nEnter x:\n");
	scanf("%lf", &A.x);
	printf("Enter y:\n");
	scanf("%lf", &A.y);
	printf("Enter count of point:\n");
	scanf("%d", &k);
	Polygon = (struct Point*)malloc(k * sizeof(struct Point));
	printf("Enter vertices of polygon:\n");
	for (i = 0; i < k; i++)
	{
		printf("Enter x[%d]\n", i + 1);
		scanf("%lf", &PolyDot.x);
		printf("Enter y[%d]\n", i + 1);
		scanf("%lf", &PolyDot.y);
		*(Polygon + i) = PolyDot;
	}

	Task(Polygon, A, k);

	return 0;
}
