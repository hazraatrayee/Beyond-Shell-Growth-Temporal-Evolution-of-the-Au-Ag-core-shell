#include<stdio.h>
#include<string.h>
int main()
{
int line_no,j,l,length,w,i,grid,size1,size2,size3;
char data[500],filename[200],filename1[500],outputfile_Cabs[500],Cext[1000],a[200];
char outputfile_Cext[500],outputfile_Qext[500],outputfile_Qabs[500];
char Qabs[500],Qext[500],Cabs[500];
float GMF_inter,GMF_outer;
FILE *fp, *fr,*fr1,*fr2,*fr3,*fr4;
fr=fopen("grid.txt", "r");
fscanf(fr, "%d", &grid);
fclose(fr);
fr=fopen("size1.txt", "r");
fscanf(fr, "%d", &size1);
fclose(fr);
fr=fopen("size2.txt", "r");
fscanf(fr, "%d", &size2);
fclose(fr);
fr=fopen("size3.txt", "r");
fscanf(fr, "%d", &size3);
fclose(fr);
fr=fopen("GMF_outer.txt", "r");
fscanf(fr, "%f", &GMF_outer);
fclose(fr);
fr=fopen("GMF_inter.txt", "r");
fscanf(fr, "%f", &GMF_inter);
fclose(fr);
sprintf(outputfile_Cext,"Cext_bi_alloy_shell,grid_%d,size_%dangs,core dia_%dangs,inter_dia_%dangs,GMF_outer_%f,GMF_inter_%f.txt",grid,size1,size2,size3,GMF_outer,GMF_inter);
sprintf(outputfile_Qext,"Qext_bi_alloy_shell,grid_%d,size_%dangs,core dia_%dangsangs,inter_dia_%d,GMF_outer_%f,GMF_inter_%f.txt",grid,size1,size2,size3,GMF_outer,GMF_inter);
sprintf(outputfile_Cabs,"Cabs_bi_alloy_shell,grid_%d,size_%dangs,core dia_%dangs,inter_dia_%dangs,GMF_outer_%f,GMF_inter_%f.txt",grid,size1,size2,size3,GMF_outer,GMF_inter);
sprintf(outputfile_Qabs,"Qabs_bi_alloy_shell,grid_%d,size_%dangs,core dia_%dangs,inter_dia_%dangs,GMF_outer_%f,GMF_inter_%f.txt",grid,size1,size2,size3,GMF_outer,GMF_inter);
fr1=fopen(outputfile_Cext,"w");
fr2=fopen(outputfile_Qext,"w");
fr3=fopen(outputfile_Cabs,"w");
fr4=fopen(outputfile_Qabs,"w");
w=300;
for(i=0;i<=600;i++)
{
sprintf(filename,"bi_alloy_shell,run_%d,grid_%d,size_%d,core_%d,inter_dia_%d/CrossSec-Y",i,grid,size1,size2,size3);
fp=fopen(filename,"r");
line_no=1;
while(fgets(data,500,fp)!=NULL)
{
sprintf(filename1,"output_of_line%d.txt",line_no);
fr=fopen(filename1,"w");
fprintf(fr,"%s",data);
line_no++;
fclose(fr);
}
/*Cext*/
fr=fopen("output_of_line1.txt","r");
fgets(a,200,fr);
length= strlen(a);
j=0;
for(l=0;l<=length;l++)
{
if(l>=7)
{
Cext[j]=a[l];
j++;
}
}
fclose(fr);
fprintf(fr1,"%d\t%s",w,Cext);
/*Qext*/
fr=fopen("output_of_line2.txt","r");
fgets(a,200,fr);
length= strlen(a);
j=0;
for(l=0;l<=length;l++)
{
if(l>=7)
{
Qext[j]=a[l];
j++;
}
}
fclose(fr);
fprintf(fr2,"%d\t%s",w,Qext);
/*Cabs*/
fr=fopen("output_of_line3.txt","r");
fgets(a,200,fr);
length= strlen(a);
j=0;
for(l=0;l<=length;l++)
{
if(l>=7)
{
Cabs[j]=a[l];
j++;
}
}
fclose(fr);
fprintf(fr3,"%d\t%s",w,Cabs);
/*Qabs*/
fr=fopen("output_of_line4.txt","r");
fgets(a,200,fr);
length= strlen(a);
j=0;
for(l=0;l<=length;l++)
{
if(l>=7)
{
Qabs[j]=a[l];
j++;
}
}
fprintf(fr4,"%d\t%s",w,Qabs);
w++;
fclose(fr);
fclose(fp);
}
fclose(fr1);
fclose(fr2);
fclose(fr3);
fclose(fr4);
return(0);
}
