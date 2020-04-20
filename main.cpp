#include <iostream>
#include <mysql.h>
#include <string.h>

using namespace std;

class MyCon{
private:
  MYSQL *con;
public:
  MyCon(char ho[],char us[],char pw[],char db[]);
  void close();
  void error();
  void fail();
  void query(char c[]);
  void queryd(char c[],char d[]);
  void query2d(char c[],char d1[],char d2[]);
  void query3d(char c[],char d1[],char d2[],char d3[]);
};


int main(){
  char name[10];
  char pswd[8];
  char c[]="insert into users(name,pswd) values('%s','%s')";
  char *q;
  MyCon mc("localhost","root","tabladelfin","counts");

  cout << "ingresar nombre: ";
  cin.getline(name,10,'\n');
  cout << "ingresar contraseña: ";
  cin.getline(pswd,8,'\n');

  mc.query2d(c,name,pswd);

  mc.close();
  return 0;
}

MyCon::MyCon(char ho[],char us[],char pw[],char db[]){
  con=mysql_init(NULL);
  if(!mysql_real_connect(con,ho,us,pw,db,0,NULL,0)) cout << mysql_error(con) << endl;
}

void MyCon::close(){
  mysql_close(con);
}

void MyCon::error(){
  cout << mysql_error(con) << endl;
}

void MyCon::fail(){
  error();
  close();
  exit(1);
}

void MyCon::query(char c[]){
  if(mysql_query(con,c)) error();
}

void MyCon::queryd(char c[],char d[]){
  char *q=new char[strlen(c)+sizeof(d)-sizeof(int)];
  sprintf(q,c,d);
  if(mysql_query(con,q)) error();
}

void MyCon::query2d(char c[],char d1[],char d2[]){
  char *q=new char[strlen(c)+sizeof(d1)+sizeof(d2)-sizeof(int)];
  sprintf(q,c,d1,d2);
  if(mysql_query(con,q)) error();
}

void MyCon::query3d(char c[],char d1[],char d2[],char d3[]){
  char *q=new char[strlen(c)+sizeof(d1)+sizeof(d2)+sizeof(d3)-sizeof(int)];
  sprintf(q,c,d1,d2,d3);
  if(mysql_query(con,q)) error();
}
