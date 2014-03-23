/*Pick up and Delivery with Time Windows :D */
#include<stdio.h>
#include<stdlib.h>

typedef struct customers
{
        int loc;
        int pickup;
        int delivery;
}Customer;

typedef struct Vehicle
{
        int capacity;
}Vehicle;

int main()
{
        int dis[1000][1000];
        int rows,columns,n,i,j;
        int customers, vehicles;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                {
                        scanf("%d",&dis[i][j]);
                }
        }
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                {
                        printf("dis[%d][%d]=%d\n",i,j,dis[i][j]);
                }
        }
        printf("Customer count:");
        scanf("%d",&customers);
        printf("Vehicle count:");
        scanf("%d",&vehicles);

        Customer c[customers+1];
        Vehicle v[vehicles+1];

        printf("Customer Details:\n");
        for(i=0;i<customers;i++)
        {
                printf("Customer %d\n",i+1);
                scanf("%d",&c[i].loc);
                scanf("%d",&c[i].pickup);
                scanf("%d",&c[i].delivery);
        }


        printf("Vehicle Details:\n");
        for(i=0;i<vehicles;i++)
        {
                printf("Vehicles %d\n",i+1);
                scanf("%d",&v[i].capacity);
        }

        printf("Implementing a TABU search :\n");
        return 0;
}
