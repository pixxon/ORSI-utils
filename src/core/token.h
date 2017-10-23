#pragma once

#include "symbol_info.h"

struct Token
{
	Token(const SymbolInfo& Info, const std::string& Value) :
		mInfo(Info),
		mValue(Value)
	{
	}
	
	const SymbolInfo& getInfo() const
	{
		return mInfo;
	}
	
	const std::string& getValue() const
	{
		return mValue;
	}
	
private:
	SymbolInfo mInfo;
	std::string mValue;
};