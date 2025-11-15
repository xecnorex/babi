#include <iostream>
#include <vector>

using namespace std;
using Matrix = vector<vector<double>>;

void minor(double matrix[2][2]);
void cofactor(double matrix[2][2]);
void adjoint(double matrix[2][2]);
int determinant(double matrix[2][2]);

int main() {
  double a[2][2];

  cout << "Enter the elements of the 2x2 matrix:\n";
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      cout << a[i][j] << "\t";
    }
    cout << "\n";
  }

  double b[2][2];
  double det;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      b[i][j] = a[i][j];
    }
  }

  minor(a);
  cofactor(a);
  adjoint(a);
  det = determinant(b);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      a[i][j] = a[i][j] / det;
    }
  }

  cout << a[0][0] << "\t" << a[0][1] << "\n" << a[1][0] << "\t" << a[1][1] << "\n\n";

  return 0;
}

void minor(double matrix[2][2]) {
  swap(matrix[0][0], matrix[1][1]);
  swap(matrix[0][1], matrix[1][0]);
}

void cofactor(double matrix[2][2]) {
  matrix[0][1] = -matrix[0][1];
  matrix[1][0] = -matrix[1][0];
}

void adjoint(double matrix[2][2]) {
  double temp[2][2];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      temp[j][i] = matrix[i][j];
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      swap(matrix[i][j], temp[i][j]);
    }
  }
}

int determinant(double matrix[2][2]) {
  return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
}