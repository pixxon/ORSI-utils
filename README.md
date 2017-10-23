# ORSI-utils
Helper library for ORSI.  

Using this library is simple, you can build it using CMake.
  
  
0. If you don't have CMake installed with a C++ compiler you should do it now!
1. Download or clone the repository then navigate to the build directory.
```bash
cmake .
```
2. Copy the **libEvaluator** to the desired location with the required header(s) found in **include**. ( Most likely will be next to your main.cpp. )  
Reference main.cpp:
```c++
#include "math_evaluator.h"

#include <iostream>

int main()
{
  MathEvaluator evaluator("x+2");
  std::cout << evaluator.calculate(3);
  return 0;
}
```
3. Compile your code and link the lib.
```bash
g++ main.cpp -L . -l Evaluator
```
4. Run your code!
```bash
./a.out
5
```
