
#include "mycon.h"

int main(){
  char c[]="select id from user where name='%' and pswd='%'";
  char data[10][20];
  MyCon mc("localhost","root","tabladelfin","counts");

  cout << "ingresar nombre: ";
  cin.getline(data[0],10,'\n');
  fflush(stdin);
  cout << "ingresar contraseña: ";
  cin.getline(data[1],8,'\n');
  

  insert(c,data);
  cout << c << endl;

  cout << mc.query(c) << endl;
  //if(!mc.query(c))cout << "ingreso exitoso\n";
  
  mc.close();
  return 0;
}
