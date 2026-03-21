#include <iostream>
using namespace std ;

int main(){

    int num1, num2 ;
    char operador ;

cout << " Ingrese el operador \n + - * / " << endl ;
cin >> operador ;

cout << " Ingrese dos numeros " << endl ;
cin >> num1 >> num2 ;

switch (operador)
{
case '+' :
    cout << num1 << " + " << num2 << " = " << num1 + num2 ;
    break;
case '-' :

    cout << num1 << " - " << num2 << " = " << num1 - num2 ;

  break;
case '*' :

    cout << num1 << " * " << num2 << " = " << num1 * num2 ;

  break;
case '/' :
 
  cout << num1 << " / " << num2 << " = " << num1 / num2 ;

  break;
default:
 cout << " Error " ;
    break;
}



    return 0 ;
}