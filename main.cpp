#include "user.h"

int main(){
  User us("coco","12345");
  bool b;
  Table x(1,1);

  us.id();

  us.vuser(x);
  for(int i=0;i<x.y;i++) cout << x.t[i] << endl;

  us.repswd("jimenez");

  us.vuser(x);
  for(int i=0;i<x.y;i++) cout << x.t[i] << endl;
  
  return 0;
}
