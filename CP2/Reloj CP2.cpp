/*
Jorge J Suarez
Tele 1ro
*/
#include<iostream>
using namespace std;
string f(int p){
    return (p>9 ? to_string(p) : "0" + to_string(p) );
}
class Reloj{
    private:
            int hora,minuto,segundo;
    public:
            Reloj(int h,int m,int s){
                if(h>=0 && h<24){
                    hora=h;
                }else{
                    cout << " Ha ingresado un valor erroneo.Se asignara el valor 0" << endl;
                    hora=0;
                }
                if(m>=0 && m<60){
                    minuto=m;
                }else{
                    cout << " Ha ingresado un valor erroneo.Se asignara el valor 0." << endl;
                    minuto=0;
                }
                if(s>=0 && s<60){
                    segundo=s;
                }else{    
                    cout << " Ha ingresado un valor erroneo.Se asignara el valor de 0." << endl;
                    segundo=0;
                }
            }
            void mostrarHora(){
               cout << f(hora) << ":" << f(minuto) << ":" << f(segundo) << endl;
            }
            void adelantar(){
                segundo++;
                if(segundo==60){
                    minuto++;
                    segundo=0;
                }
                if(minuto==60){
                    hora++;
                    minuto=0;
                }
                if(hora==24){
                    hora=0;
                }
            
            }   
};
int main(){
Reloj r(23,59,59);
cout << " La hora es:" ; 
r.mostrarHora();
cout << "" << endl;
r.adelantar();
r.mostrarHora();

return 0;
}