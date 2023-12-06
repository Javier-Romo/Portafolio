#ifndef POLAR_H
#define POLAR_H
#include <iostream>
#include "Rectangular.h"


using namespace std;

class Rectangular;

class Polar
{
    private:
        double r;
        double a;
    public:
        Polar();
        Polar(double r, double a);
        double getR();
        double getA();
        Polar operator+(Polar a);
        Polar operator+(Rectangular a);
        Polar operator-(Polar a);
        Polar operator*(Polar a);
        Polar operator/(Polar a);

        Rectangular toRectangular();

        friend ostream& operator<<(ostream& os,const Polar& p)
        {
            os<<"("<<p.r<<","<<p.a<<"@)";
            return os;
        }
};

#endif