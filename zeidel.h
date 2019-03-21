#ifndef ZEIDEL_H
#define ZEIDEL_H

#include "method.h"

class Zeidel : public Method
{
public:

    Zeidel(Matrix matrix, QVector<float> vector, float eps);

    virtual ~Zeidel() override;
    virtual QPair<QVector<float>, int> calculateSolution() override;
};

#endif // ZEIDEL_H
