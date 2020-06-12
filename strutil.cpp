#include "strutil.h"

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
