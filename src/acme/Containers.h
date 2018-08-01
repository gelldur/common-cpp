//
// Created by Dawid Drozd aka Gelldur on 04.12.17.
//
#pragma once

namespace Acme
{

template <typename ContainerT, typename PredicateT>
void erase_if(ContainerT& items, const PredicateT& predicate)
{
	for(auto it = items.begin(); it != items.end();)
	{
		if(predicate(*it))
		{
			it = items.erase(it);
		}
		else
		{
			++it;
		}
	}
}

template <typename ContainerT, typename PredicateT>
void remove_if(ContainerT& items, const PredicateT& predicate) //TODO
{
	auto removeFrom = std::remove_if(std::begin(items), std::end(items), predicate);
	if(removeFrom != std::end(items))
	{
		items.erase(removeFrom, std::end(items));
	}
}

template <typename ContainerT, typename Iterator>
void erase_fast(ContainerT& items, const Iterator& iterator)
{
	if(items.empty())
	{
		return;
	}
	std::swap(items.back(), *iterator);
	items.pop_back();
}

} // namespace Acme
