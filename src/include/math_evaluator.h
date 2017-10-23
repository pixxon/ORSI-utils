#pragma once

#include <string>
#include <memory>

struct Evaluator;

struct MathEvaluator
{
	MathEvaluator(const std::string& Input);
	~MathEvaluator();
	
	double calculate(const double x);
	
private:
	std::unique_ptr<Evaluator> mEvaluator;
};
