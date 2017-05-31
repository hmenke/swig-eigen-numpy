# Instructions

Install Eigen3 and Python3 such that CMake can find them.  On Ubuntu
16.04 it suffices to install the corresponding packages.

Then follow the usual CMake workflow

````bash
mkdir build
cd build
cmake ..
make
````

In the `build` directory execute

````bash
python3 test.py
````

and watch hell break loose!