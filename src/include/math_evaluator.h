#pragma once

#include <string>
#include <memory>

#include "evaluator.h"

struct MathEvaluator
{
	MathEvaluator(const std::string& Input);
	
	double calculate(const double x);
	
private:
	std::unique_ptr<Evaluator> mEvaluator;
};
