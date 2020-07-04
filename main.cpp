#include "user.h"

int main(){
  User us("angel","pollo");
  bool b;
  Table x(1,4);

  us.id();

  cout << us.idarch("carpetam","0",x.t[0]) << endl;
  cout << x.t[0] << endl;
  
  return 0;
}
