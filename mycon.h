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
  MyCon();
  MyCon(char *ho,char *us,char *pw,char *db);
  MyCon(const char *ho,const char *us,const char *pw,const char *db);
  void init(char *ho,char *us,char *pw,char *db);
  void init(const char *ho,const char *us,const char *pw,const char *db);
  void close();
  void error();
  void fail();
  bool query(char *q);
  bool query(const char *q);
  bool queryd(char *q,Table &d,int i);
  bool queryd(const char *q,Table &d,int i);
  bool outpoint(char *q);
  bool outtable(Table &d);
  bool indata(char *q,Table &d,int i,int s);
  bool indata(const char *q,Table &d,int i,int s);
  bool outdata(Table &d);
  bool outdata(Table &d,unsigned long* &i);
};
