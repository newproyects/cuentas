#include "user.h"

int main(){
  User us("root","toor");
  bool b;

  us.id();
  cout << us.x.t[0] << endl;
  us.setact(0);
  us.getacs(b);
  cout << b << endl;
  us.setacs(1);
  us.getacs(b);
  cout << b << endl;
  
  return 0;
}
