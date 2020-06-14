
#include "mycon.h"

int main(){
  char c[]="select id from user where name='%' and pswd='%'";
  Table data(10,40);
  MyCon mc("localhost","root","tabladelfin","counts");
  char result[10];

  cout << "ingresar nombre: ";
  cin.getline(data.t[0],10,'\n');
  fflush(stdin);
  cout << "ingresar contraseña: ";
  cin.getline(data.t[1],8,'\n');
  

  if(mc.queryd(c,data.t)) mc.fail();

  strcpy(result,mc.outpoint());

  cout << "id: " << (strcmp(result,"")==0 ? "error de acceso" : result) << endl;
  
  mc.close();
  return 0;
}
