SET(EXECUTABLE_OUTPUT_PATH "build")
SET(CMAKE_CXX_STANDARD 11)

PROJECT(ORSI-Utils)

INCLUDE_DIRECTORIES("../src")

ADD_LIBRARY(Evaluator STATIC /
	../src/core/symbol_table.cpp /
	../src/core/tokenizer.cpp /
	../src/core/parser.cpp /
	../src/core/evaluator.cpp /
	../src/core/tree_printer.cpp /
	../src/utils/math_evaluator.cpp)

ADD_LIBRARY(BMPWriter STATIC /
	../src/utils/bmp_image.cpp)
