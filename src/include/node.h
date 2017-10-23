#pragma once

#include "token.h"

struct Node
{
	Node(std::unique_ptr<Node> Left, std::unique_ptr<Node> Right, const Token& Data):
		mLeft(std::move(Left)),
		mRight(std::move(Right)),
		mToken(Data)
	{
	}
	
	const Node& getLeft() const
	{
		return *mLeft;
	}
	
	const Node& getRight() const
	{
		return *mRight;
	}
	
	const bool hasLeft() const 
	{
		return mLeft != nullptr;
	}
	
	const bool hasRight() const
	{
		return mRight != nullptr;
	}
	
	const Token& getToken() const
	{
		return mToken;
	}

private:
	std::unique_ptr<Node> mLeft;
	std::unique_ptr<Node> mRight;
	Token mToken;
};