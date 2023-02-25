#include <stdio.h>
#define dx 0.0001

double integrate(double (*f)(double),double a,double b) {
    double area=0;
    for(double x = a;x <= b;x += dx){
        area += f(x) * dx;
    }
    return area;

}

double square(double x) {
    return x*x;
}
double cube(double x){
    return x*x*x;
}
int main(void) {
    printf("integrate(square, 0.0, 2.0)=%f\n", integrate(square, 0.0, 2.0));
    printf("integrate(cube, 0.0, 2.0)=%f\n", integrate(cube, 0.0, 2.0));
    return 0;
}