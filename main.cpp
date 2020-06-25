#include "mycon.h"

int main(){
  MyCon mc("localhost","root","tabladelfin","counts");
  FILE *f;
  Table d(2,10);

  strcpy(d.t[0],"100");
  strcpy(d.t[1],"counts.sql");
  

  f=fopen(d.t[1],"rb");
    if(f==NULL) cout << "Archivo inexistente" << endl;
    else{
      cout << "Arcbriendo archivo..." << endl;
      fseek(f,0,SEEK_END);
      int fl=ftell(f);
      Table x(3,fl+1);
      fseek(f,0,SEEK_SET);
      fread(x.t[2],1,fl,f);
      fclose(f);

      
      strcpy(x.t[0],d.t[0]);
      strcpy(x.t[1],d.t[1]);


      if(mc.indata("insert into arch(id_user,name_arch,data) values('%s','%s','%s')",x,3)) cout << "error de ingreso de archivo\n";
      else cout << "Archivo ingresado\n";
    }
  
  return 0;
}
