#include "matrix.h"

using namespace Matrix;

int main()
{
    unsigned r = 5;
    unsigned c = 4;
    double i = 0.5;

    SimpleMatrix m(r, c, i);
    SimpleMatrix b(r, c, 0.2);

    SimpleMatrix x = m + b;
    x.print();
    return 0;
}