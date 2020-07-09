#include "user.h"

int main(){
  User us("angel","pollo");
  Table x(1,1);

  us.id();
  
  cout << us.outarch("Makefile","330",x) << endl;
  cout << x.t[0] << endl;
  
  return 0;
}
