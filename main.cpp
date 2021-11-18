#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "head.h"

using namespace std;
int main() {

  int m = 3;


  // Allocating memory for generating matrix
  int rows = m+1;
  int cols = pow(2, m);
  int** G = new int*[rows];
  for(int i = 0; i < rows; i++){
    G[i] = new int[cols];
  }
  
  createGeneratingMatrix(G, m);


  printMatrix(G, m+1, pow(2, m));


  // Freeing memory of generating matrix
  for(int i = 0; i < m+1; i++){
    delete G[i];
  }
  delete[] G;

/*
  int** G;

  G = (int**)malloc((m+1) * sizeof(int*));

  for(int i = 0; i < m+1; i++){
    G[i] = (int(*))malloc(pow(2, m)*sizeof(int));
  }

  for(int i = 0; i < m+1; i++){
    for(int j = 0; j < pow(2, m); j++){
      G[i][j] = i + j*10;
    }
  }

  for(int i = 0; i < m+1; i++){
    for(int j = 0; j < pow(2, m); j++){
      cout << G[i][j] << " ";
    }
    cout << endl;
  }

  for(int i = 0; i < m+1; i++){
    free(G[i]);
  }
  free(G);

*/



  system("pause");

  
  // int* val1;
  // val1 = (int*)malloc(4 * sizeof(int));

  // int ind = 6;

  // for (int i = 0; i < ind; i++) {
  //   val1[i] = i;
  // }

  // for (int i = 0; i < ind; i++) {
  //   cout << &val1[i] << val1[i] << endl;
  // }
  

  // int* val2;
  // val2 = (int*)malloc(5);

  // cout << val1 << endl;
  // cout << val2 << endl;
  // cout << sizeof(int) << endl;

  // free(val1);
  // free(val2);


  // string name;
  // cin >> name;
  // hi(name);
}