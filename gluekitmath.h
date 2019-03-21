#ifndef GLUEKITMATH_H
#define GLUEKITMATH_H

#include <QVector>

class Vector;

class Matrix
{
public:
    Matrix();
    Matrix(QVector<float>vect);
    Matrix(QVector<QVector<float>>matr);
    Matrix(int rows, int cols);

    void addRow(QVector<float>row, int index = -1);
    void addCol(QVector<float>col, int index = -1);
    void transp();
    Matrix transp(bool flag);
    void clear();
    void setMatrix(QVector<QVector<float>> newMatrix);

    int height() const;
    int width() const;

    Matrix operator+(Matrix otherMatrix);
    Matrix operator*(Matrix otherMatrix);
    Matrix operator*(QVector<float> vector);
    Matrix operator*(Vector vector);
    Matrix operator*(float value);
    bool operator==(Matrix otherMatrix);
    QVector<float> &operator[](int index);

    static QVector<QVector<float>> fromMatrix(Matrix otherMatrix);
    static float det(Matrix matr);
    static Matrix inverse(Matrix matr);

private:
    int rowNum;
    int colNum;

    void incrRowNum();
    void incrColNum();

    void makeSquared(Matrix &matr);
    void reduceInfVectors(Matrix &matr);
    static Matrix getAlgComp(Matrix matr);

    QVector<QVector<float>> matrix;
};

class GlueKitMath
{
public:
    GlueKitMath();
};

class Vector
{
public:
    Vector();
    Vector(int size);
    Vector(QVector<float> vector);
    Vector(Matrix matrix);
    static QVector<float> fromVector(const Vector &vector);
    static float normEuclid(Vector vec);
    static float normEuclid(Vector x, Vector y);
    static float scalarMult(Vector x, Vector y);
    int size() const;

    Vector operator+(Vector otherVector);
    void operator+=(Vector otherVector);
    Vector operator-(Vector otherVector);
    void operator-=(Vector otherVector);
    Vector operator*(const float &value);
    void operator*=(const float &value);
    Vector operator/(const float &value);
    void operator/=(const float &value);
    float &operator[](const int &index);
    void operator=(QVector<float> otherVector);

    float *begin();
    float *end();

private:
    QVector<float> vector;

};

#endif // GLUEKITMATH_H
