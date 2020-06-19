#include "mycon.h"

int main(){
  char c[]="select id from user where name='%s' and pswd='%s'";
  Table data(10,40);
  MyCon mc("localhost","root","tabladelfin","counts");
  char result[10];
  char *q;
  FILE *f;

  cout << "ingresar nombre: ";
  cin.getline(data.t[0],10,'\n');
  fflush(stdin);
  cout << "ingresar contraseña: ";
  cin.getline(data.t[1],8,'\n');
  
  
  if(mc.queryd(c,data)) mc.fail();

  mc.outpoint(result);

  cout << "id: " << (strcmp(result,"")==0 ? "error de acceso" : result) << endl;

  if(strcmp(result,"")!=0){
    Table user(10,40);
    cout << "tabla de usuarios\n";
    mc.query("select * from user");
    mc.outtable(user);
    for(int i=0;i<user.y;i++) cout << user.t[i] << endl;
    
    cout << "ingresar archivo: ";
    cin.getline(data.t[2],20,'\n');
    
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

      q="insert into arch(id_user,name_arch,data) values('%s','%s','%s')";

      if(mc.indata(q,d)) cout << "error de ingreso de archivo\n";
      else cout << "Archivo ingresado\n";

      cout << "archivo que desea ver: ";
      cin.getline(d.t[1],20,'\n');
      q="select data from arch where id_user='%s' and name_arch='%s'";
      
      unsigned long* l;

      if(mc.outdata(q,l,d))cout << "Archivo no encontrado\n";
      else{
	cout << q << endl;
	cout << l << endl;
      }
    }
  }
  
  mc.close();
  return 0;
}
