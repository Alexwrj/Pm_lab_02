#include "jacoby.h"



Jacoby::Jacoby(Matrix matrix, QVector<float> vector, float eps) : Method(matrix, vector, eps)
{
}

Jacoby::~Jacoby()
{
}

QPair<QVector<float>, int> Jacoby::calculateSolution()
{
    int rows = matrix.height() - 1;
    int count = 0;
    int size = vector.size();

    Vector x(size);

    while (Vector::normEuclid(Vector((matrix * x).transp(true)) - Vector(vector)) > eps)
    {
        Vector y(size);

        float sum = 0.f;
        for (int i = 1; i < rows + 1; i++)
        {
            sum += matrix[0][i] * x[i];
        }

        y[0] = (vector[0] - sum) / matrix[0][0];

        for (int i = 1; i < rows; i++)
        {
            float lSum = 0.f;
            for (int j = 0; j < i; j++)
            {
                lSum += matrix[i][j] * x[j];
            }

            float rSum = 0.f;
            for (int j = i + 1; j < rows + 1; j++)
            {
                rSum += matrix[i][j] * x[j];
            }

            y[i] = (vector[i] - (lSum + rSum)) / matrix[i][i];
        }

        sum = 0.f;
        for (int i = 0; i < rows; i++)
        {
            sum += matrix[rows][i] * x[i];
        }

        y[rows] = (vector[rows] - sum) / matrix[rows][rows];

        x = y;
        count++;
    }

    return QPair<QVector<float>, int>(Vector::fromVector(x), count);
}
