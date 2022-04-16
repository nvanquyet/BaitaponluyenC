#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int check(int a)
{
    int n = floor(sqrt(a));
    if(pow(n,2) == a)
    {
        return 1;
    }
    return 0;
}

void thuchien(int n)
{
    if(n < 0)
    {
        printf("\nKhong co gia tri thoa man!");
        return;
    }
    int dem = 0;
    for(int i=0; i<= n; i++)
    {
        if(check(i))
        {
            dem++;
            printf("%-5d",i);
        }
    }
    printf("\nCo %d so chinh phuong nho hon %d",dem,n);
}

int main()
{
    int n;
    printf("\nNhap vao so nguyen n: ");
    scanf("%d",&n);
    thuchien(n);
    return 0;
}

