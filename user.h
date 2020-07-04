#include "mycon.h"

class User{
private:
  MyCon mc;
  Table d;
  Table x;
public:
  User();
  User(char *a,char *b);
  User(const char *a,const char *b);
  ~User();
  void set(char *a,char *b);
  void set(const char *a,const char *b);
  bool check();
  bool create();
  bool del();
  bool id();
  bool setact(bool b);
  bool setacs(bool b);
  bool getacs(bool &b);
  bool checkdoc(char *a,char *b);
  bool checkdoc(const char *a,const char *b);
  bool iddoc(char *a,char *b,char* &c);
  bool iddoc(const char *a,const char *b,char* &c);
  bool idarch(char *a,char *b,char* &c);
  bool idarch(const char *a,const char *b,char* &c);
  bool iddir(char *a,char *b,char* &c);
  bool iddir(const char *a,const char *b,char* &c);
  bool renamedoc(char *a,char *b,char *c);
  bool renamedoc(const char *a,const char *b,const char *c);
  bool inarch(char *a,char *b,char *c);
  bool inarch(const char *a,const char *b,char *c);
  bool indir(char *a,char *b);
  bool indir(const char *a,const char *b);
  bool delarch(char *a,char *b);
  bool delarch(const char *a,const char *b);
  bool deldir(char *c);
  bool deldir(const char *c);
  bool delall(char *c);
  bool delall(const char *c);
  bool movdoc(char *a,char *b,char *c);
  bool movdoc(const char *a,const char *b,const char *c);
  bool movall(char *a,char *b);
  bool movall(const char *a,const char *b);
  bool coparch(char *a,char *b,char *c);
  bool coparch(const char *a,const char *b,const char *c);
  bool copdir(char *a,char *b,char *c);
  bool copdir(const char *a,const char *b,const char *c);
  bool copall(char *a,char *b);
  bool copall(const char *a,const char *b);
  bool varch(char *a,Table &c);
  bool varch(const char *a,Table &c);
  bool vdir(char *a,Table &c);
  bool vdir(const char *a,Table &c);
  bool vall(char *a,Table &c);
  bool vall(const char *a,Table &c);
};
