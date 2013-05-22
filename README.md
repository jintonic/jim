cum - constants, units and maths

#####Concept

This library is meant to remove the dependence on 
[CLHEP](http://proj-clhep.web.cern.ch/proj-clhep/).

Units.h is a copy of
[CLHEP/Units](http://proj-clhep.web.cern.ch/proj-clhep/manual/UserGuide/Units/units.html)/[SystemOfUnits.h](http://proj-clhep.web.cern.ch/proj-clhep/manual/RefGuide/Units/SystemOfUnits_h.html)
with the following extensions
- kpc
- light_year, lightyear, ly
- astronomical_unit, AU
- fm

Constants.h is a copy of
[CLHEP/Units](http://proj-clhep.web.cern.ch/proj-clhep/manual/UserGuide/Units/units.html)/[PhysicalConstants.h](http://proj-clhep.web.cern.ch/proj-clhep/doxygen/html/PhysicalConstants_8h-source.html)
with the following extensions
- fourpi, pi4, pi3
- fermi_const, GF

Maths.h and Maths.cc define functions in the following format
```cpp
double func(double *x, double *parameter);
```
which can be directly used to construct a 
[TF1](http://root.cern.ch/root/html/TF1.html)
object provided in [ROOT](http://root.cern.ch).

Everything is nested in a namespace called ```CUM```. The reason not to have nested namespaces, such as ```CUM::Unit```, ```CUM::Const``` and ```CUM::Math```, is to save typing.

#####Installation

```bash
vi Makefile # specify directory to install in the 1st line
make
make install
```
After a successful installation, header files are copied to ```/prefix/include/CUM/```. libCUM.so is copied to ```/prefix/lib/```

#####Usage

```cpp
#include <CUM/Units.h>
using namespace CUM;
```
