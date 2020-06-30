#include "user.h"

int main(){
  User us("tito","kmotito");
  bool b;
  Table x(1,4);

  us.id();
  cout << us.iddoc("mis","0",x) << endl;
  cout << x.t[0] << endl;
  
  return 0;
}
