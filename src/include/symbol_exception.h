#pragma once

#include <exception>

struct SymbolNotFoundException : std::exception
{
	SymbolNotFoundException(const std::string& SymbolName):
		mSymbolName("Could not find symbol: " + SymbolName)
	{
	}
	
	const char* what() const noexcept override
	{
		return mSymbolName.c_str();
	}
	
private:
	std::string mSymbolName;
};

struct SymbolAlreadyExistsException : std::exception
{
	SymbolAlreadyExistsException(const std::string& SymbolName):
		mSymbolName("Symbol already exists: " + SymbolName)
	{
	}
	
	const char* what() const noexcept override
	{
		return mSymbolName.c_str();
	}
	
private:
	std::string mSymbolName;
};