#include <iostream>
#include <mysql.h>

using namespace std;

int main(){
  MYSQL *con=mysql_init(NULL);
  if(!mysql_real_connect(con,"localhost","root","tabladelfin","counts",0,NULL,0)) cout << mysql_error(con) << endl;
  else cout << "Conexion exitosa a db counts\n";

  
  return 0;
}
