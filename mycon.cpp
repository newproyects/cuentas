#include "mycon.h"

MyCon::MyCon(char *ho,char *us,char *pw,char *db){
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

bool MyCon::queryd(char *q,Table &d){
  d.ins(q);
  if(v=mysql_query(con,q)) error();
  return v;
}

bool MyCon::outpoint(char *q){
  res=mysql_store_result(con);
  if(res==NULL)return 1;
  row = mysql_fetch_row(res);
  strcpy(q,"");
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

bool MyCon::indata(char *q,Table &d){
  Table x(3,2*strlen(d.t[2])+1);
  strcpy(x.t[0],d.t[0]);
  strcpy(x.t[1],d.t[1]);
  mysql_real_escape_string(con,x.t[2],d.t[2],strlen(d.t[2]));
  if(v=mysql_query(con,x.insd(q))) error();
  return v;
}

bool MyCon::outdata(char* &q,Table &d){
  char x[100];
  strcpy(x,q);
  if(v=queryd(x,d)) return 1;
  res=mysql_store_result(con);
  if(res==NULL) return 1;
  row = mysql_fetch_row(res);
  if(row==0) return 1;
  q=row[0];
  return 0;
}

bool MyCon::outdata(char* &q,unsigned long* &i,Table &d){
  char x[100];
  strcpy(x,q);
  if(v=queryd(x,d)) return 1;
  res=mysql_store_result(con);
  if(res==NULL) return 1;
  row = mysql_fetch_row(res);
  if(row==0) return 1;
  i=mysql_fetch_lengths(res);
  q=row[0];
  return 0;
}
