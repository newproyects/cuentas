#include "mycon.h"

class User{
private:
  Table d;
public:
  MyCon mc;
  Table x;
  User();
  User(char *a,char *b);
  User(const char *a,const char *b);
  ~User();
  void set(char *a,char *b);
  void set(const char *a,const char *b);
  bool id();
  bool active(bool b);
};
