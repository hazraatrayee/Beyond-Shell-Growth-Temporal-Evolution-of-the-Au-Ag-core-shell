#include<stdio.h>
#include<complex.h>
#include<math.h>
int main()
{
double _Complex Drude,cp1,cp2,n1,n2,n5,n6,n7,q1,q2,q3,r1,r2,dielectric;
float c=2.99792458e17,h=4.135667516e-15,omega,n3,n4;
float GMF,GMF2,wp,gammap,einf,wg1,wo1,gamma1,A1,wo2,gamma2,A2,r,s,p,q,N,n,K,k,lambda1=0.3;
int lambda;
FILE *fr, *fp, *fr1;
float a[10][3]={{8.9234,8.5546,9.0218}, /*wp*/
{0.042389,0.022427,0.16713}, /*gammap*/
{2.2715,1.7381,2.2838}, /*einf*/
{2.6652,4.0575,3.0209}, /*wg1*/
{2.3957,3.9260,2.7976}, /*wo1*/
{0.17880,0.017723,0.18833}, /*gamma1*/
{73.251,51.217,22.996}, /*A1*/
{3.5362,4.1655,3.3400}, /*wo2*/
{0.35467,0.18819,0.68309}, /*gamma2*/
{40.007,30.770,57.540}}; /*A2*/
fr=fopen("GMF_shell_inter.txt","r");
fscanf(fr,"%f",&GMF);
fclose(fr);
GMF2=pow(GMF,2);
wp=GMF2*(2*a[0][0]-4*a[0][2]+2*a[0][1])+GMF*(-a[0][0]+4*a[0][2]-3*a[0][1])+a[0][1];
gammap=GMF2*(2*a[1][0]-4*a[1][2]+2*a[1][1])+GMF*(-a[1][0]+4*a[1][2]-3*a[1][1])+a[1][1];
einf=GMF2*(2*a[2][0]-4*a[2][2]+2*a[2][1])+GMF*(-a[2][0]+4*a[2][2]-3*a[2][1])+a[2][1];
wg1=GMF2*(2*a[3][0]-4*a[3][2]+2*a[3][1])+GMF*(-a[3][0]+4*a[3][2]-3*a[3][1])+a[3][1];
wo1=GMF2*(2*a[4][0]-4*a[4][2]+2*a[4][1])+GMF*(-a[4][0]+4*a[4][2]-3*a[4][1])+a[4][1];
gamma1=GMF2*(2*a[5][0]-4*a[5][2]+2*a[5][1])+GMF*(-a[5][0]+4*a[5][2]-3*a[5][1])+a[5][1];
A1=GMF2*(2*a[6][0]-4*a[6][2]+2*a[6][1])+GMF*(-a[6][0]+4*a[6][2]-3*a[6][1])+a[6][1];
wo2=GMF2*(2*a[7][0]-4*a[7][2]+2*a[7][1])+GMF*(-a[7][0]+4*a[7][2]-3*a[7][1])+a[7][1];
gamma2=GMF2*(2*a[8][0]-4*a[8][2]+2*a[8][1])+GMF*(-a[8][0]+4*a[8][2]-3*a[8][1])+a[8][1];
A2=GMF2*(2*a[9][0]-4*a[9][2]+2*a[9][1])+GMF*(-a[9][0]+4*a[9][2]-3*a[9][1])+a[9][1];
fr=fopen("shell_inter_shell.txt","w");
for(lambda=300;lambda<=900;lambda++)
{
omega=(h*c)/lambda;
/*calculating drude*/
r1=(omega*omega)+(omega*gammap*I);
r2=pow(wp,2)/r1;
Drude=einf-r2;
/*calculating cp1*/
n1=omega+gamma1*I;
n2=cpow(n1,2);
n3=sqrt(wg1-wo1);
n4=sqrt(wg1);
n5=csqrt(n1-wg1);
n6=csqrt(n1+wg1);
n7=1-(n2/pow(wo1,2));
cp1=(A1/n2)*((2*n4*catanh(n3/n4))-((n3*clog(n7))/2)-(n5*catan(n3/n5))-(n6*catanh(n3/n6)));
/*calculating cp2*/
q1=omega+gamma2*I;
q2=cpow(q1,2);
q3=1-(q2/pow(wo2,2));
cp2=-(A2*clog(q3))/(2*q2);
dielectric=Drude+cp1+cp2;/*calculating dielectric constant*/
/*converting to refractive index, n->real part of r.i, k->imaginary part of r.i*/
r=creal(dielectric);
s=cimag(dielectric);
p=pow(r,2)+pow(s,2);
q=sqrt(p);
N=(q+r)/2;
K=(q-r)/2;
n=sqrt(N);
k=sqrt(K);
printf("%d\t%0.3f\t%f\t%f\n", lambda,lambda1,n,k);
fprintf(fr,"%0.3f\t%f\t%f\n", lambda1,n,k);
lambda1=lambda1+0.001;
}
fclose(fr);
return 0;
}

