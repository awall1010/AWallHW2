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


  int counter = 0;
  for(int i =0;i<numRows;++i){
    for(int j = 0;j<numColumns;++j){
      counter = 0;
      if(i!=0 && i!=(numRows-1) && j!= 0 && j!= (numColumns-1)){//middle squares
        // int counter = 0;
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
      }

      else if(i==0 && j ==(numColumns-1)){ //top right corner
        if(arrGrid[i][j]=='X'){
          counter++;
        }
      }

      else if(i ==(numRows-1) && j ==0){//bottom left corner
        if(arrGrid[i][j]=='X'){
          counter++;
        }
      }

      else if(i ==(numRows-1)&& j ==(numColumns-1)){
        if(arrGrid[i][j]=='X'){
          counter++;
        }
      }

cout<<"counter: "<<counter<<endl;


          if(counter <=1){
            nextGeneration[i][j]='-';
                }
          else if(counter == 2){
            nextGeneration[i][j]= arrGrid[i][j];
                }
          else if(counter ==3){
            nextGeneration[i][j]= 'X';
                }
          else{
            nextGeneration[i][j]= '-';
                }

                // counter = 0;
              }
          // counter = 0;
      }



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
