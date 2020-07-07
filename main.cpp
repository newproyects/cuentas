#include "user.h"

int main(){
  //User us("angel","pollo");
  User us;
  bool b=0;
  Table x(1,1);
  
  cout << us.getact(b) << endl;

  cout << b << endl;
  us.id();

  us.varch("0",x);

  for(int i=0;i<x.y;i++) cout << x.t[i] << endl;
  
  
  return 0;
}
