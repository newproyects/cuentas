#include "user.h"

int main(){
  User us("angel","pollo");
  Table x(1,1);
  unsigned long* i;

  us.id();

  //FILE *fp= fopen("main.cpp", "rb");
  FILE *fp= fopen("venom2.jpg", "rb");
  fseek(fp, 0, SEEK_END);
  int flen = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  Table d(4,flen+1);
  int size = fread(d.t[3],1,flen,fp);


  fclose(fp);
  strcpy(d.t[0],"id");
  //strcpy(d.t[1],"main.cpp");
  strcpy(d.t[1],"venom2.jpg");
  strcpy(d.t[2],"0");

  //for(int j=0;j<4;j++) cout << d.t[j] << endl;
  
  us.inarch(d,flen);
  
  /*
  cout << us.outarch("Makefile","330",x,i) << endl;
  cout << i << endl;
  cout << x.t[0] << endl;
  */
  
  return 0;
}
