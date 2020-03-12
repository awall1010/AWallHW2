#include "GameMode.h"

GameMode::GameMode(){
    // Board board = new Board();
    // createMap(10,7,.5);
    int numRows = 0;
    int numColumns = 0;
    double density= 0;
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
cout<<"NORMAL MODE "<<endl;
  int genCount = 0;
while( true){
  int counter = 0;

  cout<<"press enter to to produce another generation or control c to exit. "<<endl;
  cin.get();

  for(int i =0;i<numRows;++i){
    for(int j = 0;j<numColumns;++j){
      counter = 0;
      if(i!=0 && i!=(numRows-1) && j!= 0 && j!= (numColumns-1)){//middle squares
        if(arrGrid[i-1][j]=='X'){
          counter++;

              }
        if(arrGrid[i-1][j-1]=='X'){


          counter++;

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
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
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
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
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
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
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
      else if((i == 0) && (j != numColumns-1 && j != 0)){ //top row

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
      else if((i == numRows-1) && (j != numColumns-1 && j != 0)){ //bottom row
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
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
      else if((i != 0 && i != numRows-1) && (j == 0)){ // left column
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
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
      else if((i != 0 && i != numRows-1) && (j == numColumns-1)){ //far right column
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
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


  cout<<"new generation "<<++genCount <<": "<<endl;
  for(int i = 0;i<numRows;++i){
    for(int j = 0;j<numColumns;++j){

      cout<<nextGeneration[i][j];
    }

    cout<<endl;
  }

  bool isEqual = true;
  for(int i = 0;i<numRows;++i){
    for(int j = 0;j<numColumns;++j){
      if(arrGrid[i][j]!=nextGeneration[i][j]){
        isEqual = false;
      }
    }
  }

  if(isEqual==true){
    cout<<"population stabalized. Press enter to break. "<<endl;
    cin.get();
    return;

  }
  // if(arrGrid)


  for(int i = 0;i<numRows;++i){
    for(int j = 0;j<numColumns;++j){
      arrGrid[i][j]=nextGeneration[i][j];
    }
  }




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

              }
        if(arrGrid[i-1][j-1]=='X'){


          counter+1;
          // cout<<"counter after entering: "<<counter<<endl;
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

      else if(i==0 && j==0 ){ //top left corner
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
        if(arrGrid[i+1][j+1]=='X'){ //right bottom diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
        if(arrGrid[0][0]){
          counter++;
        }

      }

      else if(i==0 && j ==(numColumns-1)){ //top right corner
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[i+1][j-1]=='X'){ //left bottom diagonal
          counter++;
        }
        if(arrGrid[i+1][j]=='X'){ //below
          counter++;
        }
        if(arrGrid[numRows-1][j]=='X'){
          counter++;
        }
        if(arrGrid[numRows-1][j-1]=='X'){
          counter++;
        }
        if(arrGrid[numRows-1][0]=='X'){
          counter++;
        }
        if(arrGrid[i+1][0]=='X'){
          counter++;
        }
        if(arrGrid[0][0]=='X'){
          counter++;
        }

      }

      else if(i ==(numRows-1) && j ==0){//bottom left corner
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j+1]=='X'){ //right diagonal
          counter++;
        }
        if(arrGrid[i][j+1]=='X'){ //to the right
          counter++;
        }
        if(arrGrid[i][numColumns-1]=='X'){
          counter++;
        }
        if(arrGrid[i-1][numColumns-1]=='X'){
          counter++;
        }
        if(arrGrid[0][numColumns-1]=='X'){
          counter++;
        }
        if(arrGrid[0][j+1]=='X'){
          counter++;
        }
        if(arrGrid[0][j]=='X'){
          counter++;
        }

      }

      else if(i ==(numRows-1)&& j ==(numColumns-1)){ //bottom right corner
        //
        if(arrGrid[i-1][j]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j-1]=='X'){ //left diagonal
          counter++;
        }
        if(arrGrid[i][j-1]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[0][0]=='X'){
          counter++;
        }
        if(arrGrid[0][j]=='X'){
          counter++;
        }
        if(arrGrid[i][0]){
          counter++;
        }
        if(arrGrid[i-1][0]=='X'){
          counter++;
        }
        if(arrGrid[0][j-1]){
          counter++;
        }


      }

      else if((i == 0) && (j != numColumns-1 && j != 0)){ // top row

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
        if(arrGrid[numRows-1][j-1]=='X'){
          counter++;
        }
        if(arrGrid[numRows-1][j]=='X'){
          counter++;
        }
        if(arrGrid[numRows-1][j+1]=='X'){
          counter++;
        }


      }

      else if((i == numRows-1) && (j != numColumns - 1 && j != 0)){ // bottom row
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
        if(arrGrid[i][j+1]=='X'){ //left diagonal
          counter++;
        }
        if(arrGrid[i][j-1]=='X'){ //above
          counter++;
        }
        if(arrGrid[i-1][j-1]=='X'){ //right diagonal
          counter++;
        }
        if(arrGrid[i-1][j]=='X'){ //to the left
          counter++;
        }
        if(arrGrid[i-1][j+1]=='X'){ //to the right
          counter++;
        }
        if(arrGrid[0][j+1]=='X'){
          counter++;
        }
        if(arrGrid[0][j]=='X'){
          counter++;
        }
        if(arrGrid[0][j-1]=='X'){
          counter++;
        }
      }

      else if((i != 0 && i != numRows-1) && (j == 0)){ //left side
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
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
        if(arrGrid[i][numColumns-1]=='X'){ //below
          counter++;
        }
        if(arrGrid[i-1][numColumns-1]=='X'){ //below
          counter++;
        }
        if(arrGrid[i+1][numColumns-1]=='X'){ //below
          counter++;
        }
      }

      else if((i != 0 && i != numRows-1) && (j == numColumns-1)){ //right side
        // if(arrGrid[i][j]=='X'){
        //   counter++;
        // }
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
        if(arrGrid[i-1][0]=='X'){
          counter++;
        }
        if(arrGrid[i][0]=='X'){
          counter++;
        }
        if(arrGrid[i+1][0]=='X'){
          counter++;
        }
      }

      //for checking
      // cout<<"counter: "<<counter<<endl;

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
  cout<<endl;
  cout<<"new generation: "<<endl;
  cout<<endl;

  for(int i = 0;i<numRows;i++){
    for(int j = 0;j<numColumns;j++){
      cout<<nextGeneration[i][j];
    }
    cout<<endl;
  }
}






//pass actual board objext into the parameter

void GameMode::mirrorMode(int numRows, int numColumns, double density){
  char **arrGrid = Board::createMap(numRows, numColumns, density);

  char** nextGeneration;
  nextGeneration = new char*[numRows];
  for(int p = 0;p < numRows;++p){
    nextGeneration[p]= new char[numColumns];
  }

  //check for neighbors
  cout<<"MIRROR MODE "<<endl;
  int counter = 0;
  int genCount=0;
  while(true){
    cout<<"press enter to to produce another generation or control c to exit. "<<endl;
    cin.get();
  for(int i =0;i<numRows;++i){
    for(int j = 0;j<numColumns;++j){


        counter = 0;
        if(i!=0 && i!=(numRows-1) && j!= 0 && j!= (numColumns-1)){//middle squares
          if(arrGrid[i-1][j]=='X'){
            counter++;
            // cout<<"counting"<<endl;
                }
          if(arrGrid[i-1][j-1]=='X'){
            // cout<<"I AM COUNTING DOWN AND LEFT"<<endl;

            counter++;
            // cout<<"counter after entering: "<<counter<<endl;
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
          // if(arrGrid[i][j]=='X'){
          //   counter+=3;
          // }
          if(arrGrid[i][j+1]=='X'){ //to the right
            counter++;
          }
          if(arrGrid[i+1][j+1]=='X'){ //right diagonal
            counter++;
          }
          if(arrGrid[i+1][j]=='X'){ //below
            counter++;
          }
          if(arrGrid[numRows-1][numColumns-1]=='X'){
            counter++;
          }
          if(arrGrid[i][numColumns-1]=='X'){
            counter++;
          }
          if(arrGrid[i+1][numColumns-1]=='X'){
            counter++;
          }
          if(arrGrid[numRows-1][j]=='X'){
            counter++;
          }
          if(arrGrid[numRows-1][j+1]=='X'){
            counter++;
          }

        }

        else if(i==0 && j ==(numColumns-1)){ //top right corner
          if(arrGrid[i][j]=='X'){
            counter+=3;
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
            counter+=3;
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
            counter+=3;
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
        else if((i == 0) && (j != numColumns-1 && j != 0)){ //top row
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
        else if((i == numRows-1) && (j != numColumns-1 && j != 0)){ //bottom row
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
        else if((i != 0 && i != numRows-1) && (j == 0)){ // left column
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
        else if((i != 0 && i != numRows-1) && (j == numColumns-1)){ //far right column
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
        // cout<<"counter: "<<counter<<endl;

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


  cout<<"new generation "<<++genCount <<": "<<endl;
    for(int i = 0;i<numRows;++i){
      for(int j = 0;j<numColumns;++j){
        cout<<nextGeneration[i][j];
      }
      cout<<endl;
    }


    bool isEqual = true;
    for(int i = 0;i<numRows;++i){
      for(int j = 0;j<numColumns;++j){
        if(arrGrid[i][j]!=nextGeneration[i][j]){
          isEqual = false;
        }
      }
    }

    if(isEqual==true){
      cout<<"population stabalized. Press enter to break. "<<endl;
      cin.get();
      return;

    }
    // if(arrGrid)


    for(int i = 0;i<numRows;++i){
      for(int j = 0;j<numColumns;++j){
        arrGrid[i][j]=nextGeneration[i][j];
      }
    }


  }

      // cout<<"press enter to to produce another generation or control c to exit. "<<endl;
      // cin.get();



  //     counter = 0;
  //     if(i!=0 && i!=(numRows-1) && j!= 0 && j!= (numColumns-1)){//middle squares
  //       if(arrGrid[i-1][j]=='X'){
  //         counter++;
  //         // cout<<"counting"<<endl;
  //             }
  //       if(arrGrid[i-1][j-1]=='X'){
  //         // cout<<"I AM COUNTING DOWN AND LEFT"<<endl;
  //
  //         counter++;
  //         // cout<<"counter after entering: "<<counter<<endl;
  //             }
  //       if(arrGrid[i][j-1]=='X'){
  //         counter++;
  //       }
  //       if(arrGrid[i+1][j-1]=='X'){
  //         counter++;
  //       }
  //       if(arrGrid[i+1][j]=='X'){
  //         counter++;
  //       }
  //       if(arrGrid[i+1][j+1]=='X'){
  //         counter++;
  //       }
  //       if(arrGrid[i][j+1]=='X'){
  //         counter++;
  //       }
  //       if(arrGrid[i-1][j+1]=='X'){
  //         counter++;
  //       }
  //     }
  //
  //     else if(i==0 && j==0 ){//top left corner
  //       // if(arrGrid[i][j]=='X'){
  //       //   counter+=3;
  //       // }
  //       if(arrGrid[i][j+1]=='X'){ //to the right
  //         counter++;
  //       }
  //       if(arrGrid[i+1][j+1]=='X'){ //right diagonal
  //         counter++;
  //       }
  //       if(arrGrid[i+1][j]=='X'){ //below
  //         counter++;
  //       }
  //       if(arrGrid[numRows-1][numColumns-1]=='X'){
  //         counter++;
  //       }
  //       if(arrGrid[i][numColumns-1]=='X'){
  //         counter++;
  //       }
  //       if(arrGrid[i+1][numColumns-1]=='X'){
  //         counter++;
  //       }
  //       if(arrGrid[numRows-1][j]=='X'){
  //         counter++;
  //       }
  //       if(arrGrid[numRows-1][j+1]=='X'){
  //         counter++;
  //       }
  //
  //
  //
  //
  //
  //
  //
  //
  //
  //
  //
  //     }
  //
  //     else if(i==0 && j ==(numColumns-1)){ //top right corner
  //       if(arrGrid[i][j]=='X'){
  //         counter+=3;
  //       }
  //       if(arrGrid[i][j-1]=='X'){ //to the left
  //         counter++;
  //       }
  //       if(arrGrid[i+1][j-1]=='X'){ //left diagonal
  //         counter++;
  //       }
  //       if(arrGrid[i+1][j]=='X'){ //below
  //         counter++;
  //       }
  //     }
  //
  //     else if(i ==(numRows-1) && j ==0){//bottom left corner
  //       if(arrGrid[i][j]=='X'){
  //         counter+=3;
  //       }
  //       if(arrGrid[i-1][j]=='X'){ //above
  //         counter++;
  //       }
  //       if(arrGrid[i-1][j+1]=='X'){ //right diagonal
  //         counter++;
  //       }
  //       if(arrGrid[i][j+1]=='X'){ //to the right
  //         counter++;
  //       }
  //     }
  //
  //     else if(i ==(numRows-1)&& j ==(numColumns-1)){ //bottom right corner
  //       if(arrGrid[i][j]=='X'){
  //         counter+=3;
  //       }
  //       if(arrGrid[i-1][j]=='X'){ //above
  //         counter++;
  //       }
  //       if(arrGrid[i-1][j-1]=='X'){ //left diagonal
  //         counter++;
  //       }
  //       if(arrGrid[i][j-1]=='X'){ //to the left
  //         counter++;
  //       }
  //     }
  //     else if((i == 0) && (j != numColumns-1 && j != 0)){ //top row
  //       if(arrGrid[i][j]=='X'){
  //         counter++;
  //       }
  //       if(arrGrid[i][j-1]=='X'){ //to the left
  //         counter++;
  //       }
  //       if(arrGrid[i][j+1]=='X'){ //to the right
  //         counter++;
  //       }
  //       if(arrGrid[i+1][j-1]=='X'){ //left diagonal
  //         counter++;
  //       }
  //       if(arrGrid[i+1][j]=='X'){ //below
  //         counter++;
  //       }
  //       if(arrGrid[i+1][j+1]=='X'){ //right diagonal
  //         counter++;
  //       }
  //     }
  //     else if((i == numRows-1) && (j != numColumns-1 && j != 0)){ //bottom row
  //       if(arrGrid[i][j]=='X'){
  //         counter++;
  //       }
  //       if(arrGrid[i-1][j-1]=='X'){ //left diagonal
  //         counter++;
  //       }
  //       if(arrGrid[i-1][j]=='X'){ //above
  //         counter++;
  //       }
  //       if(arrGrid[i-1][j+1]=='X'){ //right diagonal
  //         counter++;
  //       }
  //       if(arrGrid[i][j-1]=='X'){ //to the left
  //         counter++;
  //       }
  //       if(arrGrid[i][j+1]=='X'){ //to the right
  //         counter++;
  //       }
  //     }
  //     else if((i != 0 && i != numRows-1) && (j == 0)){ // left column
  //       if(arrGrid[i][j]=='X'){
  //         counter++;
  //       }
  //       if(arrGrid[i-1][j]=='X'){ //above
  //         counter++;
  //       }
  //       if(arrGrid[i-1][j+1]=='X'){ //right above diagonal
  //         counter++;
  //       }
  //       if(arrGrid[i][j+1]=='X'){ //to the right
  //         counter++;
  //       }
  //       if(arrGrid[i+1][j+1]=='X'){ //right below diagonal
  //         counter++;
  //       }
  //       if(arrGrid[i+1][j]=='X'){ //below
  //         counter++;
  //       }
  //     }
  //     else if((i != 0 && i != numRows-1) && (j == numColumns-1)){ //far right column
  //       if(arrGrid[i][j]=='X'){
  //         counter++;
  //       }
  //       if(arrGrid[i-1][j]=='X'){ //above
  //         counter++;
  //       }
  //       if(arrGrid[i-1][j-1]=='X'){ //left above diagonal
  //         counter++;
  //       }
  //       if(arrGrid[i][j-1]=='X'){ //to the left
  //         counter++;
  //       }
  //       if(arrGrid[i+1][j-1]=='X'){ //left below diagonal
  //         counter++;
  //       }
  //       if(arrGrid[i+1][j]=='X'){ //below
  //         counter++;
  //       }
  //     }
  //
  //     //for checking
  //     // cout<<"counter: "<<counter<<endl;
  //
  //     //fill new generation based off counter
  //     if(counter <=1){
  //       nextGeneration[i][j]='-';
  //     }else if(counter == 2){
  //       nextGeneration[i][j]= arrGrid[i][j];
  //     }else if(counter ==3){
  //       nextGeneration[i][j]= 'X';
  //     }
  //     else{
  //       nextGeneration[i][j]= '-';
  //     }
  //   } //exit j for loop
  // } //exit i for loop
  //
  //
  // cout<<"new generation: "<<endl;
  // for(int i = 0;i<numRows;++i){
  //   for(int j = 0;j<numColumns;++j){
  //     cout<<nextGeneration[i][j];
  //   }
  //   cout<<endl;
  // }
  //
  //
  // bool isEqual = true;
  // for(int i = 0;i<numRows;++i){
  //   for(int j = 0;j<numColumns;++j){
  //     if(arrGrid[i][j]!=nextGeneration[i][j]){
  //       isEqual = false;
  //     }
  //   }
  // }
  //
  // if(isEqual==true){
  //   cout<<"population stabalized. Press enter to break. "<<endl;
  //   cin.get();
  //   return;
  //
  // }
  // // if(arrGrid)
  //
  //
  // for(int i = 0;i<numRows;++i){
  //   for(int j = 0;j<numColumns;++j){
  //     arrGrid[i][j]=nextGeneration[i][j];
  //   }
  // }





}

// int main(int argc, char const *argv[]) {
//   GameMode *g = new GameMode;
//   g->mirrorMode(5,5,.3);
//   return 0;
// }
