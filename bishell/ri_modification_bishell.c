#include<stdio.h>
int main()
{
int s, core_id,shell_id, inter_shell_id,m1,m2,i,j;
float a[1000][3],b[1000][2],c,d,e,x,y,z,n;
float *p,*q;
char core[100],shell[100],inter_shell[100];
FILE *fr, *fp, *fr1;
/*bishell*/
printf("You have selected bishell particle\n");
printf("Shell material identification:\nFor Au_Warner et al enter 1\nFor Au_Rioux et al enter 2\nFor Ag the options are::\nFor Ag_Christy et.al enter 3\nFor Ag_Warner et al enter 4\nFor Ag_DFT_calculation enter 5\nFor Ag_Rioux et al enter 6\n");
scanf("%d", &shell_id);
/*shell identification*/
if(shell_id==1)
sprintf(shell, "Au_Warner et al.txt");
if(shell_id==2)
sprintf(shell, "Au_Rioux et al.txt");
if(shell_id==3)
sprintf(shell, "Ag_Christy et.al.txt");
if(shell_id==4)
sprintf(shell, "Ag_Warner et.al.txt");
if(shell_id==5)
sprintf(shell, "Ag_DFT_calculation.txt");
if(shell_id==6)
sprintf(shell, "Ag_Rioux et al.txt");
printf("\nFor our case the outer environment is water, so r.i. of core will be modified by water");
fr=fopen(shell, "r");
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
/*identification of ri modifier of intermediate shell*/
printf("\nBy which will you modify the ri of intermediate shell?\nEnter 1 if modifier is water\nEnter 2 if modifier is shell material\t");
scanf("%d",&m2);
fr=fopen("inter_shell.txt", "r");
if(m2==1)
fp=fopen("water.txt","r");
if(m2==2)
fp=fopen(shell,"r");
fr1=fopen("modified_inter_shell.txt","w");
/*intermediate shell ri modification*/
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
printf("\nBy which will you modify the ri of core?\nEnter 1 if modifier is water\nEnter 2 if modifier is shell material\nEnter 3 if modifier is inter shell material\t");
scanf("%d",&m1);
fr=fopen(core, "r");
if(m1==1)
fp=fopen("water.txt","r");
if(m1==2)
fp=fopen(shell,"r");
if(m1==3)
fp=fopen(inter_shell,"r");
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
