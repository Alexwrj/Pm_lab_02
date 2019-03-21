#include "zeidel.h"

Zeidel::Zeidel(Matrix matrix, QVector<float> vector, float eps) : Method (matrix, vector, eps)
{
}

Zeidel::~Zeidel()
{
}

QPair<QVector<float>, int> Zeidel::calculateSolution()
{
    int rows = matrix.height() - 1;
    int count = 0;
    int size = vector.size();

    Vector x(size);

    while (Vector::normEuclid(Vector((matrix * x).transp(true)), Vector(vector)) > eps)
    {
        float sum = 0.f;
        for (int j = 1; j < rows + 1; j++)
        {
            sum += matrix[0][j] * x[j];
        }

        x[0] = (vector[0] - sum) / matrix[0][0];

        for (int i = 1; i < rows + 1; i++)
        {
            float lSum = 0.f;
            float rSum = 0.f;

            for (int j = 0; j < i; j++)
            {
                lSum += matrix[i][j] * x[j];
            }

            for (int j = i + 1; j < rows + 1; j++)
            {
                rSum += matrix[i][j] * x[j];
            }

            x[i] = (vector[i] - (lSum + rSum)) / matrix[i][i];
        }

        sum = 0.f;
        for (int j = 0; j < rows; j++)
        {
            sum += matrix[rows][j] * x[j];
        }

        x[rows] = (vector[rows] - sum) / matrix[rows][rows];
        count++;
    }

    return QPair<QVector<float>, int> (Vector::fromVector(x), count);
}
