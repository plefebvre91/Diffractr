#ifndef DIFFRACTOR_H
#define DIFFRACTOR_H

#include <QImage>
#include <QColor>
#include <cmath>

class Diffractor
{
public:

    Diffractor();
    virtual void run(QImage& image) = 0;
    virtual void setDimensions(double c) = 0;
    virtual void setDimensions(double w, double h) = 0;

    void setColor(int c);

    inline void setZoom(int z) {
        zoom = z;
    }

protected:
    double zoom;
    QColor color;
};

#endif // DIFFRACTOR_H
