#include "mycon.h"

int main(){
  MyCon mc("localhost","root","tabladelfin","counts");
  FILE *f;
  Table d(2,10);

  strcpy(d.t[0],"100");
  strcpy(d.t[1],"counts.sql");
  
  mc.queryd("select data from arch where id_user='%s' and name_arch='%s'",d,2);
  Table x(1,1);
  unsigned long *l;
  mc.outdata(x,l);

  cout << l << endl;
  cout << x.t[0] << endl;
    
  return 0;
}
