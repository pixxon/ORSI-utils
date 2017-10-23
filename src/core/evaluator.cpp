#include "evaluator.h"

#include <sstream>

double Evaluator::calculate(const double x)
{
	return calculateAt(*mRoot.get(), x);
}

double Evaluator::calculateAt(const Node& Root, const double x)
{
	// Todo: remove dependency on "num"
	if (Root.getToken().getInfo().getName() == "num")
	{
		std::stringstream Buffer(Root.getToken().getValue());
		double Result;
		Buffer >> Result;
		return Result;
	}

	// Todo: remove dependency on "var"
	if (Root.getToken().getInfo().getName() == "var")
	{
		return x;
	}

	double Left = Root.hasLeft() ? calculateAt(Root.getLeft(), x) : 0;
	double Right = Root.hasRight() ? calculateAt(Root.getRight(), x) : 0;

	return Root.getToken().getInfo().getFunction()(Left, Right);
}
