jim - jing's math library

#####Concept

Maths.h and Maths.cc define functions in the following format
```cpp
double func(double *x, double *parameter);
```
which can be directly used to construct a 
[TF1](http://root.cern.ch/root/html/TF1.html)
object provided in [ROOT](http://root.cern.ch).

Everything is nested in a namespace called ```JIM```.

#####Installation

```bash
vi Makefile # specify directory to install in the 1st line
make
make install
```
After a successful installation, 
header files are copied to ```/prefix/include/JIM/```.
libJIM.so is copied to ```/prefix/lib/```

#####Usage

```cpp
#include <JIM/Maths.h>
using namespace JIM;
```
