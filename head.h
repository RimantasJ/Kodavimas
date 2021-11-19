#ifndef HEADER_GUARD
#define HEADER_GUARD
#endif

using namespace std;

void printMatrix(int** M, int rows, int cols);
void printMatrix(int* M, int cols);

void createGeneratingMatrix(int** G, int m);

void mulMatrixes(int** A, int arows, int acols, int** B, int brows, int bcols, int** R);
void mulMatrixes(int* A, int acols, int** B, int brows, int bcols, int* R);

void encode(int m, string input_file_name);