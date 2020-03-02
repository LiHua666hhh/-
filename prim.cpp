#include<stdio.h>    
#define MAX 100  
#define MAXCOST 10000000

int graph[MAX][MAX];

void prim(int graph[][MAX], int n)
{
	int Vnew[MAX];     //��ʾ��ӦDist�����
	int Dist[MAX];     //������ѡ���δѡ��֮������ڱ�
	int i, j, min, minid, sum = 0;
	for (i = 2; i <= n; ++i) { //�Լ���������г�ʼ������ΪĬ�ϴ��±�1��ʼ������i=2
		Vnew[i] = 1;
		Dist[i] = graph[1][i]; //������1���ڽӱ߶���
	}
	Vnew[1] = 0;
	for (i = 2; i <= n; i++) {
		min = MAXCOST;
		minid = 0;
		for (j = 2; j <= n; j++) {
			if (min > Dist[j] && Dist[j] != 0) { //�ҳ���С�ߺ���С�߶�Ӧ���±�
				min = Dist[j];       
				minid = j;
			}
		}
		printf("%d--->%d : ȨֵΪ��%d\n", Vnew[minid], minid, min);
		sum += min;
		Dist[minid] = 0; //minid��Ӧ����··��Ϊ0
		for (j = 2; j <= n; j++)
		{
			if (graph[minid][j] < Dist[j])  //����һ��ֱ��Ķ������·������ 
			{
				Dist[j] = graph[minid][j];
				Vnew[j] = minid; 
			}
		}
	}
	printf("��СȨֵ��Ϊ:%d", sum);
}
int main()
{
	int i, j, k, m, n;
	int cost;
	scanf("%d%d", &m, &n);//m=����ĸ�����n=�ߵĸ���  

	for (i = 1; i <= m; i++)//��ʼ��ͼ 
	{
		for (j = 1; j <= m; j++)
		{
			graph[i][j] = MAXCOST;
		}
	}
	for (k = 1; k <= n; k++)
	{
		scanf("%d%d%d", &i, &j, &cost);
		graph[i][j] = cost;
		graph[j][i] = cost;
	}
	prim(graph, m);
	return 0;
}

