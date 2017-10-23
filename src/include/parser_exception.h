#pragma once

#include <exception>
#include <string>

struct LexicalException : std::exception
{
	LexicalException(const std::string& Input):
		mInput("Parsing failed on: " + Input)
	{
	}
	
	const char* what() const noexcept override
	{
		return mInput.c_str();
	}
	
private:
	std::string mInput;
};

struct UnexceptedTokenException : std::exception
{
	UnexceptedTokenException(const std::string& Input):
		mInput("Unexpected input: " + Input)
	{
	}
	
	const char* what() const noexcept override
	{
		return mInput.c_str();
	}
	
private:
	std::string mInput;
};
