//C PROGRAME FOR TOM
#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793
void calc(int, double, double, double);
void main() {
    double rad,len,theta,omega,x,v,a,n,lamda;
    int d;
    printf("Enter the crank radious: ");
    scanf("%lf",&rad);
    printf("Enter the length of connecting rod: ");
    scanf("%lf",&len);
    printf("Enter the speed of the crank(rpm): ");
    scanf("%lf",&n);
    printf("1.Theta value is given\n");
    printf("2.Theta value is not given\n");
    printf("Enter your option: ");
    scanf("%d",&d);
    switch(d){
        case 1:
            printf("Enter the crank angle theta: ");
            scanf("%lf",&theta);
            break;
        case 2:
            printf("The default value of theta is 0\n");
            printf("______________________________________________\n");
            theta = 0;
            break;
    }
    lamda = len/rad;
    omega = ((2*PI*n)/60.0);
    if(theta == 0){
        double angles[] = {0, 30, 45, 60, 90, 180};
        for (int i = 0; i < 6; i++) {
            calc(angles[i], lamda, omega, rad);
        }
    }else{
        calc(theta,lamda,omega,rad);
    }
    printf("<--That code was written by Thamizharasan D-->");
}
void calc(int theta, double lamda, double omega, double rad){
    double i1,x,v,a;
    // if i1 is the value of theta in rad/s
    i1 = theta*(PI/180.0);
    printf("At theta = %d degrees:\n", theta);
    x = (rad)*((1-cos(i1))+((pow(sin(i1),2))/(2*lamda)));
    printf("The value of Displacement: %lf m\n",x);
    v = (omega*rad)*(sin(i1)+((sin(2*i1))/(2*lamda)));
    printf("The value of Velocity: %lf m/s\n",v);
    a = ((pow(omega,2))*rad)*((cos(i1))+((cos(2*i1))/lamda));
    printf("The value of Acceleration: %lf m/s²\n",a);
    printf("______________________________________________\n");
}