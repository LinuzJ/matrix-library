#include "matrix.h"
#include <iostream>
// ----------------------------------
using namespace Matrix;
using namespace std;
// ----------------------------------

SimpleMatrix::SimpleMatrix(unsigned rows, unsigned cols, double init_value)
{
    this->row_size = rows;
    this->col_size = cols;
    this->m.resize(cols);

    for (int i = 0; i < cols; i++)
    {
        this->m[i].resize(rows, init_value);
    }
};

void SimpleMatrix::print()
{
    cout << "[\n";
    for (int i = 0; i < this->col_size; i++)
    {
        for (int j = 0; j < this->row_size; j++)
        {
            cout << this->m[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "]\n";
}