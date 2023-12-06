#ifndef RECTANGULAR_H
#define RECTANGULAR_H
#include <string>
#include <iostream>
#include "Polar.h"
#include <math.h>

using namespace std;

class Polar;

class Rectangular
{
    private:
        double x;
        double y;
    public:
        Rectangular();
        Rectangular(double x, double y);
        double getX();
        double getY();

        Rectangular suma(Rectangular a);

        string toString();
        Polar toPolar();
        Rectangular operator+(Rectangular b);
        Rectangular operator+(Polar p);
        Rectangular operator-(Rectangular a);
        Rectangular operator*(Rectangular a);
        Rectangular operator/(Rectangular a);

        friend ostream& operator<<(ostream& os,const Rectangular& rec)
        {
            os<<"("<<rec.x<<","<<rec.y<<")";
            return os;
        }

        
};
#endif