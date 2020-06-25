#include <iostream>
#include "strutil.h"

using namespace std;

int main(){
  Table d(2,10);
  char *q=new char[40];

  strcpy(d.t[0]," uno ");
  strcpy(d.t[1]," dos ");
  strcpy(q,"consulta smn('%s')");

  cout << d.insd("consulta smn('%s')",1) << endl;
  
  delete[] q;
  return 0;
}
