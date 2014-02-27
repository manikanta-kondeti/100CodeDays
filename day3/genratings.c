#include<stdio.h>
int main()
{
int n,i,j;
printf("<?php\n");
printf("$ratings= array()\n");
for(i=0;i<320;i++)
{
	printf("$ratings[%d]=1500;\n",i);
}
printf("?>\n");
return 0;
}
