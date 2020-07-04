#include "user.h"

int main(){
  User us("angel","pollo");
  bool b;
  Table x(1,1);

  us.id();

  us.vall("334",x);
  for(int i=0;i<x.y;i++) cout << x.t[i] << endl;
  
  return 0;
}
