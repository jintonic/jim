#include "Maths.h"
#include "Constants.h"

#include <cmath>
#include <iostream>
using namespace std;

//______________________________________________________________________________
//

double CUM::SimpleFall(double *x, double *parameter)
{
   double t = x[0];
   double nevts   = parameter[0];
   double tfall   = parameter[1];
   double toffset = parameter[2];

   if (t<toffset) return 0;

   return nevts/tfall * exp(-(t-toffset)/tfall);
}

//______________________________________________________________________________
//

double CUM::SmearedFall(double *x, double *parameter)
{
   double t = x[0];
   double nevts   = parameter[0];
   double tfall   = parameter[1];
   double toffset = parameter[2];
   double sigma   = parameter[3];

   if (t<toffset-10*sigma) return 0;

   return nevts/2./tfall * exp(sigma*sigma/2./tfall/tfall-(t-toffset)/tfall) * 
      erfc(sigma/sqrt(2.)/tfall-(t-toffset)/sqrt(2.)/sigma);
}

//______________________________________________________________________________
//

double CUM::SmearedDoubleFall(double *x, double *parameter)
{
   double t = x[0];
   double nevts   = parameter[0];
   double tfall   = parameter[1];
   double toffset = parameter[2];
   double sigma   = parameter[3];
   double tfall2  = parameter[4];   
   double weight  = parameter[5];      

   if (t<toffset-10*sigma) return 0;   
   return weight* nevts/2./tfall *
      exp(sigma*sigma/2./tfall/tfall-(t-toffset)/tfall) *
      erfc(sigma/sqrt(2.)/tfall-(t-toffset)/sqrt(2.)/sigma) +
      (1-weight)*nevts/2./tfall2 *
      exp(sigma*sigma/2./tfall2/tfall2-(t-toffset)/tfall2) *
      erfc(sigma/sqrt(2.)/tfall2-(t-toffset)/sqrt(2.)/sigma);
}

//______________________________________________________________________________
//

double CUM::SmearedTripleFall(double *x, double *parameter)
{
   double t = x[0];
   double nevts   = parameter[0];
   double tfall   = parameter[1];
   double toffset = parameter[2];
   double sigma   = parameter[3];
   double tfall2  = parameter[4];   
   double weight  = parameter[5];      
   double tfall3  = parameter[6];   
   double weight2 = parameter[7];      

   if (t<toffset-10*sigma) return 0;

   return weight*nevts/2./tfall *
      exp(sigma*sigma/2./tfall/tfall-(t-toffset)/tfall) *
      erfc(sigma/sqrt(2.)/tfall-(t-toffset)/sqrt(2.)/sigma) +
      (1-weight-weight2)*nevts/2./tfall2 *
      exp(sigma*sigma/2./tfall2/tfall2-(t-toffset)/tfall2) * 
      erfc(sigma/sqrt(2.)/tfall2-(t-toffset)/sqrt(2.)/sigma) +
      (weight2)*nevts/2./tfall3 *
      exp(sigma*sigma/2./tfall3/tfall3-(t-toffset)/tfall3) *
      erfc(sigma/sqrt(2.)/tfall3-(t-toffset)/sqrt(2.)/sigma);
}

//______________________________________________________________________________
//

double CUM::SimpleRise(double *x, double *parameter)
{
   double t = x[0];
   double nevts   = parameter[0];
   double trise   = parameter[1];
   double toffset = parameter[2];

   if (t<toffset) return 0;

   return nevts/trise * (1-exp(-(t-toffset)/trise));
}

//______________________________________________________________________________
//

double CUM::SmearedRise(double *x, double *parameter)
{
   double t = x[0];
   double nevts   = parameter[0];
   double trise   = parameter[1];
   double toffset = parameter[2];
   double sigma   = parameter[3];

   if (t<toffset) return 0;

   return nevts*(1 + erf((t - toffset)/(sqrt(2.)*sigma)) - 
         exp((pow(sigma,2.)-2.*t*trise+2.*toffset*trise)/(2.*pow(trise,2.)))*
         erfc((pow(sigma,2.)-t*trise+toffset*trise)/(sqrt(2.)*sigma*trise)))/2.;
}

//______________________________________________________________________________
//

double CUM::SimpleRiseAndFall(double *x, double *parameter)
{
   double t = x[0];
   double nevts = parameter[0];
   double tfall = parameter[1];
   double trise = parameter[2];
   double toffset = parameter[3];

   if (t<toffset) return 0;
   if (tfall<trise) return 0;

   return nevts/(tfall-trise) 
      * (exp(-(t-toffset)/tfall) - exp(-(t-toffset)/trise));
}

//______________________________________________________________________________
//

double CUM::SmearedRiseAndFall(double *x, double *parameter)
{
   double t = x[0];
   double nevts   = parameter[0];
   double tfall   = parameter[1];
   double trise   = parameter[2];
   double toffset = parameter[3];
   double sigma   = parameter[4];

   if (tfall<trise) return 0;

   return nevts/(tfall-trise)/2. * exp(-t/tfall-t/trise) * (
         exp(t/trise + toffset/tfall + sigma*sigma/tfall/tfall/2.) *
         erfc(sigma/tfall/sqrt(2.)-t/sigma/sqrt(2.)+toffset/sigma/sqrt(2.)) -
         exp(t/tfall + toffset/trise + sigma*sigma/trise/trise/2.) *
         erfc(sigma/trise/sqrt(2.)-t/sigma/sqrt(2.)+toffset/sigma/sqrt(2.)));
}

//______________________________________________________________________________
//

double CUM::SmearedRiseAndDoubleFall(double *x, double *parameter)
{
   double t = x[0];
   double nevts = parameter[0];
   double tfall = parameter[1];
   double trise = parameter[2];
   double toffset = parameter[3];
   double sigma = parameter[4];
   double tfall2 = parameter[5];
   double w      = parameter[6];

   if (tfall<trise) return 0;

   return w*(nevts/(tfall-trise)/2. * exp(-t/tfall-t/trise) * (
            exp(t/trise + toffset/tfall + sigma*sigma/tfall/tfall/2.) *
            erfc(sigma/tfall/sqrt(2.)-t/sigma/sqrt(2.)+toffset/sigma/sqrt(2.))-
            exp(t/tfall + toffset/trise + sigma*sigma/trise/trise/2.) *
            erfc(sigma/trise/sqrt(2.)-t/sigma/sqrt(2.)+toffset/sigma/sqrt(2.))))+
      (1.-w)*(nevts/(tfall2-trise)/2. * exp(-t/tfall2-t/trise) * (
               exp(t/trise + toffset/tfall2 + sigma*sigma/tfall2/tfall2/2.) *
               erfc(sigma/tfall2/sqrt(2.)-t/sigma/sqrt(2.)+toffset/sigma/sqrt(2.))-
               exp(t/tfall2 + toffset/trise + sigma*sigma/trise/trise/2.) *
               erfc(sigma/trise/sqrt(2.)-t/sigma/sqrt(2.)+toffset/sigma/sqrt(2.))));
}

//______________________________________________________________________________
//

double CUM::ContinuousPoisson(double *x, double *parameter)
{
   double normal = parameter[0];
   double binWidth = parameter[1];
   double mu = parameter[2];
   double scale = parameter[3];
   return normal/binWidth/scale*pow(mu,x[0]/scale)*exp(-mu)/tgamma(x[0]/scale+1);
}

//______________________________________________________________________________
//

void CUM::Cartesian2Geographic(double x, double y, double z, // input
      double *longitude, double *latitude) // output
{
   double r = sqrt(x*x+y*y+z*z);
   *latitude = pi/2.-acos(z/r);

   if (abs(*latitude)==pi/2.0) {
      *longitude = 0;
   } else if (y>=0) {
      *longitude = acos(x/sqrt(x*x+y*y));
   } else {
      *longitude = -acos(x/sqrt(x*x+y*y));
   }
}

//______________________________________________________________________________
//

void CUM::Geographic2Mollweide(double *x, double *y)
{
   double latitude = *y;
   double longitude = *x;

   // calculate theta by newton's method
   bool isPrecise = false;
   double dt, theta = 0;
   for (int i=0; i<100; i++) {
      dt = -(theta + sin(theta) - pi*sin(latitude))/(cos(theta) + 1);
      theta += dt;

      if (abs(dt)<=1e-12) { 
         isPrecise = true;
         break;
      }
   }
   if (isPrecise==false) cout<<"Newton's method failed!"<<endl;
   theta/=2.;

   *x = 2.*sqrt(2.)*longitude/pi*cos(theta);
   *y = sqrt(2.)*sin(theta);
}

//______________________________________________________________________________
//

void CUM::Geographic2AzimuthalEquidistant(
      double latitude, double longitude, double *x, double *y)
{
   *x =  (latitude+pi/2.)*cos(longitude);
   *y = -(latitude+pi/2.)*sin(longitude);
}
