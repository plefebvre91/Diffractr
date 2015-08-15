#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#define DR_WIDTH  256
#define DR_HEIGHT 256

#include <QMessageBox>
#include "diffractor.h"
#include "straightslitdiffractor.h"
#include "circularslitdiffractor.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void refresh();
    void setStraightSlitMode();
    void setCircularSlitMode();

private:
    Ui::MainWindow *ui;
    StraightSlitDiffractor sSlitDiffractor;
    CircularSlitDiffractor cSlitDiffractor;
    QImage* image;
};

#endif // MAINWINDOW_H
