#include "matrix/matrix.h"

using namespace Matrix;

int main()
{
    unsigned time = clock();
    unsigned r = 3000;
    unsigned c = 2000;
    double i = 0.5;

    SimpleMatrix m(r, c, i);
    SimpleMatrix b(c, r, 0.2);

    SimpleMatrix *x = m.multiply(b);
    SimpleMatrix final = *x;

    time = clock() - time;

    std::cout << "Matrix multiplication finished in: " << (float)time / CLOCKS_PER_SEC << " seconds.";

    return 0;
}