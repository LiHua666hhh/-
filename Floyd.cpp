#include<stdio.h>
#define max 100
#define inf 1000000
int main() {
	int D[max][max] = { {inf,2,6,4},{inf,inf,3,inf},{7,inf,inf,1},{5,inf,12,inf} };  //��ʾͼ�и����ڵ�֮���·������D[i][j]����ΪVi����>VjȨֵΪD[i][j]
	int S[max][max];  //��ʾͼ�нڵ�ĺ�̾���,��S[i][j]����Vi����>Vj�����·���Ĵ���V S[i][j].
	int i, j, k, V,count;
	printf("����ڵ������");
	scanf("%d", &V);
	for (i = 0; i < V; ++i) { //��S���г�ʼ��
		count = 0;
		for (j = 0; j < V; ++j) {
			if(i != j){
				S[i][j] = count;
			}
			else 
				S[i][j] = -1;
			++count;
		}
	}
	for (k = 0; k < V; ++k) //V��ʾ�ڵ������
		for (i = 0; i < V; ++i)
			for (j = 0; j < V; ++j)
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];
					S[i][j] = S[i][k];
				}
	printf("��������С�������Ϊ��\n");
	for (i = 0; i < V; ++i) {//�����̾������
		for (j = 0; j < V; ++j) {
			if (i==j) {
				printf("-1 ");
			}
			else
				printf("%2d ", D[i][j]);
		}
		printf("\n");
	}

}

