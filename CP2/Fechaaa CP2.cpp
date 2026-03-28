/*
Jorge J Suarez
Tele 1ro
*/
#include<iostream>
using namespace std;
class Fecha {
private:
    int dia,mes,anio;
    bool es_b(int anio) {
        return(anio%400==0)||(anio%4==0&&anio%100!=0);
    }
    int cantDia(int mes, int anio) {
        switch(mes) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
            break;

        case 2:
            if(es_b(anio)) {
                return 29;
            } else {
                return 28;
            }
            break;
        default:
            return 0;
        }


    }
    bool fCorrecta(int dia,int mes,int anio) {
        if(anio<=0) {
            return false;
        }
        if(mes<1 || mes>12) {
            return false;
        }
        if(dia<1 || dia>cantDia(mes,anio)) {
            return false;
        }
        return true;
    }


public:
    Fecha(int d,int m, int a) {
        if(fCorrecta(d,m,a)) {
            dia=d;
            mes=m;
            anio=a;
        } else {
            cout << " Error " << endl;
            dia=1;
            mes=1;
            anio=1900;
        }
    }
    void adelantarDia() {
        dia++;
        switch(mes) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
            if(dia==32) {
                dia=1;
                mes++;
            }
            break;
        case 12:
            if(dia==32) {
                dia=1;
                mes=1;
                anio++;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(dia==31) {
                dia=1;
                mes++;
            }
            break;
        case 2:
            if(es_b(anio)) {
                if(dia==30) {
                    dia=1;
                    mes++;
                }
            } else {
                if(dia==29) {
                    dia=1;
                    mes++;
                }
            }
            break;

        }
    }
    void mostrar() {
        cout << dia << "/" << mes << "/" << anio << endl;
    }
    int comparar(Fecha fc) {
        if(anio<fc.anio) {
            return -1;
        }
        if(anio>fc.anio) {
            return 1;
        }
        if(mes<fc.mes) {
            return -1;
        }
        if(mes>fc.mes) {
            return 1;
        }
        if(dia<fc.dia) {
            return -1;
        }
        if(dia>fc.dia) {
            return 1;
        }
        return 0;
    }
};
int main() {
    Fecha f1(29,2,2024);
    cout << " A la fecha f1: ";
    f1.mostrar();
    cout << " se le adelantara un dia " << endl;
    f1.adelantarDia();
    f1.mostrar();
    cout << "" << endl;
    Fecha f2(31,12,2024);
    cout << " A la fecha f2: ";
    f2.mostrar();
    cout << " se le adelantara un dia " << endl;
    f2.adelantarDia();
    f2.mostrar();
    cout << "" << endl;
    Fecha f3(32,14,-1);
    f3.mostrar();
    cout << "" << endl;
    Fecha f4(1,3,2024);
    f4.mostrar();
    cout << "" << endl;
    if(f1.comparar(f4)>0){
        cout << " La fecha f1 es mas antigua que la fecha f2 " << endl;
    }else if(f1.comparar(f4)<0){
        cout << " La fecha f2 es mas antigua que la fecha f1 " << endl;
    }else{
        cout << " Ambas fechas son iguales " << endl;
    }
    return 0;
}