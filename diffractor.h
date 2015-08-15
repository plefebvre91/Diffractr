#ifndef DIFFRACTOR_H
#define DIFFRACTOR_H

#include <QImage>

class Diffractor
{
public:
    Diffractor();

    virtual void run(QImage& image) const = 0;
    virtual void setDimensions(double c) = 0;
    virtual void setDimensions(double w, double h) = 0;

    inline void setZoom(double z) {
        zoom = z;
    }

    inline void setColor(double c) {
        color = c;
    }

private:
    double zoom;
    double color;
};

#endif // DIFFRACTOR_H
