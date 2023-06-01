#include "matrix/matrix.h"

using namespace Matrix;

int main()
{
    unsigned r = 3;
    unsigned c = 2;
    double i = 0.5;

    SimpleMatrix m(r, c, i);
    SimpleMatrix b(c, r, 0.2);

    SimpleMatrix *x = m.multiply(b);
    SimpleMatrix final = *x;
    final.print();
    return 0;
}