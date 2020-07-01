#include "user.h"

int main(){
  User us("tito","kmotito");
  bool b;
  Table x(1,4);

  us.id();

  if(us.coparch("koko","150","0")) cout << "Error al copiar archivo\n";
  else cout << "Archivo copiado correctamente\n";
  
  return 0;
}
