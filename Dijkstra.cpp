#include<stdio.h>
#include<stdlib.h>
#define max 1000000
int a[1000][1000];
int d[1000];//d��ʾԴ�ڵ㵽�ýڵ����С����
int p[1000];//p��Ƿ��ʹ��Ľڵ�
int i, j, k;
int m;//m�������
int n;//n�������
int main()
{
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
		{
			if (i == j) {
				a[i][j] = 0;
			}
			else
				a[i][j] = max;
		}
	}
	int  k;
	int  x, y;
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &x, &y, &k);//�����ڽӾ���
		a[x][y] = k;
	}
	for (i = 1; i <= n; ++i) {//��ʼ����������
		p[i] = 0;
	}
	p[1] = 1;
	for (i = 1; i <= n; i++) //��ʼ��dis����Ϊa�㵽��������ľ���
	{
		d[i] = a[1][i];
	}

	for (i = 1; i < n; i++) 
	{
		int min = max,temp;
		for (j = 1; j <= n; j++)
		{
			if (!p[j] && d[j] < min) //�ҵ���1�Ŷ�������Ķ���
			{
				min = d[j];
				temp = j;
			}
		}
		p[temp] = 1;
		for (j = 1; j <= n; j++)
		{
			if (a[temp][j] < max) {
				if (a[temp][j] + d[temp] < d[j])
				{
					d[j] = a[temp][j] + d[temp];
				}
			}
		}

	}
	//���������Դ�ڵ㵽����ÿ���ڵ����С����
	for (i = 1; i < n; i++)
		printf("%d->", d[i]);
	printf("%d\n", d[n]);
	return 0;
}

