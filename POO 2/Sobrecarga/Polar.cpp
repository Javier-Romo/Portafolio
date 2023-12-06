#include "Polar.h"
#include <math.h>

Polar::Polar(double r, double a)
{
    this->r = r;
    this->a = a;
}

Polar::Polar():Polar(0.0,0.0){}

double Polar::getR()
{
    return this->r;
}

double Polar::getA()
{
    return this->a;
}

Polar Polar::operator*(Polar a)
{
    return Polar(this -> r*a.r, this -> a+a.a);
}

Polar Polar::operator/(Polar a)
{
    return Polar(this -> r/a.r, this -> a-a.a);
}

Rectangular Polar::toRectangular()
{
    return Rectangular(this->r*cos(this->a),this->r*sin(this->a));
}

Polar Polar::operator+(Polar a)
{
    return (this->toRectangular()+a.toRectangular()).toPolar();
}

Polar Polar::operator+(Rectangular a)
{
    return *this+a.toPolar();
}

Polar Polar::operator-(Polar a)
{
    return (this->toRectangular()-a.toRectangular()).toPolar();
}