#include<stdio.h>
int main()
{
int shape_id,size1,size2,size3;
float s1,s2,s3, size,core_size,inter_dia,coat_ratioI,coat_ratioII,ratio;                                                                                                                                                                            FILE *fr, *fp;
/*core-shell*/
printf("You have selected core-shell particle\n");
printf("Enter the outer diameter of the core-shell particle in µm\t");
scanf("%f", &size);
printf("\nEnter the core diameter of the core-shell particle in µm\t");
scanf("%f", &core_size);
s1=size*10000;
size1=(int)s1;
s2=core_size*10000;
size2=(int)s2;
fp=fopen("size.txt","w");
fprintf(fp,"%f", size);	/*stores µm diameter value to pass to adda*/
fclose(fp);
fp=fopen("size1.txt","w");	/*stores nm diameter value to pass to output file name*/
fprintf(fp,"%d", size1);
fclose(fp);
fp=fopen("core_size.txt","w");
fprintf(fp,"%f", core_size);	/*stores µm core diameter value to pass to adda*/
fclose(fp);
fp=fopen("size2.txt","w");	/*stores nm core diameter value to pass to output file name*/
fprintf(fp,"%d", size2);
fclose(fp);
ratio=core_size/size;
fp=fopen("ratio.txt","w");	/*stores core to outer diameter ratio for adda*/
fprintf(fp,"%f", ratio);
fclose(fp);
return(0);
}
