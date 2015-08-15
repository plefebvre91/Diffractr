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

     QObject::connect(ui->radioCircularSlit, SIGNAL(clicked()), this, SLOT(setCircularSlitMode()));
     QObject::connect(ui->radioStraightSlit, SIGNAL(clicked()), this, SLOT(setStraightSlitMode()));

}

void MainWindow::setCircularSlitMode(){
    ui->radioStraightSlit->setChecked(false);
    ui->diameterDoubleSpinBox->setReadOnly(false);
    ui->widthDoubleSpinBox->setReadOnly(true);
    ui->heightDoubleSpinBox->setReadOnly(true);

}

void MainWindow::setStraightSlitMode(){
    ui->radioCircularSlit->setChecked(false);
    ui->diameterDoubleSpinBox->setReadOnly(true);
    ui->widthDoubleSpinBox->setReadOnly(false);
    ui->heightDoubleSpinBox->setReadOnly(false);
}


void MainWindow::refresh() {

    QMessageBox m;
    Diffractor* diffractor = NULL;

    double width = ui->widthDoubleSpinBox->value();
    double height = ui->heightDoubleSpinBox->value();
    double diameter = ui->diameterDoubleSpinBox->value();
    double zoom = ui->zoomSlider->value();
    int color = ui->colorDial->value();

    if(ui->radioStraightSlit->isChecked()){
        diffractor = &sSlitDiffractor;
        diffractor->setDimensions(width, height);
    }
    else if(ui->radioCircularSlit->isChecked()){
        diffractor = &cSlitDiffractor;
        diffractor->setDimensions(diameter);
    }

    diffractor->setZoom(zoom);
    diffractor->setColor(color);
    diffractor->run(*image);
    ui->labelImage->setPixmap(QPixmap::fromImage(*image));

}

MainWindow::~MainWindow()
{
    delete image;
    delete ui;
}
