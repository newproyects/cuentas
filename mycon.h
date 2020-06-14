#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>
#include "strutil.h"

using namespace std;

class MyCon{
  private:
  MYSQL *con;
  MYSQL_RES *res;
  MYSQL_ROW row;
  bool v;
  public:
  MyCon(char ho[],char us[],char pw[],char db[]);
  void close();
  void error();
  void fail();
  bool query(char c[]);
  bool queryd(char c[],Table &d);
  bool outpoint(char q[]);
  bool outtable(Table &o);
};
