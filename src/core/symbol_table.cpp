#include "include/symbol_table.h"

#include "include/symbol_exception.h"

void SymbolTable::insertSymbol(const std::string& Name,
	const std::regex& rgx,
	const Arity& arity,
	const Associativity& asso,
	const Precedence& prec,
	const BinaryFunction& func)
{
	const auto It = findSymbol(Name);
	if (It != mTable.end())
	{
		throw SymbolAlreadyExistsException(Name);
	}

	mTable.emplace_back(Name, rgx, arity, asso, prec, func);
}

void SymbolTable::removeSymbol(const std::string& Name)
{
	const auto It = findSymbol(Name);
	if (It == mTable.end())
	{
		throw SymbolNotFoundException(Name);
	}
	mTable.erase(It);
}

const SymbolInfo& SymbolTable::operator[](const std::string& Name) const
{
	const auto It = findSymbol(Name);
	if (It == mTable.end())
	{
		throw SymbolNotFoundException(Name);
	}
	*It;
}

std::vector<SymbolInfo>::const_iterator SymbolTable::findSymbol(const std::string& Name) const
{
	const auto It = std::find_if(mTable.begin(), mTable.end(), [&](const SymbolInfo& Symbol){ return Symbol.getName() == Name; });
}
