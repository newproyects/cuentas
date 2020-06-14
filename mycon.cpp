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

bool MyCon::queryd(char c[],Table &d){
  d.ins(c);
  if(v=mysql_query(con,c)) error();
  return v;
}

bool MyCon::outpoint(char q[]){
  res=mysql_store_result(con);
  if(res==NULL)return 1;
  row = mysql_fetch_row(res);
  strcpy(q,"");
  if(row==0) return 0;
  strcpy(q,row[0]);
  return 0;
}

bool MyCon::outtable(Table &o){
  int j=0;
  res=mysql_store_result(con);
  
  if(res==NULL) return 1;
  
  row=mysql_fetch_row(res);
  int n = mysql_num_fields(res);
  int m = mysql_affected_rows(con);
  o.reset(m,200);
  if(row==0) return 0;
  do{
    for(int i=0;i<n;i++){
      strcat(o.t[j],row[i]);
      strcat(o.t[j]," ");
    }
    j++;
  }while(row=mysql_fetch_row(res));
  
  return 0;
}
