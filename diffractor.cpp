#include "diffractor.h"

Diffractor::Diffractor():color(){}

void Diffractor::setColor(int c){
    color.setHsv(c, 255, 255);
    color = color.toRgb();
}
