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
};
