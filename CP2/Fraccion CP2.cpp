/*
Jorge J Suarez
Tele 1ro
*/
#include <iostream>
using namespace std;

class Fraccion
{
private:
    int mcd(int a, int b)
    {
        if (a < 0)
        {
            a = -a;
        }
        if (b < 0)
        {
            b = -b;
        }
        while (b != 0)
        {
            int aux = b;
            b = a % b;
            a = aux;
        }
        return a;
    }
    void simplificar()
    {
        int d = mcd(numerador, denominador);
        numerador = numerador / d;
        denominador = denominador / d;
    }

public:
    int numerador, denominador;
    Fraccion(int num, int den)
    {
        if (den != 0)
        {
            numerador = num;
            denominador = den;
        }
        else
        {
            cout << " Error.El denominador no puede ser cero. " << endl;
            numerador = 0;
            denominador = 1;
        }
        simplificar();
    }
    Fraccion sumar(Fraccion s)
    {
        int nNum = (numerador * s.denominador) + (s.numerador * denominador);
        int nDen = denominador * s.denominador;
        return Fraccion(nNum, nDen);
    }
    Fraccion restar(Fraccion r)
    {
        int nNum = (numerador * r.denominador) - (r.numerador * denominador);
        int nDen = denominador * r.denominador;
        return Fraccion(nNum, nDen);
    }
    Fraccion multiplicar(Fraccion m)
    {
        int nNum = numerador * m.numerador;
        int nDen = denominador * m.denominador;
        return Fraccion(nNum, nDen);
    }
    Fraccion dividir(Fraccion d)
    {
        int nNum = numerador * d.denominador;
        int nDen = denominador * d.numerador;
        return Fraccion(nNum, nDen);
    }
    double valorReal()
    {
        double real = (double)numerador / denominador;
        return real;
    }
};
int main()
{
    Fraccion f(2, 4);
    Fraccion a(-1, 3);
    cout << f.sumar(a).numerador << " " << f.sumar(a).denominador << endl;
    cout << f.valorReal() << endl;
    cout << f.multiplicar(a).numerador << " " << f.multiplicar(a).denominador << endl;
    cout << f.dividir(a).numerador << " " << f.dividir(a).denominador << endl;
    return 0;
}