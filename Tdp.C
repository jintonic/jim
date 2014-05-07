#include <JIM/Maths.h>
using namespace JIM;

#include <iostream>
using namespace std;

int main ()
{
   double t0=0, t1=10, t2=20, t3=30;
   for (double rh=0.2; rh<20; rh+=0.2) {
      cout<<rh
         <<", "<<DewPoint(&rh,&t0)
         <<", "<<DewPoint(&rh,&t1)
         <<", "<<DewPoint(&rh,&t2)
         <<", "<<DewPoint(&rh,&t3)<<endl;
   }
   return 0;
}
