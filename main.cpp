#include "user.h"

int main(){
  User us("tito","kmotito");
  bool b;
  Table x(1,4);

  us.id();

  if(us.movdoc("Makefile","0","150")) cout << "Error al mover Makefile\n";
  else cout << "Makefile movido correctamente\n";
  
  return 0;
}
