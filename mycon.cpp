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

bool MyCon::queryd(char c[],char d[]){
  char *q=new char[strlen(c)+sizeof(d)-sizeof(int)];
  sprintf(q,c,d);
  if(v=mysql_query(con,q)) error();
  return v;
}

bool MyCon::query2d(char c[],char d1[],char d2[]){
  char *q=new char[strlen(c)+sizeof(d1)+sizeof(d2)-sizeof(int)];
  sprintf(q,c,d1,d2);
  if(v=mysql_query(con,q)) error();
  return v;
}

bool MyCon::query3d(char c[],char d1[],char d2[],char d3[]){
  char *q=new char[strlen(c)+sizeof(d1)+sizeof(d2)+sizeof(d3)-sizeof(int)];
  sprintf(q,c,d1,d2,d3);
  if(v=mysql_query(con,q)) error();
  return v;
}
