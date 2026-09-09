#include<stdio.h>
int main()
{
int shape_id,size1,size2,size3;
float s1,s2,s3, size,core_size,inter_dia,coat_ratioI,coat_ratioII,ratio;                                                                                                                                                                            FILE *fr, *fp;
printf("You have selected spherical particle\n");
printf("Enter the diameter of the sperical particle in µm\t");
scanf("%f", &size); /*stores diameter of NP in µm*/
s1=size*1000;	/*convetrs diameter in nm*/
size1=(int)s1;
fp=fopen("size.txt","w");
fprintf(fp,"%f", size);	/*stores µm diameter value to pass to adda*/
fclose(fp);
fp=fopen("size1.txt","w");	/*stores nm diameter value to pass to output file name*/
fprintf(fp,"%d", size1);
fclose(fp);
return(0);
}
