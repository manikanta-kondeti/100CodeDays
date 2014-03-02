#include<stdio.h>
int main()
{
int n,i,j;
printf("<?php\n");
printf("$scores= array()\n");
for(i=0;i<320;i++)
{
	printf("$scores[%d]=0;\n",i);
}
printf("?>\n");
return 0;
}
