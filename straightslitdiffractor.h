#ifndef STRAIGHTSLITDIFFRACTOR_H
#define STRAIGHTSLITDIFFRACTOR_H

#include "diffractor.h"

/**
 * @brief The StraightSlitDiffractor class
 */
class StraightSlitDiffractor : public Diffractor
{
public:
    /**
     * @brief StraightSlitDiffractor
     */
    StraightSlitDiffractor(){}

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
    double width;
    double height;
};

#endif // STRAIGHTSLITDIFFRACTOR_H
