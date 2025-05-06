/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <alexm@live.be>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:24:54 by amylle            #+#    #+#             */
/*   Updated: 2025/05/05 22:21:15 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <functional>
#include <iostream>

bool	PmergeMe::comparePairs(std::pair<int, int> a, std::pair<int, int> b)
{
	if (a.second < b.second)
		return (1);
	return (0);
}

void printVector(const std::vector<int> &vec)
{
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void printList(const std::list<int> &list)
{
	for (std::list<int>::const_iterator it = list.begin(); it != list.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void printPairs(const std::vector<std::pair<int, int> > &vec)
{
	for (std::vector<std::pair<int, int> >::const_iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << "(" << it->first << ", " << it->second << ") ";
	}
	std::cout << std::endl;
}

void	binaryInsertion(std::vector<int> &vec, std::vector<int>::iterator end, int value)
{
	std::vector<int>::iterator it = std::lower_bound(vec.begin(), end, value);
	vec.insert(it, value);
}

void	binaryInsertion(std::list<int> &list, std::list<int>::iterator end, int value)
{
	std::list<int>::iterator it = std::lower_bound(list.begin(), end, value);
	list.insert(it, value);
}

void	PmergeMe::insertIntoMainChain(vecPair &pairs, std::vector<int> &main_chain, bool isOdd, int additional_value)
{
	std::size_t jacobsthal[16] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691};
	int jacobsthalIdx = 1;

	std::vector<int>::iterator sliceDelimIt;
	vecPairIter pairIt;
	vecPairIter lastJacobIt = pairs.begin();

	while (jacobsthal[jacobsthalIdx] <= pairs.size())
	{
		pairIt = pairs.begin() + (jacobsthal[jacobsthalIdx] - 1);
		lastJacobIt = pairIt;

		int insertionCounter = 0;
		while (jacobsthal[jacobsthalIdx] - insertionCounter > jacobsthal[jacobsthalIdx - 1])
		{
			sliceDelimIt = std::find(main_chain.begin(), main_chain.end(), pairIt->second);
			binaryInsertion(main_chain, sliceDelimIt, pairIt->first);
			pairIt--;
			insertionCounter++;
		}
		jacobsthalIdx++;
	}

	if (jacobsthal[jacobsthalIdx] != pairs.size())
	{
		pairIt = pairs.end();
		if (pairIt != pairs.begin())
			pairIt--;
		while (pairIt != lastJacobIt)
		{
			sliceDelimIt = std::find(main_chain.begin(), main_chain.end(), pairIt->second);
			binaryInsertion(main_chain, sliceDelimIt, pairIt->first);
			pairIt--;
		}
	}
	if (isOdd == true)
	{
		binaryInsertion(main_chain, main_chain.end(), additional_value);
	}
}

void	PmergeMe::sort(std::vector<int> &vec)
{
	if (vec.size() < 2)
		return ;

	bool	isOdd = false;
	int		oddValue;
	if (vec.size() % 2 != 0)
	{
		isOdd = true;
		oddValue = vec.back();
		vec.pop_back();
	}

	std::vector<std::pair<int, int> > pairs(vec.size() / 2);
	for (std::size_t i = 0; i < vec.size(); i += 2)
		pairs[i / 2] = (std::pair<int, int> (vec[i], vec[i + 1]));
	sortPairs(pairs);
	mergeSortPairs(pairs.begin(), pairs.end(), pairs.size());

	//init main chain
	std::vector<int> mainChain(vec.size() / 2);
	for (std::size_t i = 0; i < pairs.size(); i++)
		mainChain[i] = pairs[i].second;
	mainChain.insert(mainChain.begin(), pairs[0].first);
	insertIntoMainChain(pairs, mainChain, isOdd, oddValue);
	vec = mainChain;
}

void	PmergeMe::sort(std::list<int> &list)
{
	(void) list;
}

void	PmergeMe::sortPairs(vecPair &pairs)
{
	for (vecPairIter it = pairs.begin(); it != pairs.end(); it++)
		if (it->first > it->second)
			std::swap(it->first, it->second);
}

void	PmergeMe::sortPairs(listPair &pairs)
{
	for (listPairIter it = pairs.begin(); it != pairs.end(); it++)
		if (it->first > it->second)
			std::swap(it->first, it->second);
}

void	PmergeMe::mergeSortPairs(vecPairIter begin, vecPairIter end, std::size_t size)
{
	if (size == 0 && begin != end)
		size = std::distance(begin, end);
	if (size < 2)
		return ;

	std::size_t sizeFirstHalf = size / 2;
	std::size_t sizeSecHalf = size - sizeFirstHalf;
	vecPairIter center = begin;
	std::advance(center, sizeFirstHalf);

	// Recursively sort both halves
	mergeSortPairs(begin, center, sizeFirstHalf);
	mergeSortPairs(center, end, sizeSecHalf);

	// Merge the sorted halves back into lst
	std::inplace_merge(begin, center, end, &comparePairs);
}

void PmergeMe::mergeSortPairs(listPair& lst, std::size_t size)
{
	if (size == 0 && !lst.empty())
		size = lst.size();
	if (size < 2)
		return ;

	std::size_t sizeFirstHalf = size / 2;
	std::size_t sizeSecHalf = size - sizeFirstHalf;

	listPair left, right;
	listPairIter mid = lst.begin();
	std::advance(mid, lst.size() / 2);

	left.splice(left.begin(), lst, lst.begin(), mid);
	right.splice(right.begin(), lst, lst.begin(), lst.end());

	// Recursively sort both halves
	mergeSortPairs(left, sizeFirstHalf);
	mergeSortPairs(right, sizeSecHalf);

	// Merge the sorted halves back into lst
	left.merge(right, &comparePairs);
	lst.swap(left);
}
