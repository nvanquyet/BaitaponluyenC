#include<stdio.h>
#include<stdlib.h>

void xuatmatran(int a[][100],int n,int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
void docmatranlenmang(FILE *f,int a[][50],int n,int m)
{

}

void docdulieutufile(FILE *f,int a[][100],int b[][100],int n,int m)
{
    char str1[20],str2[20];
    fscanf(f,"%[^\n]\n",&str1);
    //docmatranlenmang(f,a,n,m);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            fscanf(f,"%d",&a[i][j]);
        }
        fscanf(f,"\n");
    }
    fscanf(f,"%[^\n]\n",&str2);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            fscanf(f,"%d",&b[i][j]);
        }
        fscanf(f,"\n");
    }
    //docmatranlenmang(f,b,n,m);
}
void ghixuongfile(FILE *f,int a[][100],int n,int m)
{
    char name[20];
    printf("\nNhap ten ma tran: ");
    fflush(stdin);
    gets(name);
    fprintf(f,"%s\n",name);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            fprintf(f,"%d\t",a[i][j]);
        }
        fprintf(f,"\n");
    }
}

void tong2matran(FILE *f,int a[][100],int b[][100],int n,int m)
{
    int c[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    ghixuongfile(f,c,n,m);//Tinh tong 2 ma tran r ghi xuong file
    printf("\nGhi Thanh Cong!");
}

//Nhap du lieu ma tran A va B tu ban phim
void ghidulieuxuongfile()
{
    FILE *f = fopen("MA_TRAN.txt","w");
    int hang,cot;
    printf("\nNhap so hang: ");
    scanf("%d",&hang);
    printf("\nNhap so cot: ");
    scanf("%d",&cot);
    int arr[hang][cot],brr[hang][cot];
    //nhapmatran(arr,hang,cot);
    // nhapmatran(brr,hang,cot);
    fprintf(f,"%d %d\n",hang,cot);
    ghixuongfile(f,arr,hang,cot);
    ghixuongfile(f,brr,hang,cot);
    fclose(f);

}

void menu()
{
    printf("\n1. Doc tep ma tran A, B tu tep");
    printf("\n2. Tinh ma tran C va ghi bo sung vao cuoi tep");
    printf("\n3. Ket thuc");
}
void taofilerog()
{
    FILE *f = fopen("MA_TRAN.txt","r");
    fclose(f);
}


int main()
{
    int a[50][50],b[50][50];
    int n,m;
    //taofilerog();
    //ghidulieuxuongfile();
    do
    {
        int luachon = 0;
        menu();
        printf("\nLua chon cua ban: ");
        scanf("%d",&luachon);
        if(luachon == 1)
        {
            FILE *f = fopen("MA_TRAN.txt","rt");//Mo file co the doc va ghi
            fscanf(f,"%d%d\n",&n,&m);
            docdulieutufile(f,a,b,n,m);
            xuatmatran(a,n,m);
            fclose(f);
            continue;
        }
        if(luachon == 2)
        {
            FILE *f = fopen("MA_TRAN.txt","a");
            tong2matran(f,a,b,n,m);
            fclose(f);
            continue;
        }
        if(luachon == 3)
        {
            return 0;
        }
    }
    while(1);

    return 0;
}



/*
#include<stdio.h>
#include<stdlib.h>

void xuatmatran(int a[][50],int n,int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
void docdulieutufile(int a[][50],int b[][50],int *n,int *m)
{
    FILE *f = fopen("MA_TRAN.txt","r");
    fscanf(f,"%d%d\n",n,m);
    char str1[20],str2[20];
    fscanf(f,"%s\n",str1);
    for(int i=0; i<*n; i++)
    {
        for(int j=0; j<*m; j++)
        {
            fscanf(f,"%d",&a[i][j]);
        }
        fscanf(f,"\n");
    }
    xuatmatran(a,*n,*m);
    fscanf(f,"%s\n",str2);
    for(int i=0; i<*n; i++)
    {
        for(int j=0; j<*m; j++)
        {
            fscanf(f,"%d",&b[i][j]);
        }
        fscanf(f,"\n");
    }
    xuatmatran(b,*n,*m);
    fclose(f);
}
void ghixuongfile(int a[][50],int n,int m)
{
    FILE*f = fopen("MA_TRAN.txt","a");
    char name[20];
    printf("\nNhap ten ma tran: ");
    fflush(stdin);
    gets(name);
    fprintf(f,"\n%s\n",name);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            fprintf(f,"%d\t",a[i][j]);
        }
        fprintf(f,"\n");
    }
    fclose(f);
}

void tong2matran(int a[][50],int b[][50],int n,int m)
{
    int c[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    ghixuongfile(c,n,m);//Tinh tong 2 ma tran r ghi xuong file
    printf("\nGhi Thanh Cong!");
}
void menu()
{
    printf("\n1. Doc tep ma tran A, B tu tep");
    printf("\n2. Tinh ma tran C va ghi bo sung vao cuoi tep");
    printf("\n3. Ket thuc");
}
void taofilerog()
{
    FILE *f = fopen("MA_TRAN.txt","r");
    fclose(f);
}
int main()
{
    int a[50][50],b[50][50];
    int n,m;
    do
    {
        int luachon = 0;
        menu();
        printf("\nLua chon cua ban: ");
        scanf("%d",&luachon);
        if(luachon == 1)
        {
            docdulieutufile(a,b,&n,&m);
            continue;
        }
        if(luachon == 2)
        {
            tong2matran(a,b,n,m);
            continue;
        }
        if(luachon == 3)
        {
            return 0;
        }
    }
    while(1);

    return 0;
}
*/
