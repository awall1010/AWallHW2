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
  // delete myGrid;
}


char **Board::createMap(string fileName){
ifstream inFS;
int rows;
int columns;
string readString = "";
string outputString = "";
inFS.open(fileName);
int lineCount=0;

if(!inFS.is_open()){
  cout<<"couldn't open file. "<<endl;
}

inFS >> numRows >> numColumns;
cout<<"rows: "<<numRows<<" columns: "<<numColumns<<endl;
while(!inFS.eof()){
  inFS>>readString;
  if(!inFS.fail()){
    outputString+=readString;
  }
}
cout<<"output string: "<<outputString<<endl;
cout<<"output string size: "<<outputString.size()<<endl;
// double a = 0;
int counter = -1;

// int maxValue = d*(numRows*numColumns);

char** myGrid;
myGrid = new char*[numRows];
for(int i = 0;i < numRows;++i){
  myGrid[i]= new char[numColumns];
}

// string sMap = stringMap.split(",");
for(int i = 0;i<numRows;++i){
  for(int j = 0;i<numColumns;++j){
    for(int c = 0; c<outputString.size();++c){
      myGrid[i][j] = outputString[c];
    }

    // counter++;
  }
}

for(int i = 0; i < numRows; ++i){
  for(int j = 0; j < numColumns;++j){
    cout <<myGrid[i][j];

  }
  cout<<endl;
}
return myGrid;
// delete myGrid;
}








//
// int main(int argc, char const *argv[]) {
//   Board *b = new Board();
//   b->createMap("input.txt");
//   return 0;
// }
