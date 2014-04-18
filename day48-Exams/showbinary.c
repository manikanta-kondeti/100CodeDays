#include<stdio.h>
void showbits(int a)
{
        // int 32bits.. 1word 
        int i,k;
        for (i=31;i>=0;i--)
        {
                k= a >> i;
                printf("%d",(k&1)?1:0);
        }
        return;
}
int main()
{
        int a;
        scanf("%d",&a);
        printf("Showing a in bits:\n");
        showbits(a);
        printf("\n");
        return 0;
}

