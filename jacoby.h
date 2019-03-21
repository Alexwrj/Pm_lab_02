#ifndef JACOBY_H
#define JACOBY_H

#include "method.h"

class Jacoby : public Method
{
public:
    Jacoby(Matrix matrix, QVector<float> vector, float eps);
    virtual ~Jacoby() override;
    virtual QPair<QVector<float>, int> calculateSolution() override;
};

#endif // JACOBY_H
