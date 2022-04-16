#include <stdio.h>
#include <stdlib.h>

void input(int a[],int n)
{
    printf("\nNhap vao day so: \n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n");
}

void output(int a[],int n)
{
    printf("\nDay so: \n");
    for(int i=0; i<n; i++)
    {
        printf("%-5d",a[i]);
    }
    printf("\n");
}
void noi(int a[],int b[],int c[],int n)
{
    int i=0,j=0,k=0;
    while((i<n) && (j<n))
    {
        if(a[i]<=b[j])
        {
            c[k] = a[i];
            i++;
            k++;
        }
        else
        {
            c[k] = b[j];
            j++;
            k++;
        }
    }
    for(;i<n;i++)
    {
        c[k] = a[i];
        k++;
    }
    for(;j<n;j++)
    {
        c[k] = b[j];
        k++;
    }
}

int main()
{
    int n;
    printf("\nNhap vao so luong phan tu: ");
    scanf("%d",&n);
    int a[n],b[n],c[n+n];
    input(a,n);
    input(b,n);
    noi(a,b,c,n);
    output(a,n);
    output(b,n);
    output(c,2*n);

    return 0;
}

