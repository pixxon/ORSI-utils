#pragma once

#include <vector>

#include "symbol_info.h"

struct SymbolTable
{
	void insertSymbol(const std::string& name,
		const std::regex& rgx,
		const Arity& arity,
		const Associativity& asso,
		const Precedence& prec,
		const BinaryFunction& func);
	
	void removeSymbol(const std::string& name);
	
	const SymbolInfo& operator[](const std::string& name) const;
	
	struct const_iterator
	{
		explicit const_iterator(std::vector<SymbolInfo>::const_iterator It) :
			mIt(It)
		{}
		
		const_iterator& operator++()
		{
			mIt++;
			return *this;
		}
		
		const_iterator operator++(int)
		{
			const_iterator retval = *this;
			++(*this);
			return retval;
		}
		
		bool operator==(const_iterator other) const
		{
			return mIt == other.mIt;
		}
		
		bool operator!=(const_iterator other) const
		{
			return !(*this == other);
		}
		
		const SymbolInfo& operator*() const
		{
			return *mIt;;
		}
		
		const SymbolInfo* operator->() const
		{
			return &(*mIt);
		}
		
		using difference_type = long;
		using value_type = SymbolInfo;
		using pointer = const SymbolInfo*;
		using reference = const SymbolInfo&;
		using iterator_category = std::forward_iterator_tag;
		
	private:
		std::vector<SymbolInfo>::const_iterator mIt;
	};
	
	const_iterator begin() const
	{
		return const_iterator(mTable.begin());
	}
	
	const_iterator end() const
	{
		return const_iterator(mTable.end());
	}

private:
	std::vector<SymbolInfo>::const_iterator findSymbol(const std::string& Name) const;
	
	std::vector<SymbolInfo> mTable;
};
