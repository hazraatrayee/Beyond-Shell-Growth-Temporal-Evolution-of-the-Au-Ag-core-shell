#include<stdio.h>
int main()
{
int s, core_id,shell_id, inter_shell_id,m1,m2,m3,i,j;
float a[1000][3],b[1000][2],c,d,e,x,y,z,n;
float *p,*q;
char core[100],shell[100],inter_shell[100];
FILE *fr, *fp, *fr1;
/*trishell*/
printf("You have selected bi_alloy_shell particle\n");
/*outer shell ri modification*/
fr=fopen("outer_shell.txt", "r");
printf("\nFor our case the outer environment is water, so r.i. of core will be modified by water");
fp=fopen("water.txt","r");
fr1=fopen("modified_shell.txt","w");
/*shell ri modification*/
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
/*intermediate shell ri modification*/
/*shell adjacent intermediate shell ri modification*/
/*identification of ri modifier of shell adjacent intermediate shell*/
printf("\nBy which will you modify the ri of shell adjacent intermediate shell?\nEnter 1 if modifier is water\nEnter 2 if modifier is outer shell material\t");
scanf("%d",&m3);
fr=fopen("shell_inter_shell.txt", "r");
if(m3==1)
fp=fopen("water.txt","r");
if(m3==2)
fp=fopen(shell,"r");
fr1=fopen("modified_shell_inter_shell.txt","w");
/*shell adjacent intermediate shell ri modification*/
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
/*identification of ri modifier of core adjacent intermediate shell*/
printf("\nBy which will you modify the ri of core adjacent intermediate shell?\nEnter 1 if modifier is water\nEnter 2 if modifier is shell material\t");
scanf("%d",&m2);
fr=fopen("core_inter_shell.txt", "r");
if(m2==1)
fp=fopen("water.txt","r");
if(m2==2)
fp=fopen(shell,"r");
fr1=fopen("modified_core_inter_shell.txt","w");
/*core adjacent intermediate shell ri modification*/
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
printf("\nCore material identification:\nFor Au_Warner et al enter 1\nFor Au_Rioux et al enter 2\nFor Ag the options are::\nFor Ag_Christy et.al enter 3\nFor Ag_Warner et al enter 4\nFor Ag_DFT_calculation enter 5\nFor Ag_Rioux et al enter 6\n");
scanf("%d", &core_id);
/*core identification*/
if(core_id==1)
sprintf(core, "Au_Warner et al.txt");
if(core_id==2)
sprintf(core, "Au_Rioux et al.txt");
if(core_id==3)
sprintf(core, "Ag_Christy et.al.txt");
if(core_id==4)
sprintf(core, "Ag_Warner et.al.txt");
if(core_id==5)
sprintf(core, "Ag_DFT_calculation.txt");
if(core_id==6)
sprintf(core, "Ag_Rioux et al.txt");
/*identification of ri modifier of core*/
printf("\nBy which will you modify the ri of core?\nEnter 1 if modifier is water\nEnter 2 if modifier is shell material\nEnter 3 if modifier is shell adjacent inter shell material\nEnter 4 if modifier is core adjacent inter shell material\t");
scanf("%d",&m1);
fr=fopen(core, "r");
if(m1==1)
fp=fopen("water.txt","r");
if(m1==2)
fp=fopen("shell.txt","r");
if(m1==3)
fp=fopen("shell_inter_shell.txt","r");
if(m1==4)
fp=fopen("core_inter_shell.txt","r");
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
