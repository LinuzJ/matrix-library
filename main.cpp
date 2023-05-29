#include "matrix.h"

using namespace Matrix;

int main()
{
    unsigned r = 3;
    unsigned c = 2;
    double i = 0.5;

    SimpleMatrix m(r, c, i);
    SimpleMatrix b(r, c, 0.2);

    SimpleMatrix x = m.transpose();
    x.print();
    return 0;
}