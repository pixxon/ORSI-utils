#include "tokenizer.h"

#include "parser_exception.h"

void Tokenizer::next()
{
	const auto It = std::find_if(mInputIt, mInput.cend(), [](const char Char){ return Char != ' '; });
	
	std::smatch SymbolMatch;
	const auto SymbolIt = std::find_if(mTable.begin(), mTable.end(), [&](const SymbolInfo& Info)
	{
		return std::regex_search(It, mInput.cend(), SymbolMatch, Info.getRegex());
	});
	
	if (SymbolIt == mTable.end())
	{
		throw LexicalException({It, mInput.cend()});
	}
	
	mCurrent = Token(*SymbolIt, SymbolMatch.str(0));
	mInputIt = It + mCurrent.getValue().size();
}
