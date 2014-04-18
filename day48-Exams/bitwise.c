#include<stdio.h>
#include<stdlib.h>
int main()
{
        unsigned int a=60 ; //0011 1100
        unsigned int b=13;  //0000 1101
        int c;
    
        c = a&b;
        printf("c(&) = %d\n",c);
        c = a|b;
        printf("c(|) = %d\n",c);
        c = a^b ;
        printf("c(^) = %d\n",c);
        c = ~a;
        printf("c(~) = %d\n",c);
        c = a << 2;
        printf("c(<<) = %d\n",c);
        c = a >> 2;
        printf("c(>>) = %d\n",c);
        return 0;
}
