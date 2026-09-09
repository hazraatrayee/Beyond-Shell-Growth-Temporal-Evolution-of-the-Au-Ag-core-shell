#include<stdio.h>
int main()
{
int shape_id,size1,size2,size3,size4;
float s1,s2,s3,s4, size,core_size,core_inter_dia,shell_inter_dia,coat_ratioI,coat_ratioII,coat_ratioIII;                                                                                                                                                                            FILE *fr, *fp;
/*bishell*/
printf("You have selected tri_alloy_shell particle\n");
printf("Enter the outer diameter of the tri_alloy_shell particle in µm\t");
scanf("%f", &size);
printf("\nEnter the core diameter of the tri_alloy_shell particle in µm\t");
scanf("%f", &core_size);
printf("\nEnter the core adjacent intermediate diameter of tri_alloy_shell particle in µm\t");
scanf("%f",&core_inter_dia);
printf("\nEnter the shell adjacent intermediate diameter of tri_alloy_shell particle in µm\t");
scanf("%f",&shell_inter_dia);
s1=size*10000;
size1=(int)s1;
s2=core_size*10000;
size2=(int)s2;
s3=core_inter_dia*10000;
size3=(int)s3;
s4=shell_inter_dia*10000;
size4=(int)s4;
fp=fopen("size.txt","w");
fprintf(fp,"%f", size);	/*stores µm outer diameter value to pass to adda*/
fclose(fp);
fp=fopen("core_size.txt","w");
fprintf(fp,"%f", core_size);	/*stores µm core diameter value to pass to adda*/
fclose(fp);
fp=fopen("core_inter_dia.txt","w");
fprintf(fp,"%f", core_inter_dia);	/*stores µm core adjacent intermediate diameter value to pass to adda*/
fclose(fp);
fp=fopen("shell_inter_dia.txt","w");
fprintf(fp,"%f", shell_inter_dia);	/*stores µm shell adjacent intermediate diameter value to pass to adda*/
fclose(fp);
fp=fopen("size1.txt","w");	/*stores angstrom outer diameter value to pass to output file name*/
fprintf(fp,"%d", size1);
fclose(fp);
fp=fopen("size2.txt","w");	/*stores angstrom core diameter value to pass to output file name*/
fprintf(fp,"%d", size2);
fclose(fp);
fp=fopen("size3.txt","w");	/*stores angstrom core adjacent intermediate diameter value to pass to output file name*/
fprintf(fp,"%d", size3);
fclose(fp);
fp=fopen("size4.txt","w");	/*stores angstrom shell adjacent intermediate diameter value to pass to output file name*/
fprintf(fp,"%d", size4);
fclose(fp);
coat_ratioIII=core_size/size;
fp=fopen("coat_ratioIII.txt","w");	/*stores core to outer diameter ratio for adda*/
fprintf(fp,"%f", coat_ratioIII);
fclose(fp);
coat_ratioII=core_inter_dia/size;
fp=fopen("coat_ratioII.txt","w");	/*stores core adjacent intermediate dia to outer diameter ratio for adda*/
fprintf(fp,"%f", coat_ratioII);
fclose(fp);
coat_ratioI=shell_inter_dia/size;
fp=fopen("coat_ratioI.txt","w");	/*stores shell adjacent intermediate dia to outer diameter ratio for adda*/
fprintf(fp,"%f", coat_ratioI);
fclose(fp);
return(0);
}
