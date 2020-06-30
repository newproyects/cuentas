#include "user.h"

int main(){
  User us("tito","kmotito");
  bool b;

  us.id();
  cout << us.checkdoc("a","0") << endl;


  if(!us.checkdoc("a","0")) cout << "Archivo(a) no encontrado\n";
  else if(us.checkdoc("b","0")) cout << "Archivo(b) ya existente\n";
  else{
    cout << "RENAME(a->b)..." << endl;
    if(us.renamedoc("a","b","0")) cout << "error de rename\n";
    else cout << "Nombre cambiado\n";    
  }

  cout << us.checkdoc("a","0") << endl;
  
  return 0;
}
