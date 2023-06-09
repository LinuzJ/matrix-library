#include "matrix.h"
// ----------------------------------
using namespace Matrix;
// ----------------------------------

SimpleMatrix::SimpleMatrix(unsigned rows, unsigned cols, double init_value)
{
    this->row_amount = rows;
    this->col_amount = cols;
    this->m.resize(cols);

    for (int i = 0; i < cols; i++)
    {
        this->m[i].resize(rows, init_value);
    }
};

SimpleMatrix::SimpleMatrix(vector<vector<double>> input)
{
    this->col_amount = input.size();

    if (this->col_amount > 0)
    {
        this->row_amount = input[0].size();
    }

    this->m = input;
};

// ----------------------------------

SimpleMatrix *SimpleMatrix::add(SimpleMatrix x)
{
    vector<vector<double>> new_m = this->m;

    // Make sure dimensions match
    if (this->col_amount != x.col_amount || this->row_amount != x.row_amount)
    {
        return NULL;
    }

    vector<double> current_col;
    for (int i = 0; i < this->col_amount; i++)
    {
        current_col = x.getCol(i);
        for (int j = 0; j < this->row_amount; j++)
        {
            new_m[i][j] = this->m[i][j] + current_col[j];
        }
    }

    return new SimpleMatrix(new_m);
}

SimpleMatrix *SimpleMatrix::operator+(SimpleMatrix x)
{
    return this->add(x);
}

SimpleMatrix *SimpleMatrix::subtract(SimpleMatrix x)
{
    vector<vector<double>> new_m = this->m;

    // Make sure dimensions match
    if (this->col_amount != x.col_amount || this->row_amount != x.row_amount)
    {
        return NULL;
    }

    vector<double> current_col;
    for (int i = 0; i < this->col_amount; i++)
    {
        current_col = this->getCol(i);
        for (int j = 0; j < this->row_amount; j++)
        {
            new_m[i][j] = this->m[i][j] - current_col[j];
        }
    }
    return new SimpleMatrix(new_m);
}

SimpleMatrix *SimpleMatrix::operator-(SimpleMatrix x)
{
    return this->subtract(x);
}

SimpleMatrix *SimpleMatrix::multiply(double x)
{
    vector<vector<double>> new_m = this->m;

    for (int i = 0; i < this->col_amount; i++)
    {
        for (int j = 0; j < this->row_amount; j++)
        {
            new_m[i][j] = this->m[i][j] * x;
        }
    }
    return new SimpleMatrix(new_m);
}

SimpleMatrix *SimpleMatrix::operator*(double x)
{
    return this->multiply(x);
}

// ----------------------------------

// Operations
// ----------------------------------

SimpleMatrix *SimpleMatrix::transpose()
{
    vector<vector<double>> new_m;
    new_m.resize(this->row_amount);

    for (int i = 0; i < this->row_amount; i++)
    {
        new_m[i].resize(this->col_amount);
    }

    for (int i = 0; i < this->row_amount; i++)
    {
        for (int j = 0; j < this->col_amount; j++)
        {
            new_m[i][j] = this->m[j][i];
        }
    }
    unsigned temp_copy = this->col_amount;
    this->col_amount = this->row_amount;
    this->row_amount = temp_copy;

    return new SimpleMatrix(new_m);
}

SimpleMatrix *SimpleMatrix::multiply(SimpleMatrix other)
{
    if (this->row_amount != other.col_amount)
    {
        // TODO: fix error
        return NULL;
    }

    // Init new correctly sized matrix
    vector<vector<double>> new_m;
    new_m.resize(this->row_amount);
    for (int i = 0; i < this->row_amount; i++)
    {
        new_m[i].resize(this->row_amount);
    }
#pragma omp for parallel
    for (int i = 0; i < other.col_amount; i++)
    {
        for (int j = 0; j < this->row_amount; j++)
        {
            for (int n = 0; n < this->col_amount; n++)
            {
                new_m[i][j] += this->m[n][j] * other.m[i][n];
            }
        }
    }

    return new SimpleMatrix(new_m);
}
// ----------------------------------

// Helpers
// ----------------------------------

vector<double> SimpleMatrix::getCol(unsigned c)
{
    return this->m[c];
}

vector<double> SimpleMatrix::getRow(unsigned r)
{
    vector<double> row(this->col_amount, 0);

    for (int c = 0; c < this->col_amount; c++)
    {
        row[c] = this->m[c][r];
    }

    return row;
}

// ----------------------------------

// Visual
// ----------------------------------

void SimpleMatrix::print()
{
    std::cout << "[\n";
    for (int i = 0; i < this->row_amount; i++)
    {
        for (int j = 0; j < this->col_amount; j++)
        {
            std::cout << this->m[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "]\n";
}