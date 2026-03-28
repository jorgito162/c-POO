/*
Jorge J Suarez
Tele 1ro
*/
#include <iostream>
#include <cmath>
using namespace std;
class Punto
{
private:
    double x, y;

public:
    Punto(double cx = 0, double cy = 0)
    {
        x = cx;
        y = cy;
    }
    double getX()
    {
        return x;
    }
    double getY()
    {
        return y;
    }
    void setX(double cx)
    {
        x = cx;
    }
    void setY(double cy)
    {
        y = cy;
    }
    double d(Punto a)
    {
        double distX = a.getX() - x;
        double distY = a.getY() - y;
        return sqrt((distX * distX) + (distY * distY));
    }
};
class Circulo
{
private:
    double radio;
    Punto centro;

public:
    Circulo(double r, Punto c)
    {
        centro = c;
        if (r > 0)
        {
            radio = r;
        }
        else
        {
            cout << " Valor incorrecto.Se asignara el valor 1. " << endl;
            radio = 1;
        }
    }
    double area()
    {
        double pi = 3.14;
        return pi * (radio * radio);
    }
    double perimetro()
    {
        double pi = 3.14;
        return 2 * pi * radio;
    }
    bool contienePunto(Punto p)
    {
        if (centro.d(p) <= radio)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    Punto centro(0, 0);
    Punto p1(3, -2);
    Punto p2(2, 5);
    Punto p3(2, 2);
    Circulo cir(4, centro);
    cout << " El area es: " << cir.area() << endl;
    cout << " El perimetro es: " << cir.perimetro() << endl;
    cout << " Punto p2: " << p2.getX() << ";" << p2.getY() << endl;
    if (cir.contienePunto(p2))
    {
        cout << " El punto p2 esta dentro del circulo " << endl;
    }
    else
    {
        cout << " El punto p2 no esta dentro del circulo " << endl;
    }
    cout << " Punto p3: " << p3.getX() << ";" << p3.getY() << endl;
    if (cir.contienePunto(p3))
    {
        cout << " El punto p3 esta dentro del circulo " << endl;
    }
    else
    {
        cout << " El punto p3 no esta dentro del circulo " << endl;
    }

    return 0;
}