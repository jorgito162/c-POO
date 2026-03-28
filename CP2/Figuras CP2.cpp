/*
Jorge J Suarez
Tele 1ro
*/
#include <iostream>
#include <vector>
using namespace std;
class Figura
{
public:
    virtual double area()=0;
    virtual double perimetro()=0;

};
class Rectangulo : public Figura
{
private:
    double largoR, anchoR;

public:
    Rectangulo(double l, double a)
    {
        if (l > 0)
        {
            largoR = l;
        }
        else
        {
            cout << " Ha ingresado una longitud erronea.Se le asignara el valor 1." << endl;
            largoR = 1;
        }
        if (a > 0)
        {
            anchoR = a;
        }
        else
        {
            cout << " Ha ingresado una longitud erronea.Se le asignara el valor 1." << endl;
            anchoR = 1;
        }
    }
    double area() override
    {
        return largoR * anchoR;
    }
    double perimetro() override
    {
        return 2 * (largoR + anchoR);
    }
};
class Circulo : public Figura
{
private:
    double radio, pi = 3.14;

public:
    Circulo(double r)
    {
        if (r > 0)
        {
            radio = r;
        }
        else
        {
            cout << " Ha ingresado una longitud erronea.Se le asignara el valor 1." << endl;
            radio = 1;
        }
    }
    double area() override
    {
        return pi * (radio * radio);
    }
    double perimetro() override
    {
        return 2 * pi * radio;
    }
};
class Triangulo : public Figura
{
private:
    double base, altura;
    double lado1, lado2;

public:
    Triangulo(double b, double h, double l1, double l2)
    {
        if (l1 + l2 <= b || l1 + b <= l2 || l2 + b <= l1)
        {
            cout << " Error en los valores. No se cumple la desigualdad triangular. " << endl;
            base = 3;
            altura = 4;
            lado1 = 3;
            lado2 = 4;
        }
        else
        {
            if (b > 0)
            {
                base = b;
            }
            else
            {
                cout << " Ha ingresado una longitud erronea.Se le asignara el valor 1." << endl;
                base = 1;
            }
            if (h > 0)
            {
                altura = h;
            }
            else
            {
                cout << " Ha ingresado una longitud erronea.Se le asignara el valor 1." << endl;
                altura = 1;
            }
            if (l1 > 0)
            {
                lado1 = l1;
            }
            else
            {
                cout << " Ha ingresado una longitud erronea.Se le asignara el valor 1." << endl;
                lado1 = 1;
            }
            if (l2 > 0)
            {
                lado2 = l2;
            }
            else
            {
                cout << " Ha ingresado una longitud erronea.Se le asignara el valor 1." << endl;
                lado2 = 1;
            }
        }
    }
    double area() override
    {
        return (base * altura) / 2;
    }
    double perimetro() override
    {
        return lado1 + lado2 + base;
    }
};
int main(){
    vector<Figura*>f;
    f.push_back(new Rectangulo(3,5));
    f.push_back(new Rectangulo(2,7));
    f.push_back(new Circulo(4));
    f.push_back(new Circulo(3));
    f.push_back(new Triangulo(5,4,3,4));
    f.push_back(new Triangulo(6,5,5,5));
    double area=0;
    for (size_t i=0;i<f.size();i++) {
        area+=f[i]->area();
    }
    cout<< " El area total es: " << area << endl;
return 0;
}
