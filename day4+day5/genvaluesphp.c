#include<stdio.h>
int main()
{
int i;
printf("<?php\n");
for(i=1;i<=15;i++)
{
printf("include('./values/rv%d.php');\n",i);
}
printf("?>\n");

return 0;
}

