
#include "mycon.h"

int main(){
  char c[]="select id from user where name='%s' and pswd='%s'";
  Table data(10,40);
  MyCon mc("localhost","root","tabladelfin","counts");
  char result[10];
  FILE *f;

  cout << "ingresar nombre: ";
  cin.getline(data.t[0],10,'\n');
  fflush(stdin);
  cout << "ingresar contraseña: ";
  cin.getline(data.t[1],8,'\n');
  cout << "ingresar archivo: ";
  cin.getline(data.t[2],20,'\n');
  
  
  if(mc.queryd(c,data)) mc.fail();

  mc.outpoint(result);

  cout << "id: " << (strcmp(result,"")==0 ? "error de acceso" : result) << endl;

  if(strcmp(result,"")!=0){
    /*
    cout << "tabla de usuarios\n";
    mc.query("select * from user");
    mc.outtable(data);
    for(int i=0;i<data.y;i++) cout << data.t[i] << endl;
    */
    f=fopen(data.t[2],"rb");
    if(f==NULL) cout << "Archivo inexistente" << endl;
    else{
      cout << "Arcbriendo archivo..." << endl;
      fseek(f,0,SEEK_END);
      int fl=ftell(f);
      Table d(3,fl+1);
      fseek(f,0,SEEK_SET);
      fread(d.t[2],1,fl,f);
      fclose(f);

      strcpy(d.t[0],result);
      strcpy(d.t[1],data.t[2]);

      char *q="insert into arch(id_user,name,data) values('%s','%s','%s')";
      q=d.insd(q);
      cout << q << endl;
    }
  }
  
  mc.close();
  return 0;
}
