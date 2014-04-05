#include<stdio.h>
#include<stdlib.h>
long long int function(long long int n)
{
        int sum=0;
        while(n!=0){
                sum+=n%10;
                n/=10;
        }
        return sum;
}

int main()
{
        long long int n;
        scanf("%Ld",&n);
        while(1){
                printf("Present n: %Ld\n",n);
                if(n/10!=0){
                        n=function(n);
                }
                else {
                        printf("Sum of n: %Ld\n",n);
                        return 0;
                }
        }
        return 0;
}

