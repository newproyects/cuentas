
#include "mycon.h"

int main(){
  char c[]="select id from user where name='%' and pswd='%'";
  char data[10][20];
  MyCon mc("localhost","root","tabladelfin","counts");
  char result[10];

  cout << "ingresar nombre: ";
  cin.getline(data[0],10,'\n');
  fflush(stdin);
  cout << "ingresar contraseña: ";
  cin.getline(data[1],8,'\n');
  

  if(mc.queryd(c,data)) mc.fail();

  strcpy(result,mc.outpoint());

  cout << "id: " << (strcmp(result,"")==0 ? "error de acceso" : result) << endl;
  
  mc.close();
  return 0;
}
