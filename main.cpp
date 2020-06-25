#include "user.h"

int main(){
  User us("root","toor");

  us.id();
  cout << us.x.t[0] << endl;
  us.setact(0);
  us.setacs(0);
  
  return 0;
}
