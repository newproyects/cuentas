#include "mycon.h"

int main(){
  char name[10];
  char pswd[8];
  char c[]="insert into users(name,pswd) values('%s','%s')";
  MyCon mc("localhost","root","tabladelfin","counts");

  cout << "ingresar nombre: ";
  cin.getline(name,10,'\n');
  cout << "ingresar contraseña: ";
  cin.getline(pswd,8,'\n');

  if(!mc.query2d(c,name,pswd))cout << "ingreso exitoso\n";

  mc.close();
  return 0;
}
