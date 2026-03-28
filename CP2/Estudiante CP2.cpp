/*
Jorge J Suarez
Tele 1ro
*/
#include <iostream>
#include <vector>
using namespace std;
class Estudiante
{
private:
    string nombre;
    int CI;
    vector<int> notas;

public:
    Estudiante(string n, int c)
    {
        nombre = n;
        CI = c;
    }
    void agregarCalificacion(int calificacion)
    {
        if (calificacion >= 0 && calificacion <= 100)
        {
            notas.push_back(calificacion);
        }
        else
        {
            cout << " Ha ingresado un valor erroneo " << endl;
        }
    }
    double calcularPromedio()
    {
        double suma = 0;
        if (notas.empty())
        {
            return 0;
        }
        for (int i = 0; i < notas.size(); i++)
        {
            suma += notas[i];
        }
        return suma / notas.size();
    }
    string getNombre()
    {
        return nombre;
    }
    int getCI()
    {
        return CI;
    }
};
int main()
{
    Estudiante e("Jorge", 6062638);
    cout << " El nombre del estudiante es: " << e.getNombre() << endl;
    e.agregarCalificacion(100);
    e.agregarCalificacion(80);
    e.agregarCalificacion(90);
    cout << " El CI del estudiante " << e.getNombre() << " es: " << e.getCI() << " y su promedio de notas es: " << e.calcularPromedio() << endl;

    return 0;
}