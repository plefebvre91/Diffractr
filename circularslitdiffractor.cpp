#include "circularslitdiffractor.h"

CircularSlitDiffractor::CircularSlitDiffractor()
{
}



void CircularSlitDiffractor::setDimensions(double c) {
    diameter = c;
}

void CircularSlitDiffractor::setDimensions(double w, double h) {
    diameter = w;
}


double CircularSlitDiffractor::diffractionMethode(double x, double y) {
    double lambda = 400e-9;
    double PI = 3.1415709;
    double rho = hypot(x,y);
    double k = 2*PI/lambda;
    return 2*j1(k*diameter*(y/rho))/(k*diameter*(y/rho)) * j1(k*diameter*(y/rho))/(k*diameter*(y/rho));
}

void CircularSlitDiffractor::run(QImage& image) {

    for(int i=-128;i<127;i++){
         for(int j=-128;j<127;j++){
             double dx = (double)i/zoom;
             double dy = (double)j/zoom;
                 double PI = 3.1415709;


             unsigned int val =(int)((atan(diffractionMethode(dx,dy)*10e11) * 2 / PI)*254);

            color.setHsv(color.hsvHue(),  254,(val>255)?255:val);

            color.toRgb();

            image.setPixel(i+128,j+128,color.rgb());
         }

    }

    return;
}
