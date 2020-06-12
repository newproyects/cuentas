#include "mycon.h"

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

bool MyCon::query(char c[]){
  if(v=mysql_query(con,c)) error();
  return v;
}

bool MyCon::queryd(char c[],char d[][20]){
  insert(c,d);
  if(v=mysql_query(con,c)) error();
  return v;
}
