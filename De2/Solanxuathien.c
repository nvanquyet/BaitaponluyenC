#include <stdio.h>
#include <stdlib.h>
int main2()
{
    int n;
    printf("Nhap vao so luong phan tu: ");
    scanf("%d",&n);
    int a[n],x;
    printf("\nNhap vao gia tri X: ");
    scanf("%d",&x);
    int dem = 0;
    printf("\nNhap vao day so: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        //a[i] = rand()%10;
        if(a[i] == x)
        {
            dem++;
        }
    }
   /* //Xuat de kiem tra ket qua neu nhap tu ban phim thi k can buoc nay
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%-5d",a[i]);
    }*/
    printf("\nSo lan xuat hien cua %d trong day la %d",x,dem);
    return 0;
}
