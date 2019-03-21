#ifndef EQUATIONS_H
#define EQUATIONS_H

#include <QWidget>
#include <QVector>

class MainWindow;
class QLineEdit;

namespace Ui {
class Equations;
}

class Equations : public QWidget
{
    Q_OBJECT

public:
    explicit Equations(QWidget *parent = nullptr);
    Equations(MainWindow *parentWindow, QWidget *parent = nullptr);
    ~Equations();

private slots:
    void on_calculate_clicked();
    void on_backButton_clicked();

private:
    Ui::Equations *ui;
    int eqNum;
    float eps;
    MainWindow *parentWindow;
    QVector<QLineEdit*> m_lineMatrix;
    QVector<QLineEdit*> m_lineVector;
};

#endif // EQUATIONS_H
