#include <iostream>

using namespace std;

class Board{
  public:
    Board();
    ~Board();
    int numRows;
    int numColumns;
    float density = 0;

    char **createMap(int r, int c, float d);

};
