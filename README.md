# ORSI-utils
Helper library for ORSI.  

---  
## libEvaluator
0. If you don't have CMake installed with a C++ compiler you should do it now!
1. Download or clone the repository then navigate to the build directory.
```bash
cmake .
make all -j4
```
2. Copy the **libEvaluator** to the desired location with the required header **math_evaluator.h** found in **include**.  
Reference main.cpp:
```c++
#include "math_evaluator.h"

#include <iostream>

int main()
{
  MathEvaluator evaluator("x+2");
  std::cout << evaluator.calculate(3) << std::endl;
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

---
## libBMPWriter
0. *(not needed if done already)* If you don't have CMake installed with a C++ compiler you should do it now!
1. *(not needed if done already)* Download or clone the repository then navigate to the build directory.
```bash
cmake .
make all -j4
```
2. Copy the **libBMPWriter** to the desired location with the required header **bmp_image.h** found in **include**.  
Reference main.cpp:
```c++
#include "bmp_image.h"

#include <fstream>

int main()
{
	BMPImage image(640, 480);
	
	for(uint32_t ColIndex = 100; ColIndex < 300; ColIndex++)
	{
		for(uint32_t RowIndex = 250; RowIndex < 300; RowIndex++)
		{
			image.setColor(ColIndex, RowIndex, Color(255, 0, 0));
		}
		for(uint32_t RowIndex = 30; RowIndex < 80; RowIndex++)
		{
			image.setColor(ColIndex, RowIndex, Color(0, 255, 0));
		}
	}
	
	std::ofstream out("output.bmp");
	out << image;
	out.close();
  
  return 0;
}
```
3. Compile your code and link the lib.
```bash
g++ main.cpp -L . -l BMPWriter
```
4. Run your code!
```bash
./a.out
5
```
---
