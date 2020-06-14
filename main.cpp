
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
  
  
  if(mc.queryd(c,data)) mc.fail();

  mc.outpoint(result);

  cout << "id: " << (strcmp(result,"")==0 ? "error de acceso" : result) << endl;

  if(strcmp(result,"")!=0){
    cout << "tabla de usuarios\n";
    mc.query("select * from user");
    mc.outtable(data);
    for(int i=0;i<data.y;i++) cout << data.t[i] << endl;
  }
  
  mc.close();
  return 0;
}
