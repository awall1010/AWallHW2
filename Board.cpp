#include <iostream>
using namespace std;
#include "Board.h"


  Board::Board(){

  }

  Board::~Board(){
  }


  char **Board::createMap(int r, int c, float d){
  numRows = r;
  numColumns = c;
  density = d;
  double a = 0;
  int counter = 0;

  int maxValue = d*(numRows*numColumns);

  char** myGrid;
  myGrid = new char*[numRows];
  for(int i = 0;i < numRows;++i){
    myGrid[i]= new char[numColumns];
  }

  for(int i = 0; i < numRows; ++i){
    for(int j = 0; j < numColumns;++j){
      a = ((double) rand() / (RAND_MAX));
      // int  r;

      // cout<<"A: "<<a<<endl;

      if(a<d && counter<maxValue){
        myGrid[i][j]='X';
        counter++;
      }
      else{
        myGrid[i][j] = '-';
      }


    }
  }

  for(int i = 0; i < numRows; ++i){
    for(int j = 0; j < numColumns;++j){
      cout <<myGrid[i][j];

    }
    cout<<endl;
  }
  return myGrid;
  delete myGrid;
}


void normalMode(char **myGrid){

}

//
// int main(int argc, char const *argv[]) {
//   Board *b = new Board();
//   b->createMap(10,7,.5);
//   return 0;
// }
