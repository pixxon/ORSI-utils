#pragma once

#include "core/symbol_table.h"
#include "core/tokenizer.h"
#include "core/parser.h"
#include "core/evaluator.h"

struct MathEvaluator
{
	MathEvaluator(const std::string& Input);
	
	double calculate(const double x);
	
private:
	std::unique_ptr<Evaluator> mEvaluator;
};
