#include "math_evaluator.h"

MathEvaluator::MathEvaluator(const std::string& Input)
{
	SymbolTable table;
	table.insertSymbol("var", std::regex("^x"), Arity::CONSTANT, Associativity::NONE, 0, nullptr);
	table.insertSymbol("num", std::regex("^[0-9]+(\\.[0-9]+)?"), Arity::CONSTANT, Associativity::NONE, 0, nullptr);
	table.insertSymbol("open", std::regex("^\\("), Arity::BRACKET, Associativity::LEFT, 0, nullptr);
	table.insertSymbol("close", std::regex("^\\)"), Arity::BRACKET, Associativity::RIGHT, 0, nullptr);
	
	table.insertSymbol("add", std::regex("^\\+"), Arity::BINARY, Associativity::LEFT, 1, [](double a, double b){ return a + b; });
	table.insertSymbol("min", std::regex("^-"), Arity::MULTI, Associativity::LEFT, 1, [](double a, double b){ return a - b; });
	table.insertSymbol("mul", std::regex("^\\*"), Arity::BINARY, Associativity::LEFT, 2, [](double a, double b){ return a * b; });
	table.insertSymbol("div", std::regex("^/"), Arity::BINARY, Associativity::LEFT, 2, [](double a, double b){ return a / b; });
	table.insertSymbol("pow", std::regex("^\\^"), Arity::BINARY, Associativity::RIGHT, 3, [](double a, double b){ return pow(a, b); });
	
	table.insertSymbol("abs", std::regex("^abs"), Arity::UNARY, Associativity::NONE, 0, [](double a, double){ return a<0?-a:a; });
	
	table.insertSymbol("sin", std::regex("^sin"), Arity::UNARY, Associativity::NONE, 0, [](double a, double){ return sin(a); });
	table.insertSymbol("cos", std::regex("^cos"), Arity::UNARY, Associativity::NONE, 0, [](double a, double){ return cos(a); });
	table.insertSymbol("tg", std::regex("^tg"), Arity::UNARY, Associativity::NONE, 0, [](double a, double){ return tan(a); });
	table.insertSymbol("ctg", std::regex("^ctg"), Arity::UNARY, Associativity::NONE, 0, [](double a, double){ return 1 / tan(a); });

	Tokenizer tokenizer(table, Input);
	Parser parser(tokenizer);
	mEvaluator.reset(new Evaluator(parser));
}

double MathEvaluator::calculate(const double x)
{
	return mEvaluator->calculate(x);
}
