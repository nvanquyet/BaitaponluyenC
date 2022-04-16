#include<stdio.h>
#include<stdlib.h>

void docmatran(int a[][50], char *file, FILE *f, int n, int m){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			fscanf(f, "%d", &a[i][j]);
		}fscanf(f, "\n");
	}
}

void inmatran(int a[][50], int n, int m){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%d\t", a[i][j]);
		}printf("\n");
	}
}

int main3(){
	int a[50][50], b[50][50], c[50][50];
	FILE *f;
	int n, m;
	f = fopen("Ma_Tran.C", "rt");
	char ca[20];
	char cb[20];
	char cc[20];

	fscanf(f, "%d %d\n", &n, &m);
	fscanf(f, "%[^\n]\n", &ca);
	printf("%s\n", ca);
	docmatran(a, "Ma_Tran.C", f, n, m);
	inmatran(a, n, m);

	fscanf(f, "%[^\n]\n", &cb);
	printf("%s\n", cb);
	docmatran(b, "Ma_Tran.C", f, n, m);
	inmatran(b, n, m);

	fscanf(f, "%[^\n]\n", &cc);
	printf("%s\n", cc);
	docmatran(c, "Ma_Tran.C", f, n, m);
	inmatran(c, n, m);

	fclose(f);
}
