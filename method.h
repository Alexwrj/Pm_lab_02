#ifndef METHOD_H
#define METHOD_H

#include "gluekitmath.h"
#include <QVector>
#include <QPair>

class Method
{
public:
    Method(Matrix matrix, QVector<float> vector, float eps);
    virtual ~Method();
    virtual QPair<QVector<float>, int> calculateSolution() = 0;

protected:
    Matrix matrix;
    QVector<float> vector;
    float eps;
};

#endif // METHOD_H
