#ifndef FASTDESCENT_H
#define FASTDESCENT_H

#include "method.h"

class FastDescent : public Method
{
public:
    FastDescent(Matrix matrix, QVector<float> vector, float eps);

    virtual ~FastDescent() override;
    virtual QPair<QVector<float>, int> calculateSolution() override;
};

#endif // FASTDESCENT_H
