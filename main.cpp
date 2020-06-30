#include "user.h"

int main(){
  User us("angel","pollo");
  bool b;
  Table x(1,4);

  us.id();

  cout << us.iddoc("carpetap","0",x) << endl;
  cout << us.deldir(x.t[0]) << endl;
  
  return 0;
}
