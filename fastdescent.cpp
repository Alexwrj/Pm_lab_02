#include "fastdescent.h"

FastDescent::FastDescent(Matrix matrix, QVector<float> vector, float eps) : Method(matrix, vector, eps)
{
}

FastDescent::~FastDescent()
{
}

QPair<QVector<float>, int> FastDescent::calculateSolution()
{
    int count = 0;
    int size = vector.size();

    Vector x(size);
    Vector r = Vector(vector) - (matrix * x).transp(true);

    while (Vector::normEuclid(r) > eps)
    {
        float tau = Vector::scalarMult(r, r) / Vector::scalarMult(Vector((matrix * r).transp(true)), r);
        x += r * tau;
        r = Vector(vector) - (matrix * x).transp(true);
        count++;
    }

    return QPair<QVector<float>, int>(Vector::fromVector(x), count);
}
