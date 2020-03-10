#include "GameMode.h"

GameMode::GameMode(){
  // Board board = new Board();
  // createMap(10,7,.5);
}

GameMode::~GameMode(){
  // delete ;
}

void GameMode::normalMode(int numRows, int numColumns, double density){
  char **arrGrid = Board::createMap(numRows, numColumns, density);

  char** nextGeneration;
  nextGeneration = new char*[numRows];
  for(int p = 0;p < numRows;++p){
    nextGeneration[p]= new char[numColumns];
  }

  //check for neighbors
  int counter = 0;
  for(int i =0;i<numRows;++i){
    for(int j = 0;j<numColumns;++j){
      counter = 0;
      if(i!=0 && i!=(numRows-1) && j!= 0 && j!= (numColumns-1)){//middle squares
        if(arrGrid[i-1][j]=='X'){
          counter++;
          // cout<<"counting"<<endl;
              }
        if(arrGrid[i-1][j-1]=='X'){
          cout<<"I AM COUNTING DOWN AND LEFT"<<endl;

          counter+1;
          cout<<"counter after entering: "<<counter<<endl;
              }
        if(arrGrid[i][j-1]=='X'){
          counter++;
        }
        if(arrGrid[i+1][j-1]=='X'){
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){
          counter++;
        }
        if(arrGrid[i+1][j+1]=='X'){
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){
          counter++;
        }
        if(arrGrid[i-1][j+1]=='X'){
          counter++;
        }
      }


      else if(i==0 && j==0 ){//top left corner
        if(arrGrid[i][j]=='X'){
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
        if(arrGrid[i+1][j+1]=='X'){ //right diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
      }

      else if(i==0 && j ==(numColumns-1)){ //top right corner
        if(arrGrid[i][j]=='X'){
          counter++;
        }
        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[i+1][j-1]=='X'){ //left diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
      }

      else if(i ==(numRows-1) && j ==0){//bottom left corner
        if(arrGrid[i][j]=='X'){
          counter++;
        }
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j+1]=='X'){ //right diagonal
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
      }

      else if(i ==(numRows-1)&& j ==(numColumns-1)){ //bottom right corner
        if(arrGrid[i][j]=='X'){
          counter++;
        }
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j-1]=='X'){ //left diagonal
          counter++;
        }
        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
      }
      else if(i == 0) && (j != numColumns-1 || j != 0)){ //middle top
        if(arrGrid[i][j]=='X'){
          counter++;
        }
        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
        if(arrGrid[i+1][j-1]=='X'){ //left diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
        if(arrGrid[i+1][j+1]=='X'){ //right diagonal
          counter++;
        }
      }
      else if(i == numRows-1) && (j != numColumns - 1 || j != 0)){ //middle bottom
        if(arrGrid[i][j]=='X'){
          counter++;
        }
        if(arrGrid[i-1][j-1]=='X'){ //left diagonal
          counter++;
        }
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j+1]=='X'){ //right diagonal
          counter++;
        }
        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
      }
      else if((i != 0 || i != numRows-1) && (j == 0)){ //middle left side
        if(arrGrid[i][j]=='X'){
          counter++;
        }
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j+1]=='X'){ //right above diagonal
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
        if(arrGrid[i+1][j+1]=='X'){ //right below diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
      }
      else if((i != 0 || i != numRows-1) && (j == numColumns-1)){ //middle right side
        if(arrGrid[i][j]=='X'){
          counter++;
        }
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j-1]=='X'){ //left above diagonal
          counter++;
        }
        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[i+1][j-1]=='X'){ //left below diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
      }

      //for checking
      cout<<"counter: "<<counter<<endl;

      //fill new generation based off counter
      if(counter <=1){
        nextGeneration[i][j]='-';
      }else if(counter == 2){
        nextGeneration[i][j]= arrGrid[i][j];
      }else if(counter ==3){
        nextGeneration[i][j]= 'X';
      }
      else{
        nextGeneration[i][j]= '-';
      }
    } //exit j for loop
  } //exit i for loop
  cout<<"new generation: "<<endl;
  for(int i = 0;i<numRows;i++){
    for(int j = 0;j<numColumns;j++){
      cout<<nextGeneration[i][j];
    }
    cout<<endl;
  }
}

void GameMode::doughnutMode(int numRows, int numColumns, double density){
  char **arrGrid = Board::createMap(numRows, numColumns, density);

  char** nextGeneration;
  nextGeneration = new char*[numRows];
  for(int p = 0;p < numRows;++p){
    nextGeneration[p]= new char[numColumns];
  }

  //check for neighbors
  int counter = 0;
  for(int i =0;i<numRows;++i){
    for(int j = 0;j<numColumns;++j){
      counter = 0;
      if(i!=0 && i!=(numRows-1) && j!= 0 && j!= (numColumns-1)){//middle squares
        if(arrGrid[i-1][j]=='X'){
          counter++;
          // cout<<"counting"<<endl;
              }
        if(arrGrid[i-1][j-1]=='X'){
          cout<<"I AM COUNTING DOWN AND LEFT"<<endl;

          counter+1;
          cout<<"counter after entering: "<<counter<<endl;
              }
        if(arrGrid[i][j-1]=='X'){
          counter++;
        }
        if(arrGrid[i+1][j-1]=='X'){
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){
          counter++;
        }
        if(arrGrid[i+1][j+1]=='X'){
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){
          counter++;
        }
        if(arrGrid[i-1][j+1]=='X'){
          counter++;
        }
      }


      else if(i==0 && j==0 ){//top left corner
        if(arrGrid[i][j]=='X'){
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
        if(arrGrid[i+1][j+1]=='X'){ //right bottom diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
        if(arrGrid[i+(numRows-1)][j+1]=='X'){ //top right diagonal
          counter++;
        }
        if(arrGrid[i+(numRows-1)][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i][j+ (numColumns-1)]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[i+1][j+ (numColumns-1)]=='X'){ //bottom left diagonal
          counter++;
        }
      }

      else if(i==0 && j ==(numColumns-1)){ //top right corner
        if(arrGrid[i][j]=='X'){
          counter++;
        }
        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[i+1][j-1]=='X'){ //left bottom diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
      }

      else if(i ==(numRows-1) && j ==0){//bottom left corner
        if(arrGrid[i][j]=='X'){
          counter++;
        }
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j+1]=='X'){ //right diagonal
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
      }

      else if(i ==(numRows-1)&& j ==(numColumns-1)){ //bottom right corner
        if(arrGrid[i][j]=='X'){
          counter++;
        }
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j-1]=='X'){ //left diagonal
          counter++;
        }
        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
      }
      else if(i == 0) && (j != numColumns-1 || j != 0)){ //middle top
        if(arrGrid[i][j]=='X'){
          counter++;
        }
        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
        if(arrGrid[i+1][j-1]=='X'){ //left diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
        if(arrGrid[i+1][j+1]=='X'){ //right diagonal
          counter++;
        }
      }
      else if(i == numRows-1) && (j != numColumns - 1 || j != 0)){ //middle bottom
        if(arrGrid[i][j]=='X'){
          counter++;
        }
        if(arrGrid[i-1][j-1]=='X'){ //left diagonal
          counter++;
        }
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j+1]=='X'){ //right diagonal
          counter++;
        }
        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
      }
      else if((i != 0 || i != numRows-1) && (j == 0)){ //middle left side
        if(arrGrid[i][j]=='X'){
          counter++;
        }
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j+1]=='X'){ //right above diagonal
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
        if(arrGrid[i+1][j+1]=='X'){ //right below diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
      }
      else if((i != 0 || i != numRows-1) && (j == numColumns-1)){ //middle right side
        if(arrGrid[i][j]=='X'){
          counter++;
        }
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j-1]=='X'){ //left above diagonal
          counter++;
        }
        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[i+1][j-1]=='X'){ //left below diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
      }

      //for checking
      cout<<"counter: "<<counter<<endl;

      //fill new generation based off counter
      if(counter <=1){
        nextGeneration[i][j]='-';
      }else if(counter == 2){
        nextGeneration[i][j]= arrGrid[i][j];
      }else if(counter ==3){
        nextGeneration[i][j]= 'X';
      }
      else{
        nextGeneration[i][j]= '-';
      }
    } //exit j for loop
  } //exit i for loop
  cout<<"new generation: "<<endl;
  for(int i = 0;i<numRows;i++){
    for(int j = 0;j<numColumns;j++){
      cout<<nextGeneration[i][j];
    }
    cout<<endl;
  }
}




int main(int argc, char const *argv[]) {
  GameMode *g = new GameMode;
  g->normalMode(3,3,.34);
  return 0;
}
