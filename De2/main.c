#include <stdio.h>
#include <stdlib.h>

int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}

int a,b;

int main1()
{
    printf("Nhap vao a,b: ");
    scanf("%d%d",&a,&b);
    printf("\nUCLN cua %d va %d : %d",a,b,gcd(a,b));
    printf("\nBCNN cua %d va %d : %d",a,b,abs(a*b)/gcd(a,b));
    return 0;
}
