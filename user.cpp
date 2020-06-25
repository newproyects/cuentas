#include "user.h"

User::User(){
  mc.init("localhost","program","margorp","counts");
  d.init(3,10);
  x.init(1,1);
}

User::User(char *a,char *b){
  mc.init("localhost","program","margorp","counts");
  d.init(3,10);
  x.init(1,1);
  strcpy(d.t[0],a);
  strcpy(d.t[1],b);
}

User::User(const char *a,const char *b){
  mc.init("localhost","program","margorp","counts");
  d.init(3,10);
  x.init(1,1);
  strcpy(d.t[0],a);
  strcpy(d.t[1],b);
}

User::~User(){
  mc.close();
}

void User::set(char *a,char *b){
  strcpy(d.t[0],a);
  strcpy(d.t[1],b);
}

void User::set(const char *a,const char *b){
  strcpy(d.t[0],a);
  strcpy(d.t[1],b);
}

bool User::id(){
  x.reset(2,10);
  strcpy(x.t[0],d.t[0]);
  strcpy(x.t[1],d.t[1]);
  if(mc.queryd("select id from user where name='%s' and pswd='%s'",x,2)) return 1;
  if(mc.outpoint(x.t[0])) return 1;
  strcpy(d.t[2],x.t[0]);
  return 0;
}
