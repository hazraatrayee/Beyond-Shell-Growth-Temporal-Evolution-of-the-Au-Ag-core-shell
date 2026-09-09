#include<stdio.h>
int main()
{
int shape_id,size1,size2,size3;
float s1,s2,s3, size,core_size,inter_dia,coat_ratioI,coat_ratioII,ratio;                                                                                                                                                                            FILE *fr, *fp;
/*bishell*/
printf("You have selected bi_alloy_shell particle\n");
printf("Enter the outer diameter of the bi_alloy_shell particle in µm\t");
scanf("%f", &size);
printf("\nEnter the core diameter of the bi_alloy_shell particle in µm\t");
scanf("%f", &core_size);
printf("\nEnter the intermediate diameter of bi_alloy_shell particle in µm\t");
scanf("%f",&inter_dia);
s1=size*10000;
size1=(int)s1;
s2=core_size*10000;
size2=(int)s2;
s3=inter_dia*10000;
size3=(int)s3;
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
coat_ratioII=core_size/size;
fp=fopen("coat_ratioII.txt","w");	/*stores core to outer diameter ratio for adda*/
fprintf(fp,"%f", coat_ratioII);
fclose(fp);
fp=fopen("inter_dia.txt","w");
fprintf(fp,"%f", inter_dia);	/*stores µm intermediate diameter value to pass to adda*/
fclose(fp);
fp=fopen("size3.txt","w");	/*stores nm intermediate diameter value to pass to output file name*/
fprintf(fp,"%d", size3);
fclose(fp);
coat_ratioI=inter_dia/size;
fp=fopen("coat_ratioI.txt","w");	/*stores intermediate dia to outer diameter ratio for adda*/
fprintf(fp,"%f", coat_ratioI);
fclose(fp);
return(0);
}
