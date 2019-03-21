#ifndef LEASTDISCR_H
#define LEASTDISCR_H

#include "method.h"

class LeastDiscr : Method
{
public:
    LeastDiscr(Matrix matrix, QVector<float> vector, float eps);

    virtual ~LeastDiscr() override;
    virtual QPair<QVector<float>, int> calculateSolution() override;
};

#endif // LEASTDISCR_H
