#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    sSlitDiffractor()

{
    image = new QImage(DR_WIDTH, DR_HEIGHT, QImage::Format_RGB32);
    image->fill(QColor(0,0,0));
    ui->setupUi(this);
    ui->labelImage->setPixmap(QPixmap::fromImage(*image));



}

void MainWindow::refresh() {

    QMessageBox m;
    Diffractor* diffractor;
    if(ui->radioStraightSlit->isChecked()){
       // m.information(0,"straight", "refresh");

        double width = ui->widthDoubleSpinBox->value();
        double height = ui->heightDoubleSpinBox->value();
        double zoom = ui->zoomSlider->value();


        int color = ui->colorDial->value();

        diffractor = &sSlitDiffractor;
        diffractor->setZoom(zoom);
        diffractor->setDimensions(width, height);
        diffractor->setColor(color);
        diffractor->run(*image);
        ui->labelImage->setPixmap(QPixmap::fromImage(*image));

    }
    else if(ui->radioCircularSlit->isChecked()){
        m.information(0,"circ", "refresh");
    }


}

MainWindow::~MainWindow()
{
    delete image;
    delete ui;
}
