#include <iostream>
#include <fstream>
using namespace std;
//
string readFile(string fileName){
  ifstream inFS;
  string readString = "";
  string outputString = "";
  inFS.open(fileName);

  if(!inFS.is_open()){
    cout<<"couldn't open file."<<endl;
  }
  while(!inFS.eof()){
    inFS>>readString;
    if(inFS.fail()){
      outputString+=readString+"\n";
    }
  }
  inFS.close();
  return outputString;
}

// int main(int argc, char const *argv[]) {
//   int numRows;
//   int numColumns;
//   double density;
//   // cout<<"Enter number of rows: "<<endl;
//   // cin>>numRows;
//   // cout<<"Enter number of columns: "<<endl;
//   // cin>>numColumns;
//   // cout<< "Enter population density: "<<endl;
//   // cin>>density;
//
//   return 0;
// }
