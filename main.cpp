#include <iostream>
#include <mysql.h>
#include <string.h>

using namespace std;

void conect();
void out(bool o);
void fail(char s[]);

MYSQL *con;

int main(){
  char name[10];
  char pswd[8];
  char c[]="insert into users(name,pswd) values('%s','%s')";
  char *q;

  conect();

  cout << "ingresar nombre: ";
  cin.getline(name,10,'\n');
  cout << "ingresar contraseña: ";
  cin.getline(pswd,8,'\n');

  q=new char[strlen(c)+sizeof(name)+sizeof(pswd)-sizeof(int)];
  sprintf(q,c,name,pswd);

  if(mysql_query(con,q))fail("Error de ingreso");
  else cout << "cuenta ingresada exitosamente\n";
  
  out(0);
}

void conect(){
  con=mysql_init(NULL);
  if(!mysql_real_connect(con,"localhost","root","tabladelfin","counts",0,NULL,0)) cout << mysql_error(con) << endl;
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
