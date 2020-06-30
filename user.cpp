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

bool User::check(){
  x.reset(1,10);
  strcpy(x.t[0],d.t[0]);
  if(mc.queryd("select id from user where name='%s'",x,1)) return 1;
  if(mc.outpoint(x.t[0])) return 1;
  if(strcmp(x.t[0],"\0")!=0) return 1;
  return 0;
}

bool User::create(){
  x.reset(2,10);
  strcpy(x.t[0],d.t[0]);
  strcpy(x.t[1],d.t[1]);
  if(mc.queryd("insert into user(name,pswd) values('%s','%s')",x,2)) return 1;
  return 0;
}

bool User::del(){
  x.reset(1,10);
  strcpy(x.t[0],d.t[2]);
  if(mc.queryd("delete from user where id='%s'",x,1)) return 1;
  return 0;
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

bool User::setact(bool b){
  x.reset(1,10);
  strcpy(x.t[0],d.t[2]);
  if(b){
    if(mc.query("update user set active=0")) return 1;
    if(mc.queryd("update user set active=1 where id='%s'",x,1)) return 1;
    return 0;
  }
  if(mc.queryd("update user set active=0 where id='%s'",x,1)) return 1;
  return 0;
}

bool User::setacs(bool b){
  x.reset(1,10);
  strcpy(x.t[0],d.t[2]);
  if(b)if(mc.queryd("update user set acces=1 where id='%s'",x,1)) return 1;
  if(!b)if(mc.queryd("update user set acces=0 where id='%s'",x,1)) return 1;
  return 0;
}

bool User::getacs(bool &b){
  x.reset(1,10);
  strcpy(x.t[0],d.t[2]);
  if(mc.queryd("select acces from user where id='%s'",x,1)) return 1;
  if(mc.outpoint(x.t[0])) return 1;
  if(strcmp(x.t[0],"0")==0) b=0;
  if(strcmp(x.t[0],"1")==0) b=1;
  return 0;
}

bool User::checkdoc(char *a,char *b){
  x.reset(3,strlen(a)*5);
  strcpy(x.t[0],d.t[2]);
  strcpy(x.t[1],a);
  strcpy(x.t[2],b);
  if(mc.queryd("select id_arch from arch where id_user='%s' and name_arch='%s' and id_dir='%s'",x,3)) return 1;
  if(mc.outpoint(x.t[0])) return 1;
  if(strcmp(x.t[0],"\0")!=0) return 1;
  return 0;
}

bool User::checkdoc(const char *a,const char *b){
  x.reset(3,strlen(a)*5);
  strcpy(x.t[0],d.t[2]);
  strcpy(x.t[1],a);
  strcpy(x.t[2],b);
  if(mc.queryd("select id_arch from arch where id_user='%s' and name_arch='%s' and id_dir='%s'",x,3)) return 1;
  if(mc.outpoint(x.t[0])) return 1;
  if(strcmp(x.t[0],"\0")!=0) return 1;
  return 0;
}

bool User::inarch(char *a,char *b,char *c){
  x.reset(4,strlen(c));
  strcpy(x.t[0],d.t[2]);
  strcpy(x.t[1],a);
  strcpy(x.t[2],b);
  strcpy(x.t[3],c);
  if(mc.indata("insert into arch(id_user,name_arch,id_dir,data) values('%s','%s','%s','%s')",x,4)) return 1;
  return 0;
}

bool User::inarch(const char *a,const char *b,char *c){
  x.reset(4,strlen(c));
  strcpy(x.t[0],d.t[2]);
  strcpy(x.t[1],a);
  strcpy(x.t[2],b);
  strcpy(x.t[3],c);
  if(mc.indata("insert into arch(id_user,name_arch,id_dir,data) values('%s','%s','%s','%s')",x,4)) return 1;
  return 0;
}
