#include <string.h>
#include <stdlib.h>

class Table{
private:
  int x,y;
  
public:
  char **t;
  Table(int _y,int _x);
  ~Table();
};

void insert(char q[],char c[][20]);
