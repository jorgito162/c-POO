/*
Jorge J Suarez
Tele 1ro
*/
#include <bits/stdc++.h>
using namespace std;
class Matriz
{
private:
    int filas, columnas;
    double **datos;

public:
    Matriz(int f, int c)
    {
        if (f > 0)
        {
            filas = f;
        }
        else
        {
            cout << " Valor erroneo.Se asignara el valor 2 " << endl;
            filas = 2;
        }
        if (c > 0)
        {
            columnas = c;
        }
        else
        {
            cout << " Valor erroneo.Se asignara el valor 2 " << endl;
            columnas = 2;
        }
        datos = new double *[filas];
        for (int i = 0; i < filas; i++)
        {
            datos[i] = new double[columnas];
        }
    }
    ~Matriz(){
        for(int i=0;i<filas;++i)delete[] datos[i];
        delete[] datos;
    }
    Matriz(const Matriz &o) : filas(o.filas), columnas(o.columnas)
    {
        datos = new double *[filas];
        for (int i = 0; i < filas; ++i)
        {
            datos[i] = new double[columnas];
            for (int j = 0; j < columnas; ++j)
                datos[i][j] = o.datos[i][j];
        }
    }
    Matriz& operator=(const Matriz& o) {
        if (this != &o) {
            for (int i = 0; i < filas; ++i)
                delete[] datos[i];
            delete[] datos;
            filas = o.filas;
            columnas = o.columnas;
            datos = new double*[filas];
            for (int i = 0; i < filas; ++i) {
                datos[i] = new double[columnas];
                for (int j = 0; j < columnas; ++j)
                    datos[i][j] = o.datos[i][j];
            }
        }
        return *this;
    }
     double& operator()(int i, int j) {
        if (i < 0 || i >= filas || j < 0 || j >= columnas)
            throw std::out_of_range("Índice fuera de rango");
        return datos[i][j];
    }

    double operator()(int i, int j) const {
        if (i < 0 || i >= filas || j < 0 || j >= columnas)
            throw std::out_of_range("Índice fuera de rango");
        return datos[i][j];
    }
    Matriz operator+(const Matriz& o) const {
        if (filas != o.filas || columnas != o.columnas)
            throw std::invalid_argument("Dimensiones no coinciden para suma");
        Matriz res(filas, columnas);
        for (int i = 0; i < filas; ++i)
            for (int j = 0; j < columnas; ++j)
                res.datos[i][j] = datos[i][j] + o.datos[i][j];
        return res;
    }

    Matriz operator-(const Matriz& o) const {
        if (filas != o.filas || columnas != o.columnas)
            throw std::invalid_argument("Dimensiones no coinciden para resta");
        Matriz res(filas, columnas);
        for (int i = 0; i < filas; ++i)
            for (int j = 0; j < columnas; ++j)
                res.datos[i][j] = datos[i][j] - o.datos[i][j];
        return res;
    }

    Matriz operator*(const Matriz& o) const {
        if (columnas != o.filas)
            throw std::invalid_argument("Dimensiones no válidas para multiplicación");
        Matriz res(filas, o.columnas);
        for (int i = 0; i < filas; ++i)
            for (int j = 0; j < o.columnas; ++j)
                for (int k = 0; k < columnas; ++k)
                    res.datos[i][j] += datos[i][k] * o.datos[k][j];
        return res;
    }

    Matriz transponer() const {
        Matriz res(columnas, filas);
        for (int i = 0; i < filas; ++i)
            for (int j = 0; j < columnas; ++j)
                res.datos[j][i] = datos[i][j];
        return res;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matriz& m) {
        for (int i = 0; i < m.filas; ++i) {
            for (int j = 0; j < m.columnas; ++j)
                os << setw(6) << m.datos[i][j];
            os << std::endl;
        }
        return os;
    }
};
int main(){
    Matriz A(2,2);
    Matriz B(2,2);
    A(0,0)=2;
    A(0,1)=5;
    A(1,0)=4;
    A(1,1)=4;
    B(0,0)=9;
    B(0,1)=6;
    B(1,0)=8;
    B(1,1)=1;
    cout<< A << endl;
    cout<< "------" << endl;
    cout<< B << endl;
    cout<< "------" << endl;
    Matriz C=A+B;
    cout<< C << endl;
    Matriz D=A*B;
    cout << D << endl;
    Matriz AT = A.transponer();
    cout<< AT << endl;

    return 0;
}