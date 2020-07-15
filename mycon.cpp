#include "mycon.h"

MyCon::MyCon(){}

MyCon::MyCon(char *ho,char *us,char *pw,char *db){
  con=mysql_init(NULL);
  if(!mysql_real_connect(con,ho,us,pw,db,0,NULL,0)) cout << mysql_error(con) << endl;
}

MyCon::MyCon(const char *ho,const char *us,const char *pw,const char *db){
  con=mysql_init(NULL);
  if(!mysql_real_connect(con,ho,us,pw,db,0,NULL,0)) cout << mysql_error(con) << endl;
}

void MyCon::init(char *ho,char *us,char *pw,char *db){
  con=mysql_init(NULL);
  if(!mysql_real_connect(con,ho,us,pw,db,0,NULL,0)) cout << mysql_error(con) << endl;
}

void MyCon::init(const char *ho,const char *us,const char *pw,const char *db){
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

bool MyCon::query(char *q){
  if(v=mysql_query(con,q)) error();
  return v;
}

bool MyCon::query(const char *q){
  if(v=mysql_query(con,q)) error();
  return v;
}

bool MyCon::queryd(char *q,Table &d,int i){
  if(v=mysql_query(con,d.insd(q,i))) error();
  return v;
}

bool MyCon::queryd(const char *q,Table &d,int i){
  if(v=mysql_query(con,d.insd(q,i))) error();
  return v;
}

bool MyCon::outpoint(char *q){
  res=mysql_store_result(con);
  if(res==NULL)return 1;
  row = mysql_fetch_row(res);
  strcpy(q,"\0");
  if(row==0) return 0;
  strcpy(q,row[0]);
  return 0;
}

bool MyCon::outtable(Table &d){
  int j=0;
  res=mysql_store_result(con);
  
  if(res==NULL) return 1;
  
  row=mysql_fetch_row(res);
  int n = mysql_num_fields(res);
  int m = mysql_affected_rows(con);
  d.reset(m,200);
  if(row==0) return 0;
  do{
    for(int i=0;i<n;i++){
      strcat(d.t[j],row[i]);
      strcat(d.t[j]," ");
    }
    j++;
  }while(row=mysql_fetch_row(res));
  
  return 0;
}

bool MyCon::indata(char *q,Table &d,int i,int s){
  Table x(i,2*s+1);
  for(int j=0;j<(i-1);j++)strcpy(x.t[j],d.t[j]);
  mysql_real_escape_string(con,x.t[i-1],d.t[i-1],s);
  if(v=queryd(q,x,i)) error();
  return v;
}

bool MyCon::indata(const char *q,Table &d,int i,int s){
  Table x(i,2*s+1);
  for(int j=0;j<(i-1);j++)strcpy(x.t[j],d.t[j]);
  mysql_real_escape_string(con,x.t[i-1],d.t[i-1],s);
  if(v=queryd(q,x,i)) error();
  return v;
}

bool MyCon::outdata(Table &d){
  res=mysql_store_result(con);
  if(res==NULL) return 1;
  row = mysql_fetch_row(res);
  if(row==0) return 1;
  d.reset(1,strlen(row[0]));
  strcpy(d.t[0],row[0]);
  return 0;
}

bool MyCon::outdata(Table &d,unsigned long* &i){
  res=mysql_store_result(con);
  if(res==NULL) return 1;
  row = mysql_fetch_row(res);
  if(row==0) return 1;
  i=mysql_fetch_lengths(res);
  d.reset(1,strlen(row[0]));
  strcpy(d.t[0],row[0]);
  return 0;
}
