#include "matrix.h"

using namespace Matrix;

int main()
{
    unsigned r = 5;
    unsigned c = 4;
    double i = 0.5;

    SimpleMatrix m(r, c, i);
    m.print();
    return 0;
}