#include<stdio.h>
int main()
{
int s, core_id,shell_id, inter_shell_id,m1,m2,i,j;
float a[1000][3],b[1000][2],c,d,e,x,y,z,n;
float *p,*q;
char core[100],shell[100],inter_shell[100];
FILE *fr, *fp, *fr1;
printf("You have selected alloy sphere particle\n");
printf("\nFor our case the outer environment is water, so r.i. of core will be modified by water");
fr=fopen("core.txt", "r");
fp=fopen("water.txt","r");
fr1=fopen("modified_core.txt","w");
/*core ri modification*/
for(i=0;i<=600;i++)
{
for(j=0;j<=2;j++)
{
fscanf(fr,"%f", &a[i][j]);
fscanf(fp,"%f", &b[i][j]);
}}
for(i=0;i<=600;i++)
{
c=a[i][0];
d=a[i][1];
e=a[i][2];
n=b[i][1];
x=c/n;
y=d/n;
z=e/n;
fprintf(fr1, "%f\t%f\t%f\n",x,y,z);
}
fclose(fr);
fclose(fp);
fclose(fr1);
return(0);
}
