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
  for(int i=0;i<y;i++){
    strcpy(t[i],"");
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
    strcpy(t[i],"");
  }
}

void Table::ins(char q[]){
  int n=strlen(q);
  char x[200][500];
  int j=0;
  int k=0;
  int l=0;

  for(int i=0;i<n;i++){
    if(q[i]!='%')x[j][k++]=q[i];
    else{
      strcpy(x[++j],t[l++]);
      j++;
      i++;
      k=0;
    }
  }
  for(int i=1;i<=j;i++)strcat(x[0],x[i]);
  strcpy(q,x[0]);
}

void Table::equal(int i,char q[]){
  delete[] t[i];
  t[i]=q;
}
