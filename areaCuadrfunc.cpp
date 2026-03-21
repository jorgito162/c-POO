#include <iostream>
using namespace std ;
float calcAr(float l){
    return l * l ;
}
int main(){
    int l ;
    cin >> l ;
    cout << " El area es " << calcAr(l) ;
}