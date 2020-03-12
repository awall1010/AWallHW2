#include <iostream>
#include <fstream>
#include "Board.h"
// #include "GameMode.h"
using namespace std;
//
// string readFile(string fileName){
//   ifstream inFS;
//   int rows;
//   int columns;
//   string readString = "";
//   string outputString = "";
//   inFS.open(fileName);
//   int lineCount=0;
//
//   if(!inFS.is_open()){
//     cout<<"couldn't open file. "<<endl;
//   }
//
//   // inFS >> rows >> columns;
//   while(!inFS.eof()){
//     inFS>>readString;
//     if(!inFS.fail()){
//       outputString+=readString + ",";
//     }
//   }
//
//
//   inFS.close();
//   // cout<<"read string: " <<readString<<endl;
//   // Board::createMap(rows, columns, outputString);
//
//   cout<<"rows: "<<rows<<endl;
//   cout<<"columns: "<<columns<<endl;
//   cout<<"outputString: " <<outputString<<endl;
//   // return outputString;
// }


int main(int argc, char const *argv[]) {
  int fileChoice;
  cout<<"Would you like to import a grid from a file or create a random one? "<<endl;
  cout<<"Enter 1 to import a file or 2 for random: "<<endl;
  cin>>fileChoice;

  if(fileChoice==1){ //still errors here
    // cout<<"enter a file: "<<endl;
    // string fileName;
    // cin>>fileName;
    // Board *fileBoard = new Board();
    // fileBoard->createMap(fileName);
  }
  else if(fileChoice==2){
    int modeChoice;
    cout<<"Normal Mode, Mirror Mode, or Doughnut Mode? "<<endl;
    cin>>modeChoice;
  }
  else{
    cout<<"INVALID CHOICE. "<<endl;
  }


  cout<<"enter a file: "<<endl;
  string fileName;
  cin>>fileName;
  cout<<endl;

  return 0;
}
