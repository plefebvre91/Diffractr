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
    double lambda = 900e-9;
    double PI = 3.1415709;
    double rho = hypot(x,y);
    double eta = PI*rho*diameter / lambda;

    return ( (j1(eta)/eta)*(j1(eta)/eta));

}

void CircularSlitDiffractor::run(QImage& image) {

    for(int i=-128;i<127;i++){
         for(int j=-128;j<127;j++){
             double dx = (double)i/zoom;
             double dy = (double)j/zoom;
                 double PI = 3.1415709;


             int val =(int)((atan(diffractionMethode(i,j)*10e14) * 2 / PI)*254);

            color.setHsv(color.hsvHue(),  255,val);

            color.toRgb();

            image.setPixel(i+128,j+128,color.rgb());
         }

    }

    return;
}
