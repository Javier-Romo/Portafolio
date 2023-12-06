#include "Rectangular.h"

Rectangular::Rectangular(double x, double y)
{
    this-> x = x;
    this-> y = y;
}

Rectangular::Rectangular():Rectangular(0.0,0.0){}

double Rectangular::getX()
{
    return this -> x;
}

double Rectangular::getY()
{
    return this -> y;
}

Rectangular Rectangular::suma(Rectangular a)
{
    return *this+a;
}

string Rectangular::toString()
{
    return "("+to_string(this -> x)+","+to_string(this -> y)+")"; 
}

Rectangular Rectangular::operator+(Rectangular a)
{
     return Rectangular(this -> x+a.x, this -> y+a.y);
}

Polar Rectangular::toPolar()
{
    double r=sqrt(this->x*this->y*this->x*this->y);
    double a=atan2(this->y,this->x);
    return Polar(r,a);
}

Rectangular Rectangular::operator-(Rectangular a)
{
     return Rectangular(this -> x-a.x, this -> y-a.y);
}

Rectangular Rectangular::operator+(Polar a)
{
     return *this+a.toRectangular();
}

Rectangular Rectangular::operator*(Rectangular a)
{
     return (this->toPolar()*a.toPolar()).toRectangular();
}

Rectangular Rectangular::operator/(Rectangular a)
{
     return (this->toPolar()/a.toPolar()).toRectangular();
}