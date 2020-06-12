
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
  

  if(mc.queryd(c,data)) mc.fail();

  MYSQL_RES *result = mysql_store_result(mc.con);
  MYSQL_ROW row = mysql_fetch_row(result);

  if(row==0) cout << "error al ingresar\n";
  else cout << "id: " << row[0] << endl;
  
  mc.close();
  return 0;
}
