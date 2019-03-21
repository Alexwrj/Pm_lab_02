#include "leastdiscr.h"

LeastDiscr::LeastDiscr(Matrix matrix, QVector<float> vector, float eps) : Method (matrix, vector, eps)
{
}

LeastDiscr::~LeastDiscr()
{
}

QPair<QVector<float>, int> LeastDiscr::calculateSolution()
{
    int count = 0;
    int size = vector.size();

    Vector x(size);
    Vector r = Vector(vector) - (matrix * x).transp(true);

    while (Vector::normEuclid(r) > eps)
    {
        Vector ar = Vector((matrix * r).transp(true));

        float tau = Vector::scalarMult(ar, r) / Vector::scalarMult(ar, ar);
        x += r * tau;
        r = Vector(vector) - (matrix * x).transp(true);
        count++;
    }

    return QPair<QVector<float>, int>(Vector::fromVector(x), count);
}
