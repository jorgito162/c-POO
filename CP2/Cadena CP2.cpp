#include <bits/stdc++.h>
using namespace std;

class Cadena {
private:
    char* a;
    size_t b;

public:
    Cadena(const char* c = "") {
        b = strlen(c);
        a = new char[b + 1];
        strcpy(a, c);
    }

    Cadena(const Cadena& d) {
        b = d.b;
        a = new char[b + 1];
        strcpy(a, d.a);
    }

    ~Cadena() {
        delete[] a;
    }

    Cadena& operator=(const Cadena& d) {
        if (this != &d) {
            delete[] a;
            b = d.b;
            a = new char[b + 1];
            strcpy(a, d.a);
        }
        return *this;
    }

    Cadena operator+(const Cadena& d) const {
        Cadena res;
        res.b = b + d.b;
        delete[] res.a;
        res.a = new char[res.b + 1];
        strcpy(res.a, a);
        strcat(res.a, d.a);
        return res;
    }

    bool operator==(const Cadena& d) const {
        return strcmp(a, d.a) == 0;
    }

    char& operator[](size_t indice) {
        if (indice >= b) throw out_of_range("Índice fuera de rango");
        return a[indice];
    }

    const char& operator[](size_t indice) const {
        if (indice >= b) throw out_of_range("Índice fuera de rango");
        return a[indice];
    }

    size_t longitud() const {
        return b;
    }

    void mayusculas() {
        for (size_t i = 0; i < b; ++i)
            a[i] = toupper(a[i]);
    }

    Cadena subcadena(size_t pos, size_t n) const {
        if (pos > b) throw out_of_range("Posición inicial inválida");
        size_t count = (n > b - pos) ? b - pos : n;
        char* temp = new char[count + 1];
        strncpy(temp, a + pos, count);
        temp[count] = '\0';
        Cadena res(temp);
        delete[] temp;
        return res;
    }

    friend ostream& operator<<(ostream& os, const Cadena& c) {
        os << c.a;
        return os;
    }
};

int main() {
    
    Cadena s1("Hola");
    Cadena s2(" Mundo");
    Cadena s3 = s1 + s2;
    cout << "Concatenación: " << s3 << endl;
    s3.mayusculas();
    cout << "Mayúsculas: " << s3 << endl;
    Cadena sub = s3.subcadena(0, 4);
    cout << "Subcadena (0,4): " << sub << endl;
    cout << "Longitud: " << s3.longitud() << endl;
    cout << "s3[5]: " << s3[5] << endl;
    Cadena s4("HOLA MUNDO");
    cout << "¿s3 == s4? " << boolalpha << (s3 == s4) << endl;

    return 0;
}