#include <string.h>
#include <stdlib.h>

class Table{
private:
  int x,y;
  
public:
  char **t;
  Table(int _y,int _x);
  ~Table();
  void cln();
  void reset(int _y,int _x);
};

void insert(char q[],char **c);
