#include <iostream>
#include <mysql.h>
#include <string.h>

using namespace std;

void out(bool o);
void fail(char s[]);

MYSQL *con;

int main(){
  char name[10];
  char c[]="insert into users(name) values('%s')";
  char *q;

  con=mysql_init(NULL);
  if(!mysql_real_connect(con,"localhost","root","tabladelfin","counts",0,NULL,0)) cout << mysql_error(con) << endl;
  else cout << "Conexion exitosa a db counts\n";

  cout << "ingresar nombre: ";
  cin.getline(name,10,'\n');

  q=new char[strlen(c)+sizeof(name)-sizeof(int)];
  sprintf(q,c,name);

  mysql_query(con,q);
  
  out(0);
}

void out(bool o){
  mysql_close(con);
  exit(o);
}
void fail(char s[]){
  cout << mysql_error(con) << endl;
  cout << s << endl;
  out(1);
}
