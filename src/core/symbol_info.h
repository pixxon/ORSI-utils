#pragma once

#include <regex>

using BinaryFunction = std::function<double(double, double)>;

enum class Arity
{
	BRACKET,
	CONSTANT,
	UNARY,
	BINARY,
	MULTI
};

enum class Associativity
{
	LEFT,
	RIGHT,
	NONE
};

using Precedence = uint8_t;

struct SymbolInfo
{
	SymbolInfo(const std::string& name,
		const std::regex& rgx,
		const Arity& argc,
		const Associativity& asso,
		const Precedence& prec,
		const BinaryFunction& func):
		mName(name),
		mRegex(rgx),
		mArgc(argc),
		mAsso(asso),
		mPrec(prec),
		mFunc(func)
	{
	}

	bool operator==(const SymbolInfo& other) const
	{
		return (mName == other.mName);
	}

	const std::string& getName() const
	{
		return mName;
	}
	
	const std::regex& getRegex() const
	{
		return mRegex;
	}
	
	const Arity& getArity() const
	{
		return mArgc;
	}
	
	const Associativity& getAssociativity() const
	{
		return mAsso;
	}
	
	const Precedence& getPrecedence() const
	{
		return mPrec;
	}
	
	const BinaryFunction& getFunction() const
	{
		return mFunc;
	}

private:
	std::string mName;
	std::regex mRegex;
	Arity mArgc;
	Associativity mAsso;
	Precedence mPrec;
	BinaryFunction mFunc;
};
