#include "equations.h"
#include "gluekitmath.h"
#include "ui_equations.h"
#include "mainwindow.h"
#include <QString>
#include <QLineEdit>
#include "jacoby.h"
#include "zeidel.h"
#include "leastdiscr.h"
#include "fastdescent.h"

Equations::Equations(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Equations)
{
    ui->setupUi(this);
    connect(ui->calculate, SIGNAL(clicked()), this, SLOT(on_calculate_clicked()));
}

Equations::Equations(MainWindow *parentWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Equations)
{
    ui->setupUi(this);
    connect(ui->calculate, SIGNAL(clicked()), this, SLOT(on_calculate_clicked()));

    this->parentWindow = parentWindow;
    this->eqNum = parentWindow->getEqNumber();
    this->eps = parentWindow->getEps();

    QVector<QHBoxLayout*> eq(eqNum);

    for (int i = 0; i < eqNum; i++)
    {
        eq[i] = new QHBoxLayout();

        for (int j = 0; j < eqNum; j++)
        {
            QLineEdit *pLineEdit = new QLineEdit();
            QLabel *pLabel;

            if (j != eqNum - 1)
            {
                pLabel = new QLabel("X" + QString::number(j + 1) + "+");
            }
            else
            {
                pLabel = new QLabel("X" + QString::number(j + 1) + "=");
            }

            eq[i]->addWidget(pLineEdit);
            eq[i]->addWidget(pLabel);

            m_lineMatrix.push_back(pLineEdit);
        }

        QLineEdit *pLineEdit = new QLineEdit();
        eq[i]->addWidget(pLineEdit);

        m_lineVector.push_back(pLineEdit);

        ui->eqBox->addLayout(eq[i]);
    }
}

Equations::~Equations()
{
    delete ui;
}

void Equations::on_calculate_clicked()
{ 
    Matrix m = Matrix(eqNum, eqNum);
    QVector<float> v(eqNum);

    for (int i = 0; i < eqNum; i++)
    {
        for (int j = 0; j < eqNum; j++)
        {
            m[i][j] = m_lineMatrix[i * eqNum + j]->text().toFloat();
        }

        v[i] = m_lineVector[i]->text().toFloat();
    }

    QPair<QVector<float>, int> solution;

    if (ui->radioButton->isChecked())
    {
        Jacoby *method = new Jacoby(m, v, eps);
        solution = method->calculateSolution();
        delete method;
    }
    else if (ui->radioButton_2->isChecked())
    {
        Zeidel *method = new Zeidel(m, v, eps);
        solution = method->calculateSolution();
        delete method;
    }
    else if (ui->radioButton_3->isChecked())
    {
        LeastDiscr *method = new LeastDiscr(m, v, eps);
        solution = method->calculateSolution();
        delete method;
    }
    else if (ui->radioButton_4->isChecked())
    {
        FastDescent *method = new FastDescent(m, v, eps);
        solution = method->calculateSolution();
        delete method;
    }

    QString str;

    for (int i = 0; i < eqNum; i++)
    {
        str += "X" + QString::number(i + 1) + "=" + QString::number(solution.first[i]);

        if (i != eqNum - 1)
        {
            str += ", ";
        }
        else
        {
            str += "\nЧисло итераций: " + QString::number(solution.second);
        }
    }

    ui->solution_label->setText(str);
}

void Equations::on_backButton_clicked()
{
    parentWindow->show();
    this->close();
}
