#include<stdio.h>
int main()
{
FILE *fp;
fp=fopen("rv1.php","w");
fprintf(fp,"<?php\n");
fprintf(fp,"$ratings[1]=1500;\n");
fprintf(fp,"$scores[1]=0;\n");
fprintf(fp,"?>\n");
fclose(fp);
return 0;
}
