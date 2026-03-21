#include <iostream>
using namespace std;

typedef struct Estudiante
{
    string identidad, nombre, sexo, provincia, municipio;
    int edad;
    bool es_UJC, es_becado;
} Estudiante;

typedef struct Brigada
{
    string nombre, profesor;
    Estudiante tele[1];
} Brigada;

int main()
{
    Brigada a[5];
    int i, j;
    for (i = 0; i < sizeof(a[i]) / sizeof(a[0]); i++)
    {
        cout << " Ingrese el nombre de la brigada " << endl;
        cin >> a[i].nombre;
        cout << " Ingrese el nombre del profesor guia " << endl;
        cin >> a[i].profesor;
        for (j = 0; j < sizeof(a[i].tele[j]) / sizeof(a[i].tele[0]); j++)
        {
            cout << " Ingrese el nombre del estudiante " << i << endl;
            cin >> a[i].tele[i].nombre;
            cout << " Ingrese el CI " << endl;
            cin >> a[i].tele[i].identidad;
            cout << " Ingrese el sexo del estudiante " << endl;
            cin >> a[i].tele[i].sexo;
            cout << " Ingrese la provincia " << endl;
            cin >> a[i].tele[i].provincia;
            cout << " Ingrese el municipio " << endl;
            cin >> a[i].tele[i].municipio;
            cout << " Ingrese la edad " << endl;
            cin >> a[i].tele[i].edad;
            cout << " El estudiante pertenece a la UJC (1 para SI, 0 para NO)? " << endl;
            cin >> a[i].tele[i].es_UJC;
            cout << " El estudiante es becado? (1 para SI, 0 para NO) " << endl;
            cin >> a[i].tele[i].es_becado;
        }
    }
    

    return 0;
}