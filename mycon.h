#include <iostream>
#include <string.h>
#include <mysql.h>
#include "strutil.h"

using namespace std;

class MyCon{
private:
  MYSQL *con;
  bool v;
public:
  MyCon(char ho[],char us[],char pw[],char db[]);
  void close();
  void error();
  void fail();
  bool query(char c[]);
  bool queryd(char c[],char d[][20]);
};
