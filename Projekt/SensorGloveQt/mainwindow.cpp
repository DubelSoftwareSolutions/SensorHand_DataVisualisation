#include "includes.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddWidgetToGlove3DLayout(QWidget *widget)
{
    widget->resize(600,400);
    ui->Glove3DLayout->addWidget(widget);

}
