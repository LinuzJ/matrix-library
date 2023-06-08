#ifndef SIMPLE_MATRIX_H
#define SIMPLE_MATRIX_H
// ----------------------------------
#include <vector>
#include <ctime>
#include <iostream>
// ----------------------------------
using std::vector;
// ----------------------------------

namespace Matrix
{
    class SimpleMatrix
    {
    private:
        unsigned row_amount;
        unsigned col_amount;
        vector<vector<double>> m;

    public:
        // Constructors
        SimpleMatrix(unsigned, unsigned, double);
        SimpleMatrix(vector<vector<double>>);

        // Scalar operations
        // ----------------------------------
        // Addition
        SimpleMatrix *add(SimpleMatrix x);
        SimpleMatrix *operator+(SimpleMatrix x);

        // Subtract
        SimpleMatrix *subtract(SimpleMatrix x);
        SimpleMatrix *operator-(SimpleMatrix x);

        // Multiplication
        SimpleMatrix *multiply(double x);
        SimpleMatrix *operator*(double x);
        // ----------------------------------

        // More operations
        // ----------------------------------
        SimpleMatrix *multiply(SimpleMatrix other);
        SimpleMatrix *transpose();
        SimpleMatrix *inverse();
        // ----------------------------------

        // Helpers
        // ----------------------------------
        vector<double> getCol(unsigned c);
        vector<double> getRow(unsigned r);
        // ----------------------------------

        // Visual
        // ----------------------------------
        void print();
        // ----------------------------------
    };
}

#endif