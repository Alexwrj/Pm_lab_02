#include "method.h"

Method::Method(Matrix matrix, QVector<float> vector, float eps)
{
    this->matrix = matrix;
    this->vector = vector;
    this->eps = eps;
}

Method::~Method()
{
}
