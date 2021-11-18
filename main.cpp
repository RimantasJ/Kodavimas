#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "head.h"

// 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

using namespace std;
int main() {

/*
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
*/


  /*
  int arows = 2;
  int acols = 3;
  int** A = new int*[arows];
  for(int i = 0; i < arows; i++){
    A[i] = new int[acols];
  }
  int brows = 3;
  int bcols = 3;
  int** B = new int*[brows];
  for(int i = 0; i < brows; i++){
    B[i] = new int[bcols];
  }
  int** R = new int*[arows];
  for(int i = 0; i < arows; i++){
    R[i] = new int[bcols];
  }

  A[0][0] = 1; A[0][1] = 4; A[0][2] = 3;
  A[1][0] = 2; A[1][1] = 2; A[1][2] = 5;

  B[0][0] = 5; B[0][1] = 1; B[0][2] = 2;
  B[1][0] = 3; B[1][1] = 4; B[1][2] = 4;
  B[2][0] = 1; B[2][1] = 2; B[2][2] = 2;

  mulMatrixes(A, arows, acols, B, brows, bcols, R);

  printMatrix(A, arows, acols);
  printMatrix(B, brows, bcols);
  printMatrix(R, arows, bcols);

  // Freeing memory
  for(int i = 0; i < arows; i++){
    delete A[i];
    delete R[i];
  }
  delete[] A;
  delete[] R;

  for(int i = 0; i < brows; i++){
    delete B[i];
  }
  delete[] B;
  */

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