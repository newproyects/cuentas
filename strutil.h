#include <string.h>
#include <stdlib.h>
#include <cstdio>

class Table{
public:
  int x,y;
  char **t;
  Table();
  Table(int _y,int _x);
  ~Table();
  void init(int _y,int _x);
  void cln();
  void reset(int _y,int _x);
  void ins(char *q);
  char* insd(char *q);
  char* insd(const char *q);
  void equal(int i,char *q);
};
