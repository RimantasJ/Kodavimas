#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "head.h"

using namespace std;
void hi(string name){

  cout << "Hello " << name << endl;
  
  return;
}

void printMatrix(int** M, int rows, int cols){

  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      cout << M[i][j] << " ";
    }
    cout << endl;
  }
}

void createGeneratingMatrix(int** G, int m){

  int rows = m+1;
  int cols = pow(2, m);
  int duplicate_j;


  if(m > 1){
    // quarter 1
    createGeneratingMatrix(G, m-1);
    
    // quarter 2
    for(int i = 0; i < m; i++){
      for(int j = 0; j < cols / 2; j++){
        duplicate_j = j + cols / 2;
        G[i][duplicate_j] = G[i][j];
      }
    }

    // quarter 3
    for(int i = 0; i < cols / 2; i++){
      G[m][i] = 0;
    }

    // quarter 4
    for(int i = cols / 2; i < cols; i++){
      G[m][i] = 1;
    }

  } else if(m = 1){
    G[0][0] = 1;
    G[0][1] = 1;
    G[1][0] = 0;
    G[1][1] = 1;
  } else{
    return;
  }

}