#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>

#define R (2.5 * 10 * 10)
#define L 0.6
#define C (3.5 * pow(10, -6))
#define F 60
#define VMAX (1.5 * 10 * 10)

void solution1(void)
{
    float XL, XC, Z, IMAX;

    XL = 2 * M_PI * F * L;
    XC = 1 / (2 * M_PI * F * C);
    Z = sqrt(pow(R, 2) + pow((XL - XC), 2));
    IMAX = VMAX / Z;

    printf("solution1 = %f", IMAX);
}

void solution2(void)
{

}

int main(void)
{
    solution1();
    solution2();

    return 0;
}