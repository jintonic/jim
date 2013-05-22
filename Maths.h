#ifndef MATH_H
#define MATH_H

namespace CUM {
   /**
    * Step function followed by exponential decay.
    *   - @par parameter[0]: normalization factor
    *   - @par parameter[1]: decay constant
    *   - @par parameter[2]: offset
    */
   double SimpleFall(double *x, double *parameter);
   double SimpleRise(double *x, double *parameter);
   double SmearedRise(double *x, double *parameter);
   /**
    * Smeared step function followed by exponential decay.
    *   - @par parameter[0]: normalization factor
    *   - @par parameter[1]: decay constant
    *   - @par parameter[2]: offset
    *   - @par parameter[3]: sigma of Gaussian for smearing
    */
   double SmearedFall(double *x, double *parameter);
   double SmearedDoubleFall(double *x, double *parameter);
   double SmearedTripleFall(double *x, double *parameter);   

   /**
    * Exponential rise followed by exponential decay.
    *   - @par parameter[0]: normalization factor
    *   - @par parameter[1]: decay constant
    *   - @par parameter[2]: rise constant
    *   - @par parameter[3]: offset
    */
   double SimpleRiseAndFall(double *x, double *parameter);
   /**
    * Smeared exponential rise followed by exponential decay.
    *   - @par parameter[0]: normalization factor
    *   - @par parameter[1]: decay constant
    *   - @par parameter[2]: rise constant
    *   - @par parameter[3]: offset
    *   - @par parameter[4]: sigma of Gaussian for smearing
    */
   double SmearedRiseAndFall(double *x, double *parameter);
   double SmearedRiseAndDoubleFall(double *x, double *parameter);
   /**
    * Continuous Poisson PDF.
    * thisPDF->Integral(-scalingFactor,ABigNumber) = 1
    *   - @par parameter[0]: normalization factor
    *   - @par parameter[1]: histogram bin width
    *   - @par parameter[2]: mu (mean of Poisson)
    *   - @par parameter[3]: scaling factor
    */
   double ContinuousPoisson(double *x, double *parameter);

   /**
    * Convert x, y, z to latitude and longitude.
    */
   void Cartesian2Geographic(double x, double y, double z, 
         double *latitude, double *longitude);
   /**
    * Convert latitude and longitude to Mollweide x, y.
    */
   void Geographic2Mollweide(double *x, double *y);

   /**
    * Convert Geographic to Azimuthal Equidistant coordinates.
    */
   void Geographic2AzimuthalEquidistant(
         double latitude, double longitude, double *x, double *y);
};

#endif //MATH_H
