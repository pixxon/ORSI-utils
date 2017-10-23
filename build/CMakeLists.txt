SET(EXECUTABLE_OUTPUT_PATH "build")
SET(CMAKE_CXX_STANDARD 11)

PROJECT(Evaluator)

INCLUDE_DIRECTORIES("../src")

SET(CMAKE_BUILD_TYPE Debug)

ADD_LIBRARY(Evaluator STATIC /
	../src/core/symbol_table.cpp /
	../src/core/tokenizer.cpp /
	../src/core/parser.cpp /
	../src/core/evaluator.cpp /
	../src/core/tree_printer.cpp /
	../src/utils/math_evaluator.cpp)

ADD_EXECUTABLE(App
	../src/main.cpp)

TARGET_LINK_LIBRARIES(App
	Evaluator)