#ifndef CIRCULARSLITDIFFRACTOR_H
#define CIRCULARSLITDIFFRACTOR_H

#include "diffractor.h"

/**
 * @brief The CircularSlitDiffractor class
 */
class CircularSlitDiffractor : public Diffractor
{
public:
    /**
     * @brief StraightSlitDiffractor
     */
    CircularSlitDiffractor();


    /**
     * @brief run Create the diffraction trace
     * @param image rendering image
     */
    virtual void run(QImage& image);


    /**
     * @brief setDimensions Slit dimensions
     * @param c Value for height and width
     */
    virtual void setDimensions(double c);

    /**
     * @brief setDimensions Slit dimensions
     * @param w Width
     * @param h Height
     */
    virtual void setDimensions(double w, double h);


private:
    double diffractionMethode(double x, double y);
    double diameter;
};

#endif // CIRCULARSLITDIFFRACTOR_H

