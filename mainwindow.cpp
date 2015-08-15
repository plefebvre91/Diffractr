#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    image = new QImage(DR_WIDTH, DR_HEIGHT, QImage::Format_RGB32);
    image->fill(QColor(255,255,255));
    ui->setupUi(this);
    ui->labelImage->setPixmap(QPixmap::fromImage(*image));


}

void MainWindow::refresh() {
    return;
}

MainWindow::~MainWindow()
{
    delete image;
    delete ui;
}
