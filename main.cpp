#include <iostream>
using namespace std;

struct Element {
    int row;
    int col;
    int val;
};

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    int matrix[rows][cols];
    cout << "Enter matrix elements:\n";
    int count = 0;

    // Input matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] != 0)
                count++;
        }
    }

    // Sparse matrix representation
    Element sparse[count + 1];
    sparse[0].row = rows;
    sparse[0].col = cols;
    sparse[0].val = count;

    int k = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].val = matrix[i][j];
                k++;
            }
        }
    }

    // Print sparse matrix
    cout << "\nSparse Matrix Representation:\n";
    for (int i = 0; i <= count; i++) {
        cout << sparse[i].row << " " << sparse[i].col << " " << sparse[i].val << endl;
    }

    return 0;
}
