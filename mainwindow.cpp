#include "mainwindow.h"
#include "equations.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    eqNum = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
}

int MainWindow::getEqNumber() const
{
    return eqNum;
}

float MainWindow::getEps() const
{
    return static_cast<float>(ui->doubleSpinBox->value());
}

void MainWindow::on_pushButton_clicked()
{
    eqNum = ui->spinBox->value();

    Equations *w = new Equations(this, nullptr);
    this->hide();
    w->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    close();
}
