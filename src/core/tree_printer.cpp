#include "include/tree_printer.h"

std::string TreePrinter::toString(const Node& Root)
{
	std::stringstream Result;
	print(Result, Root, 0);
	return Result.str();
}

void TreePrinter::indent(std::stringstream& Out, uint8_t Level)
{
	for (int i = 0; i < Level; i++)
	{
		if (mLevels.count(i) != 0)
		{
			Out << "   | ";
		}
		else
		{
			Out << "    ";
		}
	}
}

void TreePrinter::left(std::stringstream& Out, uint8_t Level)
{
	indent(Out, Level);
	Out << "   |-";
	mLevels.insert(Level);
}

void TreePrinter::right(std::stringstream& Out, uint8_t Level)
{
	indent(Out, Level);
	Out << "   `-";
	mLevels.erase(Level);
}

void TreePrinter::print(std::stringstream& Out, const Node& Root, uint8_t Level)
{
	Out << "( " << Root.getToken().getValue() << " )" << std::endl;
	
	if (Root.hasLeft() && Root.hasRight())
	{
		left(Out, Level);
		print(Out, Root.getLeft(), Level + 1);
		right(Out, Level);
		print(Out, Root.getRight(), Level + 1);
	}
	else if (Root.hasLeft())
	{
		right(Out, Level);
		print(Out, Root.getLeft(), Level + 1);
	}
	else if (Root.hasLeft())
	{
		right(Out, Level);
		print(Out, Root.getRight(), Level + 1);
	}
}
