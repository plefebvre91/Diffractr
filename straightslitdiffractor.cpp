#include "straightslitdiffractor.h"



void StraightSlitDiffractor::setDimensions(double c) {
    width = c;
    height = c;
}

void StraightSlitDiffractor::setDimensions(double w, double h) {
    width = w;
    height = h;
}

double sinc(double x) {
    if(x==0) return 1; else return sin(x)/x;
}
double sinc2(double x) {
    return sinc(x)*sinc(x);
}
double StraightSlitDiffractor::diffractionMethode(double x, double y) {
    double lambda = 900e-9;
    double PI = 3.1415709;

    return ( sinc2(PI*x*width/lambda)*sinc2(PI*y*height/lambda));

}

void StraightSlitDiffractor::run(QImage& image) {

    for(int i=-128;i<127;i++){
         for(int j=-128;j<127;j++){
             double dx = (double)i/zoom;
             double dy = (double)j/zoom;
    double PI = 3.1415709;
             int val =(int)((atan(diffractionMethode(dx,dy)*10e20) * 2 / PI)*254);

            color.setHsv(color.hsvHue(),  255,val);

            color.toRgb();

            image.setPixel(i+128,j+128,color.rgb());
         }

    }

    return;
}
