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

bool MyCon::queryd(char c[],char **d){
  insert(c,d);
  if(v=mysql_query(con,c)) error();
  return v;
}

char* MyCon::outpoint(){
  row = mysql_fetch_row(mysql_store_result(con));
  if(row==0) return "";
  else return row[0];
}

char** MyCon::outtable(){
  int j=0;
  char **o;
  res=mysql_store_result(con);
  int n = mysql_num_fields(res);
  int num_rows = mysql_affected_rows(con);
  cout << num_rows << endl;
  row=mysql_fetch_row(res);
  if(row!=0)do{
      for(int i=0;i<n;i++) cout << row[i] << " ";
      cout << endl;
    }while(row=mysql_fetch_row(res));
}
