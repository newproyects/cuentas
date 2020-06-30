#include "user.h"

int main(){
  User us("tito","kmotito");
  bool b;

  us.id();
  cout << us.checkdoc("cartito","0") << endl;

  FILE *f;


  if(us.checkdoc("cartito","0")) cout << "Directorio ya existente en tu directorio\n";
  else{
    cout << "Creando directorio..." << endl;
    if(us.indir("cartito","0")) cout << "error al crear directorio\n";
    else cout << "Directorio creado\n";    
  }

  cout << us.checkdoc("cartito","0") << endl;
  
  return 0;
}
