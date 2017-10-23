#pragma once

#include "node.h"

#include <set>
#include <sstream>
#include <string>

struct TreePrinter
{
	std::string toString(const Node& Root);
	
private:
	void indent(std::stringstream& Out, uint8_t Level);
	void left(std::stringstream& Out, uint8_t Level);
	void right(std::stringstream& Out, uint8_t Level);
	void print(std::stringstream& Out, const Node& Root, uint8_t Level);
	
	std::set<uint8_t> mLevels;
};