#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <string>
#include "head.h"

// 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

using namespace std;
int main() {

  int m;
  string input_file_name;

  cout << "Value m: ";
  cin >> m;
  cout << "Input file name: ";
  cin >> input_file_name;

  encode(m, input_file_name);

  system("pause");
}