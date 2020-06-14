
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

  if(strcmp(result,"")!=0){
    cout << "tabla de usuarios\n";
    mc.query("select * from user");
    MYSQL_RES *result = mysql_store_result(mc.con);
    int n = mysql_num_fields(result);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))){
      for(int i=0;i<n;i++) cout << row[i] << " ";
      cout << endl;
    }
  }
  mc.close();
  return 0;
}
