#include "strutil.h"

Table::Table(){}

Table::Table(int _y,int _x){
  x=_x;
  y=_y;
  t=new char*[y];
  for(int i=0;i<y;i++){
    t[i]=new char[x];
    strcpy(t[i],"\0");
  }
}

Table::~Table(){
  for(int i=0;i<y;i++) delete[] t[i];
  delete[] t;
}

void Table::init(int _y,int _x){
  x=_x;
  y=_y;
  t=new char*[y];
  for(int i=0;i<y;i++){
    t[i]=new char[x];
    strcpy(t[i],"\0");
  }
}

void Table::cln(){
  for(int i=0;i<y;i++){
    strcpy(t[i],"\0");
  }
}

void Table::reset(int _y,int _x){
  for(int i=0;i<y;i++) delete[] t[i];
  delete[] t;
  x=_x;
  y=_y;
  t=new char*[y];
  for(int i=0;i<y;i++){
    t[i]=new char[x];
    strcpy(t[i],"\0");
  }
}

char* Table::insd(char *q,int i){
  char *qu;
  switch(i){
  case 0:
    qu=new char[strlen(q)];
    strcpy(qu,q);
    break;
  case 1:
    qu=new char[strlen(q)+strlen(t[0])];
    snprintf(qu,strlen(q)+strlen(t[0]),q,t[0]);
    break;
  case 2:
    qu=new char[strlen(q)+strlen(t[0])+strlen(t[1])];
    snprintf(qu,strlen(q)+strlen(t[0])+strlen(t[1]),q,t[0],t[1]);
    break;
  case 3:
    qu=new char[strlen(q)+strlen(t[0])+strlen(t[1])+strlen(t[2])];
    snprintf(qu,strlen(q)+strlen(t[0])+strlen(t[1])+strlen(t[2]),q,t[0],t[1],t[2]);
    break;
  case 4:
    qu=new char[strlen(q)+strlen(t[0])+strlen(t[1])+strlen(t[2])+strlen(t[3])];
    snprintf(qu,strlen(q)+strlen(t[0])+strlen(t[1])+strlen(t[2])+strlen(t[3]),q,t[0],t[1],t[2],t[3]);
    break;
  }
  return qu;
}

char* Table::insd(const char *q,int i){
  char *qu;
  switch(i){
  case 0:
    qu=new char[strlen(q)];
    strcpy(qu,q);
    break;
  case 1:
    qu=new char[strlen(q)+strlen(t[0])];
    snprintf(qu,strlen(q)+strlen(t[0]),q,t[0]);
    break;
  case 2:
    qu=new char[strlen(q)+strlen(t[0])+strlen(t[1])];
    snprintf(qu,strlen(q)+strlen(t[0])+strlen(t[1]),q,t[0],t[1]);
    break;
  case 3:
    qu=new char[strlen(q)+strlen(t[0])+strlen(t[1])+strlen(t[2])];
    snprintf(qu,strlen(q)+strlen(t[0])+strlen(t[1])+strlen(t[2]),q,t[0],t[1],t[2]);
    break;
  case 4:
    qu=new char[strlen(q)+strlen(t[0])+strlen(t[1])+strlen(t[2])+strlen(t[3])];
    snprintf(qu,strlen(q)+strlen(t[0])+strlen(t[1])+strlen(t[2])+strlen(t[3]),q,t[0],t[1],t[2],t[3]);
    break;
  }
  return qu;
}

void Table::equal(int i,char *q){
  delete[] t[i];
  t[i]=q;
}
