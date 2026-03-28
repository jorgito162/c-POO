/*
Jorge J Suarez
Tele 1ro
*/
#include<iostream>
using namespace std;
class Rectangulo {
    private:
            double base,altura;
    public:
            Rectangulo(double b,double a){
               if(b>0){
                   base = b;
               }else{
                cout << " La base tiene que ser positiva. Se le asignara el valor de 1 " << endl;   
                base=1;
               }
               if(a>0){
                   altura=a;
               }else{
                   cout << " La altura tiene que ser positiva. Se le asiganara el valor de 1 " << endl;
                   altura=1;
               }
                
            }
            double calcArea(){
                return base*altura;
            }
            double calcPerim(){
                return 2*(altura+base);
            }
            double getBase(){
                return base;
            }
            double getAltura(){
                return altura;
            }
            void setBase(double b){
                if (b>0){
                    base=b;
                }else{
                    cout<<" La base tiene que ser positiva "<<endl;
                }
            }
            void setAltura(double a){
                if(a>0){
                    altura=a;
                }else{
                    cout<<" La altura tiene que ser positiva "<<endl;
                }
            }
};
int main(){
    Rectangulo r(2.2,4.5);
    cout<<" El area es: "<<r.calcArea()<<endl;
    cout<<" El perimetro es: "<<r.calcPerim()<<endl;
    r.setAltura(5);
    r.setBase(2);
    cout << " Ahora la base es: "<< r.getBase() << endl;
    cout << " Ahora la altura es: "<< r.getAltura() << endl;
    cout << "La nueva area es: "<< r.calcArea ()<< endl;

return 0;
}