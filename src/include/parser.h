#pragma once

#include "parser_exception.h"
#include "tokenizer.h"
#include "symbol_table.h"
#include "node.h"

struct Parser
{
	Parser(Tokenizer& Tokener):
		mTokenizer(Tokener)
	{}

	std::unique_ptr<Node> getTree()
	{
		mTokenizer.reset();
		auto Result = parse(0);
		
		if (mTokenizer.hasNext())
		{
			throw UnexceptedTokenException(mTokenizer.current().getValue());
		}
		
		return std::move(Result);
	}

private:
	Tokenizer mTokenizer;
	
	std::unique_ptr<Node> parse(const Precedence);
	std::unique_ptr<Node> parse_primary();
};
