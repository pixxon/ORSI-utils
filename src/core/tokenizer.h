#pragma once

#include "symbol_table.h"
#include "token.h"

// Should refactor to use a better interface and drop mCurrent...

class Tokenizer
{
public:
	Tokenizer(const SymbolTable& Table,
		const std::string& Input) :
		mInput(Input),
		mTable(Table),
		mCurrent(*Table.begin(), ""),
		mInputIt(mInput.begin())
	{}
	
	Token current() const
	{
		return mCurrent;
	}
	
	void next();
	
	bool hasNext() const
	{
		return mInputIt != mInput.end();
	}
	
	void reset()
	{
		mInputIt = mInput.begin();
	}
	
private:
	Token mCurrent;
	std::string mInput;
	std::string::const_iterator mInputIt;
	SymbolTable mTable;
};
