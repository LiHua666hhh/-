#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX 0x3f3f3f3f  //���������
#define M 10000
typedef struct Point
{
	int  x;
	int  y;
}Point;

int cmpx(const void * a, const void * b) //x��������
{
	return (*(Point*)a).x - (*(Point*)b).x;
}

int cmpy(const void * a, const void * b) //y��������
{
	return (*(Point*)a).y - (*(Point*)b).y;
}
double min(double a, double b)   //��������ֵ�н�С��
{
	return a < b ? a : b;
}
double ClosePoint(Point p[],int n,Point &x, Point &y)//�����㷨
{
	int dmin = MAX, d;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			d = (p[i].x - p[j].x)*(p[i].x - p[j].x) + (p[i].y - p[j].y)*(p[i].y - p[j].y);
			if (d < dmin)
			{
				dmin = d;
				x = p[i];
				y = p[j];
			}
		}
	}
	return sqrt(dmin);
}
double EfficientClosestPair(Point p[], Point q[],int n,Point &x, Point &y) {//�����㷨
	if (n <= 3) {
		return ClosePoint(p,n,x,y);
	}
	else {
		Point x1, y1,x2,y2;
		double dminsq;
		Point *p1 = new Point[n];   
		Point *p2 = new Point[n];
		Point *q1 = new Point[n];
		Point *q2 = new Point[n];
		
		for (int i = 0; i < n / 2; ++i) {
			p1[i] = p[i];
			q1[i] = q[i];
		}
		for (int i = n / 2,j=0; i < n; ++i,++j) {
			p1[j] = p[i];
			q2[j] = q[i];
		}
		double d1 = EfficientClosestPair(p1, q1,n/2,x1,y1);
		double d2 = EfficientClosestPair(p1,q2,n-n/2,x2,y2);
		double d;
		if (d1 < d2) {
			d = d1; x = x1; y = y1;
		}
		else {
			d = d2; x = x2; y = y2;
		}
		int m = p[n / 2 - 1].x;
		int num;
		Point *S = new Point[n];
		for (int i = 0, j = 0; i < n; ++i) {
			if (abs(q[i].x - m) < d) {
				S[j].x= q[i].x;
				S[j].y = q[i].y;
				++j;
				num = j;
			}
		}
		dminsq = d * d;
		for (int i = 0; i < num - 2; ++i) {
			for (int k = i + 1; k <= num - 1; ++k) {
				if ((S[k].x - S[i].x)* (S[k].x - S[i].x) + (S[k].y - S[i].y)*(S[k].y - S[i].y) < dminsq) {
					dminsq = (S[k].x - S[i].x)* (S[k].x - S[i].x) + (S[k].y - S[i].y)*(S[k].y - S[i].y);
					x = S[k];
					y = S[i];
				}
			}
		}		
		return sqrt(dminsq);
	}
}


int main()
{
	int n;
	Point dian1,dian2;
	Point p[M];
	Point q[M];
	double dmin;
	printf("�������Ϊ��");
	scanf("%d", &n);
	printf("%d\n", n);
	printf("�������꣺\n");
	for (int i = 0; i < n; i++){
		scanf("%d %d", &p[i].x, &p[i].y);
		q[i].x = p[i].x;
		q[i].y = p[i].y;
	}
	printf("�������Ϊ��\n");
	for (int i = 0; i < n; i++) {
		printf("(%d %d)\n", p[i].x, p[i].y);
	}
	qsort(p, n, sizeof(p[0]), cmpx);
	qsort(q, n, sizeof(q[0]), cmpy);

	printf("����������Ϊ��\n");
	for (int i = 0; i < n; i++) {
		printf("(%d %d)\n", p[i].x, p[i].y);
	}
	printf("����������Ϊ��\n");
	for (int i = 0; i < n; i++) {
		printf("(%d %d)\n", q[i].x, q[i].y);
	}
	dmin = EfficientClosestPair(p,q,n,dian1,dian2);
	printf("������������ǣ�%d %d �� %d %d\n", dian1.x,dian1.y, dian2.x,dian2.y);
	printf("����ľ����ǣ�%f\n", dmin);
	return 0;
}

