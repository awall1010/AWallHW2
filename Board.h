#include <iostream>
using namespace std;

class Board{
public:
  Board();
  ~Board();
  int numRows;
  int numColumns;

  void createMap(int r, int c);

};
