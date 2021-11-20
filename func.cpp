#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include "head.h"

using namespace std;

// multi dimentional matrix
void printMatrix(int** M, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << M[i][j] << " ";
    }
    cout << endl;
  }
}

// one dimentional matrix (vector)
void printMatrix(int* M, int cols) {
    for(int j = 0; j < cols; j++){
      cout << M[j] << " ";
    }
    cout << endl;
}

// Recurrent function
void generateGeneratingMatrix(int** G, int m) {
  int rows = m+1;
  int cols = pow(2, m);
  int duplicate_j;

  if (m > 1) {
    // quarter 1
    generateGeneratingMatrix(G, m-1);
    // quarter 2
    for(int i = 0; i < m; i++){
      for(int j = 0; j < cols / 2; j++) {
        duplicate_j = j + cols / 2;
        G[i][duplicate_j] = G[i][j];
      }
    }
    // quarter 3
    for(int i = 0; i < cols / 2; i++) {
      G[m][i] = 0;
    }
    // quarter 4
    for (int i = cols / 2; i < cols; i++) {
      G[m][i] = 1;
    }
  } else if(m = 1) {
    G[0][0] = 1;
    G[0][1] = 1;
    G[1][0] = 0;
    G[1][1] = 1;
  } else {
    return;
  }
}
int** createGeneratingMatrix(int m) {
  int rows = m+1;
  int cols = pow(2, m);
  int** G = new int*[rows];
  for(int i = 0; i < rows; i++){
    G[i] = new int[cols];
  }

  generateGeneratingMatrix(G, m);
  return G;
}

// if left matrix is two dimensional (one or more rows)
void mulMatrixes(int** A, int arows, int acols, int** B, int brows, int bcols, int** R) {
  if(acols != brows){
    cout << "matrix cannot be multiplied" << endl;
    return;
  }

  int cell_sum = 0;
  for(int i = 0; i < arows; i++){
    for(int j = 0; j < bcols; j++){
      for(int k = 0; k < brows; k++){
         cell_sum += A[i][k] * B[k][j];
      }
      R[i][j] = cell_sum;
      cell_sum = 0;
    }
  }
}

// if left matrix is one dimentional (one row)
void mulMatrixes(int* A, int acols, int** B, int brows, int bcols, int* R) {
  if(acols != brows){
    cout << "matrix cannot be multiplied" << endl;
    return;
  }

  int cell_sum = 0;
  for(int j = 0; j < bcols; j++){
    for(int k = 0; k < brows; k++){
        cell_sum += A[k] * B[k][j];
    }
    R[j] = cell_sum;
    cell_sum = 0;
  }
}

void encode(int m, string input_file_name) {

  int two_m = pow(2, m);
  
  int** G;

  // Creating the generating matrix
  G = createGeneratingMatrix(m);
  
  // getting input
  char char_buffer = 0;
  int* input_buffer = new int[m+1];
  string encoded_file_name;
  int* encoded_buffer = new int[two_m];
  int extra_bits = 0;
  string tmp;
  
  encoded_file_name = "encoded_" + input_file_name;

  FILE* input_file = fopen(input_file_name.c_str(), "r");
  if (input_file == nullptr) {
    return;
  }

  FILE* encoded_file = fopen(encoded_file_name.c_str(), "w");
  if (encoded_file == nullptr) {
    return;
  }

  // Loop encodes one segment at a time
  int eof_flag = 0;
  while (!eof_flag) {

    // Read
    char_buffer = getc(input_file);
    if (!feof(input_file)) {
      if (char_buffer == '1') {
        input_buffer[0] = 1;
      } else if (char_buffer == '0') {
        input_buffer[0] = 0;
      }
    } else {
      break;
    }

    for (int i = 1; i < m+1;) {
      if (!feof(input_file)) {
        char_buffer = getc(input_file);
        if (char_buffer == '1') {
          input_buffer[i] = 1;
          i++;
        } else if (char_buffer == '0') {
          input_buffer[i] = 0;
          i++;
        }
      } else {
        eof_flag = 1;
        input_buffer[i] = 0;
        i++;
        extra_bits++;
      }
    }
    
    // Encode segment
    mulMatrixes(input_buffer, m+1, G, m+1, two_m, encoded_buffer);

    // Write
    for (int  i = 0; i < two_m; i++) {
      tmp = to_string(encoded_buffer[i]);
      for (int j = 0; j < tmp.length(); j++) {
        putc(tmp[j], encoded_file);
      }
    }
  }

  fclose(input_file);
  fclose(encoded_file);

  delete input_buffer;
  delete encoded_buffer;

  for(int i = 0; i < m+1; i++){
    delete G[i];
  }
  delete[] G;
}

void createIdentityMatrix(int** I, int size) {
  I = new int*[size];
  for(int i = 0; i < size; i++){
    I[i] = new int[size];
  }
  
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < i; j++) {
      I[i][j] = 0;
      I[j][i] = 0;
    }
    I[i][i] = 1;
  }
}

// void kronecherMatrixesProduct(int** A, int arows, int acols, int** B, int brows, int bcols, int** R) {
//   for (int  i = 0; i < arows; i++) {
//     for (int j = 0; j < acols; j++) {

//     }
//   }
// }

// void decode(int m, string sent_file_name) {

// }



