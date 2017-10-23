#pragma once

#include "parser.h"

struct Evaluator
{
	Evaluator(Parser parse):
		mRoot(parse.getTree())
	{}
	
	double calculate(const double);
	
	const Node& getRoot() const
	{
		return *mRoot;
	}
	
private:
	double calculateAt(const Node&, const double);
	
	std::unique_ptr<Node> mRoot;
};
