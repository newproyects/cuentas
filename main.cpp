#include "user.h"

int main(){
  User us("angel","pollo");
  bool b;
  Table x(1,4);

  us.id();
  if(!us.checkdoc("main.cpp","0")) cout << "No se encontro main.cpp\n";
  else{
    cout << "Eliminando main.cpp...\n";
    if(us.delarch("main.cpp","0")) cout << "Error al eliminar\n";
    else cout << "Archivo eliminado\n";
  }
  
  return 0;
}
