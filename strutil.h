#include <string.h>
#include <stdlib.h>
#include <cstdio>

class Table{
public:
  int x,y;
  char **t;
  Table(int _y,int _x);
  ~Table();
  void cln();
  void reset(int _y,int _x);
  void ins(char *q);
  char* insd(char *q);
  void equal(int i,char *q);
};
