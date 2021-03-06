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
  if(mc.queryd("delete from arch where id_user='%s'",x,1)) return 1;
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

bool User::rename(char *a){
  x.reset(2,strlen(a));
  strcpy(x.t[0],a);
  strcpy(x.t[1],d.t[2]);
  if(mc.queryd("update user set name='%s' where id='%s' and not(id=0)",x,2)) return 1;
  return 0;
}

bool User::rename(const char *a){
  x.reset(2,strlen(a));
  strcpy(x.t[0],a);
  strcpy(x.t[1],d.t[2]);
  if(mc.queryd("update user set name='%s' where id='%s' and not(id=0)",x,2)) return 1;
  return 0;
}

bool User::repswd(char *a){
  x.reset(2,strlen(a));
  strcpy(x.t[0],a);
  strcpy(x.t[1],d.t[2]);
  if(mc.queryd("update user set pswd='%s' where id='%s' and not(id=0)",x,2)) return 1;
  return 0;
}

bool User::repswd(const char *a){
  x.reset(2,strlen(a));
  strcpy(x.t[0],a);
  strcpy(x.t[1],d.t[2]);
  if(mc.queryd("update user set pswd='%s' where id='%s' and not(id=0)",x,2)) return 1;
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

bool User::getact(bool &b){
  x.reset(2,10);
  b=0;
  if(mc.query("select name from user where active=1")) return 1;
  if(mc.outpoint(x.t[0])) return 1;
  if(strcmp(x.t[0],"\0")==0) return 0;
  if(mc.query("select pswd from user where active=1")) return 1;
  if(mc.outpoint(x.t[1])) return 1;
  if(strcmp(x.t[0],"\0")==0) return 0;
  strcpy(d.t[0],x.t[0]);
  strcpy(d.t[1],x.t[1]);
  b=1;
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

bool User::iddoc(char *a,char *b,char* &c){
  x.reset(3,strlen(a)*5);
  strcpy(x.t[0],d.t[2]);
  strcpy(x.t[1],a);
  strcpy(x.t[2],b);
  if(mc.queryd("select id_arch from arch where id_user='%s' and name_arch='%s' and id_dir='%s'",x,3)) return 1;
  if(mc.outpoint(c)) return 1;
  if(strcmp(c,"\0")!=0) return 1;
  return 0;
}

bool User::iddoc(const char *a,const char *b,char* &c){
  x.reset(3,strlen(a)*5);
  strcpy(x.t[0],d.t[2]);
  strcpy(x.t[1],a);
  strcpy(x.t[2],b);
  if(mc.queryd("select id_arch from arch where id_user='%s' and name_arch='%s' and id_dir='%s'",x,3)) return 1;
  if(mc.outpoint(c)) return 1;
  if(strcmp(c,"\0")!=0) return 1;
  return 0;
}

bool User::idarch(char *a,char *b,char* &c){
  x.reset(3,strlen(a)*5);
  strcpy(x.t[0],d.t[2]);
  strcpy(x.t[1],a);
  strcpy(x.t[2],b);
  if(mc.queryd("select id_arch from arch where id_user='%s' and name_arch='%s' and id_dir='%s' and not(data='0-dir-0')",x,3)) return 1;
  if(mc.outpoint(c)) return 1;
  if(strcmp(c,"\0")!=0) return 1;
  return 0;
}

bool User::idarch(const char *a,const char *b,char* &c){
  x.reset(3,strlen(a)*5);
  strcpy(x.t[0],d.t[2]);
  strcpy(x.t[1],a);
  strcpy(x.t[2],b);
  if(mc.queryd("select id_arch from arch where id_user='%s' and name_arch='%s' and id_dir='%s' and not(data='0-dir-0')",x,3)) return 1;
  if(mc.outpoint(c)) return 1;
  if(strcmp(c,"\0")!=0) return 1;
  return 0;
}

bool User::iddir(char *a,char *b,char* &c){
  x.reset(3,strlen(a)*5);
  strcpy(x.t[0],d.t[2]);
  strcpy(x.t[1],a);
  strcpy(x.t[2],b);
  if(mc.queryd("select id_arch from arch where id_user='%s' and name_arch='%s' and id_dir='%s' and data='0-dir-0'",x,3)) return 1;
  if(mc.outpoint(c)) return 1;
  if(strcmp(c,"\0")!=0) return 1;
  return 0;
}

bool User::iddir(const char *a,const char *b,char* &c){
  x.reset(3,strlen(a)*5);
  strcpy(x.t[0],d.t[2]);
  strcpy(x.t[1],a);
  strcpy(x.t[2],b);
  if(mc.queryd("select id_arch from arch where id_user='%s' and name_arch='%s' and id_dir='%s' and data='0-dir-0'",x,3)) return 1;
  if(mc.outpoint(c)) return 1;
  if(strcmp(c,"\0")!=0) return 1;
  return 0;
}

bool User::renamedoc(char *a,char *b,char *c){
  x.reset(4,strlen(a)*5);
  strcpy(x.t[0],b);
  strcpy(x.t[1],d.t[2]);
  strcpy(x.t[2],a);
  strcpy(x.t[3],c);
  if(mc.queryd("update arch set name_arch='%s' where id_user='%s' and name_arch='%s' and id_dir='%s'",x,4)) return 1;
  return 0;
}

bool User::renamedoc(const char *a,const char *b,const char *c){
  x.reset(4,strlen(a)*5);
  strcpy(x.t[0],b);
  strcpy(x.t[1],d.t[2]);
  strcpy(x.t[2],a);
  strcpy(x.t[3],c);
  if(mc.queryd("update arch set name_arch='%s' where id_user='%s' and name_arch='%s' and id_dir='%s'",x,4)) return 1;
  return 0;
}

bool User::inarch(Table &c,int s){
  strcpy(c.t[0],d.t[2]);
  if(mc.indata("insert into arch(id_user,name_arch,id_dir,data) values('%s','%s','%s','%s')",c,4,s)) return 1;
  return 0;
}

bool User::indir(char *a,char *b){
  x.reset(3,strlen(a)*5);
  strcpy(x.t[0],d.t[2]);
  strcpy(x.t[1],a);
  strcpy(x.t[2],b);
  if(mc.queryd("insert into arch(id_user,name_arch,id_dir,data) values('%s','%s','%s','0-dir-0')",x,3)) return 1;
  return 0;
}

bool User::indir(const char *a,const char *b){
  x.reset(3,strlen(a)*5);
  strcpy(x.t[0],d.t[2]);
  strcpy(x.t[1],a);
  strcpy(x.t[2],b);
  if(mc.queryd("insert into arch(id_user,name_arch,id_dir,data) values('%s','%s','%s','0-dir-0')",x,3)) return 1;
  return 0;
}

bool User::outarch(char *a,char *b,Table &c){
  x.reset(3,strlen(a)*5);
  strcpy(x.t[0],d.t[2]);
  strcpy(x.t[1],a);
  strcpy(x.t[2],b);
  if(mc.queryd("select data from arch where id_user='%s' and name_arch='%s' and id_dir='%s'",x,3)) return 1;
  if(mc.outdata(c)) return 1;
  return 0;
}

bool User::outarch(const char *a,const char *b,Table &c){
  x.reset(3,strlen(a)*5);
  strcpy(x.t[0],d.t[2]);
  strcpy(x.t[1],a);
  strcpy(x.t[2],b);
  if(mc.queryd("select data from arch where id_user='%s' and name_arch='%s' and id_dir='%s'",x,3)) return 1;
  if(mc.outdata(c)) return 1;
  return 0;
}

bool User::outarch(char *a,char *b,Table &c,unsigned long* &i){
  x.reset(3,strlen(a)*5);
  strcpy(x.t[0],d.t[2]);
  strcpy(x.t[1],a);
  strcpy(x.t[2],b);
  if(mc.queryd("select data from arch where id_user='%s' and name_arch='%s' and id_dir='%s'",x,3)) return 1;
  if(mc.outdata(c,i)) return 1;
  return 0;
}

bool User::outarch(const char *a,const char *b,Table &c,unsigned long* &i){
  x.reset(3,strlen(a)*5);
  strcpy(x.t[0],d.t[2]);
  strcpy(x.t[1],a);
  strcpy(x.t[2],b);
  if(mc.queryd("select data from arch where id_user='%s' and name_arch='%s' and id_dir='%s'",x,3)) return 1;
  if(mc.outdata(c,i)) return 1;
  return 0;
}

bool User::delarch(char *a,char *b){
  x.reset(3,strlen(a)*5);
  strcpy(x.t[0],d.t[2]);
  strcpy(x.t[1],a);
  strcpy(x.t[2],b);
  if(mc.queryd("delete from arch where id_user='%s' and name_arch='%s' and id_dir='%s'",x,3)) return 1;
  return 0;
}

bool User::delarch(const char *a,const char *b){
  x.reset(3,strlen(a)*5);
  strcpy(x.t[0],d.t[2]);
  strcpy(x.t[1],a);
  strcpy(x.t[2],b);
  if(mc.queryd("delete from arch where id_user='%s' and name_arch='%s' and id_dir='%s'",x,3)) return 1;
  return 0;
}

bool User::deldir(char *c){
  Table a(1,1);
  Table o(2,strlen(c)*5);
  strcpy(o.t[0],c);
  strcpy(o.t[1],d.t[2]);
  if(mc.queryd("select id_arch from arch where data='0-dir-0' and id_dir='%s' and id_user='%s'",o,2)) return 1;
  if(mc.outtable(a)) return 1;
  if(!(strcmp(a.t[0],"\0")==0)) for(int i=0;i<a.y;i++) deldir(a.t[i]);
  if(mc.queryd("delete from arch where id_dir='%s' and id_user='%s'",o,2)) return 1;
  if(mc.queryd("delete from arch where id_arch='%s' and id_user='%s'",o,2)) return 1;
  return 0;
}

bool User::deldir(const char *c){
  Table a(1,1);
  Table o(2,strlen(c)*5);
  strcpy(o.t[0],c);
  strcpy(o.t[1],d.t[2]);
  if(mc.queryd("select id_arch from arch where data='0-dir-0' and id_dir='%s' and id_user='%s'",o,2)) return 1;
  if(mc.outtable(a)) return 1;
  if(!(strcmp(a.t[0],"\0")==0)) for(int i=0;i<a.y;i++) deldir(a.t[i]);
  if(mc.queryd("delete from arch where id_dir='%s' and id_user='%s'",o,2)) return 1;
  if(mc.queryd("delete from arch where id_arch='%s' and id_user='%s'",o,2)) return 1;
  return 0;
}

bool User::delall(char *c){
  Table a(1,1);
  Table o(2,strlen(c)*5);
  strcpy(o.t[0],c);
  strcpy(o.t[1],d.t[2]);
  if(mc.queryd("select id_arch from arch where data='0-dir-0' and id_dir='%s' and id_user='%s'",o,2));
  if(mc.outtable(a));
  if(!(strcmp(a.t[0],"\0")==0)) for(int i=0;i<a.y;i++) deldir(a.t[i]);
  if(mc.queryd("delete from arch where id_dir='%s' and id_user='%s'",o,2)) return 1;
  return 0;
}

bool User::delall(const char *c){
  Table a(1,1);
  Table o(2,strlen(c)*5);
  strcpy(o.t[0],c);
  strcpy(o.t[1],d.t[2]);
  if(mc.queryd("select id_arch from arch where data='0-dir-0' and id_dir='%s' and id_user='%s'",o,2));
  if(mc.outtable(a));
  if(!(strcmp(a.t[0],"\0")==0)) for(int i=0;i<a.y;i++) deldir(a.t[i]);
  if(mc.queryd("delete from arch where id_dir='%s' and id_user='%s'",o,2)) return 1;
  return 0;
}

bool User::movdoc(char *a,char *b,char *c){
  x.reset(4,strlen(a)*5);
  strcpy(x.t[0],c);
  strcpy(x.t[1],d.t[2]);
  strcpy(x.t[2],a);
  strcpy(x.t[3],b);
  if(mc.queryd("update arch set id_dir='%s' where id_user='%s' and name_arch='%s' and id_dir='%s'",x,4)) return 1;
  return 0;
}

bool User::movdoc(const char *a,const char *b,const char *c){
  x.reset(4,strlen(a)*5);
  strcpy(x.t[0],c);
  strcpy(x.t[1],d.t[2]);
  strcpy(x.t[2],a);
  strcpy(x.t[3],b);
  if(mc.queryd("update arch set id_dir='%s' where id_user='%s' and name_arch='%s' and id_dir='%s'",x,4)) return 1;
  return 0;
}

bool User::movall(char *a,char *b){
  x.reset(4,strlen(a)*5);
  strcpy(x.t[0],b);
  strcpy(x.t[1],d.t[2]);
  strcpy(x.t[2],a);
  strcpy(x.t[3],b);
  if(mc.queryd("update arch set id_dir='%s' where id_user='%s' and id_dir='%s' and not(id_arch='%s')",x,4)) return 1;
  return 0;
}

bool User::movall(const char *a,const char *b){
  x.reset(4,strlen(a)*5);
  strcpy(x.t[0],b);
  strcpy(x.t[1],d.t[2]);
  strcpy(x.t[2],a);
  strcpy(x.t[3],b);
  if(mc.queryd("update arch set id_dir='%s' where id_user='%s' and id_dir='%s' and not(id_arch='%s')",x,4)) return 1;
  return 0;
}

bool User::coparch(char *a,char *b,char *c){
  x.reset(4,strlen(a)*5);
  strcpy(x.t[0],c);
  strcpy(x.t[1],d.t[2]);
  strcpy(x.t[2],a);
  strcpy(x.t[3],b);
  if(mc.queryd("insert into arch(id_user,name_arch,id_dir,data) select id_user,name_arch,'%s',data from arch where id_user='%s' and name_arch='%s' and id_dir='%s'",x,4)) return 1;
  return 0;
}

bool User::coparch(const char *a,const char *b,const char *c){
  x.reset(4,strlen(a)*5);
  strcpy(x.t[0],c);
  strcpy(x.t[1],d.t[2]);
  strcpy(x.t[2],a);
  strcpy(x.t[3],b);
  if(mc.queryd("insert into arch(id_user,name_arch,id_dir,data) select id_user,name_arch,'%s',data from arch where id_user='%s' and name_arch='%s' and id_dir='%s'",x,4)) return 1;
  return 0;
}

bool User::copdir(char *a,char *b,char *c){
  Table w(1,strlen(a));
  Table o(4,strlen(a));
  strcpy(o.t[0],c);
  strcpy(o.t[1],d.t[2]);
  strcpy(o.t[2],a);
  strcpy(o.t[3],b);
  if(mc.queryd("insert into arch(id_user,name_arch,id_dir,data) select id_user,name_arch,%s,data from arch where id_user='%s' and id_arch='%s' and id_dir='%s'",o,4)) return 1;
  if(mc.queryd("select id_arch from arch where id_dir='%s' and id_user='%s' and name_arch=(select name_arch from arch where id_arch='%s')",o,3)) return 1;
  if(mc.outpoint(o.t[0])) return 1;
  if(mc.queryd("insert into arch(id_user,name_arch,id_dir,data) select id_user,name_arch,%s,data from arch where id_user='%s' and id_dir='%s' and not(data='0-dir-0')",o,3)) return 1;
  strcpy(w.t[0],o.t[2]);
  if(mc.queryd("select id_arch from arch where id_dir='%s' and data='0-dir-0'",w,1)) return 1;
  if(mc.outtable(w)) return 1;
  if(!(strcmp(w.t[0],"\0")==0)) for(int i=0;i<w.y;i++) copdir(w.t[i],o.t[2],o.t[0]);
  return 0;
}

bool User::copdir(const char *a,const char *b,const char *c){
  Table w(1,strlen(a));
  Table o(4,strlen(a));
  strcpy(o.t[0],c);
  strcpy(o.t[1],d.t[2]);
  strcpy(o.t[2],a);
  strcpy(o.t[3],b);
  if(mc.queryd("insert into arch(id_user,name_arch,id_dir,data) select id_user,name_arch,%s,data from arch where id_user='%s' and id_arch='%s' and id_dir='%s'",o,4)) return 1;
  if(mc.queryd("select id_arch from arch where id_dir='%s' and id_user='%s' and name_arch=(select name_arch from arch where id_arch='%s')",o,3)) return 1;
  if(mc.outpoint(o.t[0])) return 1;
  if(mc.queryd("insert into arch(id_user,name_arch,id_dir,data) select id_user,name_arch,%s,data from arch where id_user='%s' and id_dir='%s' and not(data='0-dir-0')",o,3)) return 1;
  strcpy(w.t[0],o.t[2]);
  if(mc.queryd("select id_arch from arch where id_dir='%s' and data='0-dir-0'",w,1)) return 1;
  if(mc.outtable(w)) return 1;
  if(!(strcmp(w.t[0],"\0")==0)) for(int i=0;i<w.y;i++) copdir(w.t[i],o.t[2],o.t[0]);
  return 0;
}

bool User::copall(char *a,char *b){
  Table w(1,1);
  Table o(3,strlen(a));
  strcpy(o.t[0],b);
  strcpy(o.t[1],d.t[2]);
  strcpy(o.t[2],a);
  if(mc.queryd("insert into arch(id_user,name_arch,id_dir,data) select id_user,name_arch,%s,data from arch where id_user='%s' and id_dir='%s' and not(data='0-dir-0')",o,3)) return 1;
  if(mc.queryd("select id_arch from arch where not(id_dir='%s') and id_user='%s' and id_dir='%s' and data='0-dir-0'",o,3)) return 1;
  if(mc.outtable(w));
  if(!(strcmp(w.t[0],"\0")==0)) for(int i=0;i<w.y;i++) copdir(w.t[i],o.t[2],o.t[0]);
  return 0;
}

bool User::copall(const char *a,const char *b){
  Table w(1,1);
  Table o(3,strlen(a));
  strcpy(o.t[0],b);
  strcpy(o.t[1],d.t[2]);
  strcpy(o.t[2],a);
  if(mc.queryd("insert into arch(id_user,name_arch,id_dir,data) select id_user,name_arch,%s,data from arch where id_user='%s' and id_dir='%s' and not(data='0-dir-0')",o,3)) return 1;
  if(mc.queryd("select id_arch from arch where not(id_dir='%s') and id_user='%s' and id_dir='%s' and data='0-dir-0'",o,3)) return 1;
  if(mc.outtable(w));
  if(!(strcmp(w.t[0],"\0")==0)) for(int i=0;i<w.y;i++) copdir(w.t[i],o.t[2],o.t[0]);
  return 0;
}

bool User::varch(char *a,Table &c){
  x.reset(2,strlen(a));
  strcpy(x.t[0],d.t[2]);
  strcpy(x.t[1],a);
  if(mc.queryd("select name_arch from arch where id_user='%s' and id_dir='%s' and not(data='0-dir-0')",x,2)) return 1;
  if(mc.outtable(c)) return 1;
  return 0;
}

bool User::varch(const char *a,Table &c){
  x.reset(2,strlen(a));
  strcpy(x.t[0],d.t[2]);
  strcpy(x.t[1],a);
  if(mc.queryd("select name_arch from arch where id_user='%s' and id_dir='%s' and not(data='0-dir-0')",x,2)) return 1;
  if(mc.outtable(c)) return 1;
  return 0;
}

bool User::vdir(char *a,Table &c){
  x.reset(2,strlen(a));
  strcpy(x.t[0],d.t[2]);
  strcpy(x.t[1],a);
  if(mc.queryd("select name_arch from arch where id_user='%s' and id_dir='%s' and data='0-dir-0'",x,2)) return 1;
  if(mc.outtable(c)) return 1;
  return 0;
}

bool User::vdir(const char *a,Table &c){
  x.reset(2,strlen(a));
  strcpy(x.t[0],d.t[2]);
  strcpy(x.t[1],a);
  if(mc.queryd("select name_arch from arch where id_user='%s' and id_dir='%s' and data='0-dir-0'",x,2)) return 1;
  if(mc.outtable(c)) return 1;
  return 0;
}

bool User::vall(char *a,Table &c){
  x.reset(2,strlen(a));
  strcpy(x.t[0],d.t[2]);
  strcpy(x.t[1],a);
  if(mc.queryd("select name_arch from arch where id_user='%s' and id_dir='%s'",x,2)) return 1;
  if(mc.outtable(c)) return 1;
  return 0;
}

bool User::vall(const char *a,Table &c){
  x.reset(2,strlen(a));
  strcpy(x.t[0],d.t[2]);
  strcpy(x.t[1],a);
  if(mc.queryd("select name_arch from arch where id_user='%s' and id_dir='%s'",x,2)) return 1;
  if(mc.outtable(c)) return 1;
  return 0;
}

bool User::vuser(Table &c){
  if(mc.query("select name from user where not(id=0)")) return 1;
  if(mc.outtable(c)) return 1;
  return 0;
}
