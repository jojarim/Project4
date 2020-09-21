#include <stdio.h>
#define YMAX 21

typedef struct {
	char name[20];
	int height;
	double vision;
}PhysCheck;

double ave_height(const PhysCheck dat[], int n)
{

	int i;
	double sum = 0;
	for (i = 0; i < n; i++)
		sum += dat[i].height;
	return sum / n;
}

void dist_vision(const PhysCheck dat[], int n ,int dist[])
{
	int i;
	for (i = 0; i < YMAX; i++)
		dist[i] = 0;
	for (i = 0; i < n; i++)
		if (dat[i].vision >= 0.0 && dat[i].vision <= YMAX / 10.0)
			dist[(int)(dat[i].vision * 10)]++;
}

int main(void)
{
	int i;
	PhysCheck x[] = {
		{"������",162,0.3},
		{"������",173,0.7},
		{"������",175,2.0},
		{"ȫ����",171,1.5},
		{"�̼���",168,0.4},
		{"�迵��",174,1.2},
		{"�ڿ��",169,0.8}

	};
	int nx = sizeof(x) / sizeof(x[0]);
	int vdist[YMAX];
	puts("##��ü�˻�ǥ##");
	puts("   �̸�   Ű  �÷�");
	puts("-------------------");
	for (i = 0; i < nx, vdist){
		printf("%-18.18s%4d%5.1f\n", x[i].name, x[i].name, x[i].height, x[i].vision);
	printf("\m���Ű:%5.1f cm\n", ave_height(x, nx));
	dist_vision(x, nx, vdist);
	printf("\n�÷º���\n");
	for(i=0; i<YMAX; i++)
		printf("%3.1f~:%2d��\n", i / 10.0, vdist[i]);
		
		return 0;
}