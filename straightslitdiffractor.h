#ifndef STRAIGHTSLITDIFFRACTOR_H
#define STRAIGHTSLITDIFFRACTOR_H

#include "diffractor.h"

class StraightSlitDiffractor : public Diffractor
{
public:
    StraightSlitDiffractor(){}
    virtual void run(QImage& image) ;
    virtual void setDimensions(double c);
    virtual void setDimensions(double w, double h);

private:
    double diffractionMethode(double x, double y);


    double width;
    double height;
};

#endif // STRAIGHTSLITDIFFRACTOR_H
