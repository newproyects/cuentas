#include "strutil.h"

Table::Table(int _y,int _x){
  x=_x;
  y=_y;
  t=new char*[y];
  for(int i=0;i<y;i++){
    t[i]=new char[x];
    strcpy(t[i],"");
  }
}

Table::~Table(){
  for(int i=0;i<y;i++) delete[] t[i];
  delete[] t;
}

void Table::cln(){
  t=new char*[y];
  for(int i=0;i<y;i++){
    t[i]=new char[x];
    strcpy(t[i],"");
  }
}

void Table::reset(int _y,int _x){
  x=_x;
  y=_y;
  t=new char*[y];
  for(int i=0;i<y;i++){
    t[i]=new char[x];
    strcpy(t[i],"");
  }
}

void insert(char q[],char c[][20]){
  char x[200][strlen(q)];
  int j=0;
  int k=0;
  int cc=0;
  for(int i=0;i<strlen(q);i++){
    if(q[i]!='%')x[j][k++]=q[i];
    else{
      strcpy(x[++j],c[cc++]);
      j++;
      k=0;
    }
  }
  for(int i=1;i<=j;i++)strcat(x[0],x[i]);
  strcpy(q,x[0]);
}
