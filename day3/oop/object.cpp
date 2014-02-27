#include<stdio.h>
#include<stdlib.h>
using namespace std;

class fruit
{
public :
int price;
int weight;
int amount(int x,int y);

private:
int flag;
};

int fruit::amount(int x, int y)
{
printf("Printing the private member in the class flag=%d\n",flag);
    return price*weight;
}


int main()
{
fruit apple;
printf("Enter Apples's price\n");
scanf("%d",&apple.price);
printf("Enter Apples's weight\n");
scanf("%d",&apple.weight);
printf(" Apples's weight amount \n");
printf("amount=%d\n",apple.amount(apple.price,apple.weight));
return 0;
}
