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

SimpleMatrix::SimpleMatrix(vector<vector<double>> input)
{
    this->col_size = input.size();

    if (this->col_size > 0)
    {
        this->row_size = input[0].size();
    }

    this->m = input;
};

// ----------------------------------

SimpleMatrix SimpleMatrix::add(SimpleMatrix x)
{
    vector<vector<double>> tempM = this->m;

    // Make sure dimensions match
    if (this->col_size != x.col_size || this->row_size != x.row_size)
    {
        return this->m;
    }

    vector<double> currentCol;
    for (int i = 0; i < this->col_size; i++)
    {
        currentCol = x.getCol(i);
        for (int j = 0; j < this->row_size; j++)
        {
            tempM[i][j] = this->m[i][j] + currentCol[j];
        }
    }

    SimpleMatrix returnM(tempM);
    return returnM;
}

SimpleMatrix SimpleMatrix::operator+(SimpleMatrix x)
{
    SimpleMatrix returnM = this->add(x);
    return returnM;
}

SimpleMatrix SimpleMatrix::subtract(SimpleMatrix x)
{
    vector<vector<double>> newM = this->m;

    // Make sure dimensions match
    if (this->col_size != x.col_size || this->row_size != x.row_size)
    {
        return this->m;
    }

    vector<double> currentCol;
    for (int i = 0; i < this->col_size; i++)
    {
        currentCol = this->getCol(i);
        for (int j = 0; j < this->row_size; j++)
        {
            newM[i][j] = this->m[i][j] - currentCol[j];
        }
    }
    return SimpleMatrix(newM);
}

SimpleMatrix SimpleMatrix::operator-(SimpleMatrix x)
{
    return this->subtract(x);
}

SimpleMatrix SimpleMatrix::multiply(double x)
{
    vector<vector<double>> new_m = this->m;

    for (int i = 0; i < this->col_size; i++)
    {
        for (int j = 0; j < this->row_size; j++)
        {
            new_m[i][j] = this->m[i][j] * x;
        }
    }
    return SimpleMatrix(new_m);
}

SimpleMatrix SimpleMatrix::operator*(double x)
{
    return this->multiply(x);
}

// ----------------------------------

// Operations
// ----------------------------------

SimpleMatrix SimpleMatrix::transpose()
{
    vector<vector<double>> new_m;
    new_m.resize(this->row_size);

    for (int i = 0; i < this->row_size; i++)
    {
        new_m[i].resize(this->col_size);
    }

    for (int i = 0; i < this->row_size; i++)
    {
        for (int j = 0; j < this->col_size; j++)
        {
            new_m[i][j] = this->m[j][i];
        }
    }
    unsigned temp_copy = this->col_size;
    this->col_size = this->row_size;
    this->row_size = temp_copy;

    return SimpleMatrix(new_m);
}

// ----------------------------------

// Helpers
// ----------------------------------

vector<double> SimpleMatrix::getCol(unsigned x)
{
    return this->m[x];
}

// ----------------------------------

// Visual
// ----------------------------------

void SimpleMatrix::print()
{
    cout << "[\n";
    for (int i = 0; i < this->row_size; i++)
    {
        for (int j = 0; j < this->col_size; j++)
        {
            cout << this->m[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "]\n";
}