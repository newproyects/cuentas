#include "user.h"

int main(){
  User us("tito","kmotito");
  bool b;

  us.id();
  cout << us.checkdoc("a","0") << endl;
  
  return 0;
}
