#include "user.h"

int main(){
  User us("tito","kmotito");
  bool b;
  Table x(1,4);

  us.id();

  if(us.movall("0","150")) cout << "Error al mover archivos\n";
  else cout << "Archivos movidos correctamente\n";
  
  return 0;
}
