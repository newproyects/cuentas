#include "user.h"

User::User(){
  mc.init("localhost","program","margorp","counts");
  d.init(3,10);
  x.init(1,1);
}

User::~User(){
  mc.close();
}
