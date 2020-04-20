#include <iostream>
#include <mysql.h>
#include <string.h>

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
  bool queryd(char c[],char d[]);
  bool query2d(char c[],char d1[],char d2[]);
  bool query3d(char c[],char d1[],char d2[],char d3[]);
};
