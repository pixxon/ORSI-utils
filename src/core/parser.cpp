#include "parser.h"

std::unique_ptr<Node> Parser::parse(const Precedence min_prec)
{
	auto Left = parse_primary();

	if (mTokenizer.hasNext())
	{
		mTokenizer.next();
		Token peek = mTokenizer.current();
		if (peek.getInfo().getArity() == Arity::UNARY)
		{
			throw UnexceptedTokenException(peek.getValue());
		}
		
		if (!mTokenizer.hasNext())
		{
			throw UnexceptedTokenException(peek.getValue());
		}
		
		while((peek.getInfo().getArity() == Arity::BINARY
				|| peek.getInfo().getArity() == Arity::MULTI)
			&& peek.getInfo().getPrecedence() >= min_prec)
		{
			auto Right = std::unique_ptr<Node>{};
			switch(peek.getInfo().getAssociativity())
			{
				case Associativity::LEFT:
					Right = parse(peek.getInfo().getPrecedence() + 1);
					break;
				case Associativity::RIGHT:
					Right = parse(peek.getInfo().getPrecedence());
					break;
				default:
					throw UnexceptedTokenException(peek.getValue());
			}

			Left.reset(new Node(std::move(Left), std::move(Right), peek));
			
			peek = mTokenizer.current();
		}
	}

	return Left;
}

std::unique_ptr<Node> Parser::parse_primary()
{
	mTokenizer.next();
	Token peek = mTokenizer.current();
	
	switch(peek.getInfo().getArity())
	{
		case Arity::CONSTANT:
			return std::unique_ptr<Node>(new Node(nullptr, nullptr, peek));
		case Arity::UNARY:
		case Arity::MULTI:
			return std::unique_ptr<Node>(new Node(parse_primary(), nullptr, peek));
		case Arity::BINARY:
			throw UnexceptedTokenException(peek.getValue());
		case Arity::BRACKET:
			if (peek.getInfo().getAssociativity() == Associativity::LEFT)
			{
				auto Expression = parse(0);
				peek = mTokenizer.current();
				if (peek.getInfo().getArity() != Arity::BRACKET ||
					peek.getInfo().getAssociativity() != Associativity::RIGHT)
				{
					throw UnexceptedTokenException(peek.getValue());
				}
				return Expression;
			}
			else
			{
				throw UnexceptedTokenException(peek.getValue());
			}
	}
}
