#include "user.h"

int main(){
  User us("tito","kmotito");
  bool b;

  us.id();
  cout << us.checkdoc("main.cpp","0") << endl;

  FILE *f;


  if(us.checkdoc("main.cpp","0")) cout << "Archivo ya existente en tu directorio\n";
  else{
    f=fopen("main.cpp","rb");
    if(f==NULL) cout << "Archivo inexistente" << endl;
    else{
      cout << "Arcbriendo archivo..." << endl;
      fseek(f,0,SEEK_END);
      int fl=ftell(f);
      char x[fl+1];
      fseek(f,0,SEEK_SET);
      fread(x,1,fl,f);
      fclose(f);


      if(us.inarch("main.cpp","0",x)) cout << "error de ingreso de archivo\n";
      else cout << "Archivo ingresado\n";
    
    }
  }

  cout << us.checkdoc("main.cpp","0") << endl;
  
  return 0;
}
