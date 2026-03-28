/*
Jorge J Suarez
Tele 1ro
*/


#include<iostream>
#include<vector>
using namespace std;
class Contacto{ 
    public:
        string nombre,email,telefono;
        Contacto(string n,string e,string t){
            nombre=n;
            email=e;
            telefono=t;
        }
};
class Agenda{
    private:
        vector<Contacto> c;
    public:
        Agenda(vector<Contacto> cc){
            c=cc;
        }
        void agregar(Contacto a){
            for(int i=0;i<c.size();i++){
                if(a.nombre==c[i].nombre){
                    cout<< " Ya existe el contacto " << endl;
                    return ;
                }
            }
            c.push_back(a);
        }
        void eliminar(string q){
            for(int i=0;i<c.size();i++){
                if(q==c[i].nombre){
                    c.erase(c.begin()+i);
                    return ;
                }
            }
            cout<< " No se encontro el contacto " << endl;
        }
        void buscar(string w){
            for(size_t i=0;i<c.size();i++){
                if(w==c[i].nombre){
                    cout<< " Informacion del contacto " << endl;
                    cout<< " Nombre: " << w << endl;
                    cout<< " Telefono: " << c[i].telefono << endl;
                    cout<< " Email: " << c[i].email << endl;
                    return ;
                }
            }
            cout<< " No se encontro el contacto " << endl;
        }
        void mostrarTodos(){
            for(size_t i=0;i<c.size();i++){
                cout<< " Informacion del contacto " << endl;
                cout<< " Nombre: " << c[i].nombre << endl;
                cout<< " Telefono: " << c[i].telefono << endl;
                cout<< " Email: " << c[i].email << endl;
                cout<< "-------------------"<< endl;
            }
        }
};
int main(){
    vector<Contacto>yo;
    Contacto c1("Karel","56325123","karel@gmail.com");
    Contacto c2("Diana","54145236","diana@gmail.com");
    Contacto c3("Leroy","55478569","leroy@gamil.com");
    yo.push_back(c1);
    yo.push_back(c2);
    yo.push_back(c3);
    Agenda a(yo);
    a.mostrarTodos();
    a.eliminar("Leroy");
    a.mostrarTodos();




    return 0;
}