#ifndef SIMPLE_MATRIX_H
#define SIMPLE_MATRIX_H
// ----------------------------------
#include <vector>
// ----------------------------------
using std::vector;
// ----------------------------------

namespace Matrix
{
    class SimpleMatrix
    {
    private:
        unsigned row_size;
        unsigned col_size;
        vector<vector<double> > m;

    public:
        // Constructors
        SimpleMatrix(unsigned, unsigned, double);
        SimpleMatrix(vector<vector<double> >);

        // Scalar operations
        // ----------------------------------

        // Addition
        SimpleMatrix add(SimpleMatrix x);
        SimpleMatrix operator+(SimpleMatrix x);

        // Subtract
        SimpleMatrix subtract(SimpleMatrix x);
        SimpleMatrix operator-(SimpleMatrix x);

        // Multiplication
        SimpleMatrix multiply(double x);
        SimpleMatrix operator*(double x);

        // ----------------------------------


        // More operations
        // ----------------------------------

        SimpleMatrix transpose();

        // ----------------------------------

        // Helpers
        // ----------------------------------
        vector<double> getCol(unsigned x);
        // ----------------------------------
       
        // Visual
        // ----------------------------------
        void print();
        // ----------------------------------
    };
}

#endif