#include<stdio.h>
int main()
{
FILE *fp;
fp=fopen("rv15.php","w");
fprintf(fp,"<?php\n");
fprintf(fp,"$ratings[15]=1500;\n");
fprintf(fp,"$scores[15]=0;\n");
fprintf(fp,"?>\n");
fclose(fp);
return 0;
}
