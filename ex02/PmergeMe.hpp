/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <alexm@live.be>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:12:09 by amylle            #+#    #+#             */
/*   Updated: 2025/05/05 22:16:38 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <list>
#include <utility>

class	PmergeMe
{
	typedef typename std::vector<std::pair<int, int> > vecPair;
	typedef typename std::list<std::pair<int, int> > listPair;
	typedef typename vecPair::iterator vecPairIter;
	typedef typename listPair::iterator listPairIter;

public:
	static void	sort(std::vector<int> &vec);
	static void	sort(std::list<int> &list);

private:
	//compares second member of each pair
	static bool	comparePairs(std::pair<int, int> a, std::pair<int, int> b);

	//sorts the whole container, for each pair itself, so pair(a, b) will be sorted yk
	static void	sortPairs(vecPair &pairs);
	static void	sortPairs(listPair &pairs);

	static void	mergeSortPairs(vecPairIter begin, vecPairIter end, std::size_t size);
	static void	mergeSortPairs(listPairIter begin, listPairIter end, std::size_t size);

	static void insertIntoMainChain(vecPair &pairs, std::vector<int> &main_chain, bool isOdd, int additional_value);
};
