#include<stdio.h>/*refractive index reading in loop in main shell script*/
int main()
{
int i,j,l,shape_id;
float a[1000][3], b[1000][3],c[1000][3],w,m1_re,m1_im,m2_re,m2_im,m3_re,m3_im;
FILE *fp,*fr1,*fr2,*fr3;
fp=fopen("count.txt","r");
fscanf(fp,"%d", &l);
fclose(fp);
/*spherical particle*/
fr1=fopen("modified_core.txt","r");
for(i=0;i<=l;i++)
{
for(j=0;j<=2;j++)
fscanf(fr1,"%f",&a[l][j]);
}
w=a[l][0];
m1_re=a[l][1];
m1_im=a[l][2];
fr2=fopen("w.txt","w");
fprintf(fr2,"%f",w);
fclose(fr2);
fr2=fopen("m1_re.txt","w");
fprintf(fr2,"%f",m1_re);
fclose(fr2);
fr2=fopen("m1_im.txt","w");
fprintf(fr2,"%f",m1_im);
fclose(fr2);
fclose(fr1);
return 0;
}
