#include "user.h"

int main(){
  User us("angel","pollo");
  Table x(1,1);
  unsigned long* i;

  us.id();

  us.delarch("main.cpp","0");
  /*
  cout << us.outarch("Makefile","330",x,i) << endl;
  cout << i << endl;
  cout << x.t[0] << endl;
  */
  
  return 0;
}
