#include <iostream>
using namespace std;
#include "Board.h"

// class Board{
  // int numRows, numColumns;
// public:
  Board::Board(){

  }


  void Board::createMap(int r, int c){
  numRows = r;
  numColumns = c;
  char** myGrid;
  myGrid = new char*[numRows];
  for(int i = 0;i < numRows;++i){
    myGrid[i]= new char[numColumns];
  }

  for(int i = 0; i < numRows; ++i){
    for(int j = 0; j < numColumns;++j){
      myGrid[i][j] = '-';
    }
  }

  for(int i = 0; i < numRows; ++i){
    for(int j = 0; j < numColumns;++j){
      cout <<myGrid[i][j];

    }
    cout<<endl;
  }

  delete myGrid;
}

// int main(int argc, char const *argv[]) {
//   Board *b = new Board();
//   b->createMap(10,7);
//   return 0;
// }
