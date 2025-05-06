/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <alexm@live.be>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:16:43 by amylle            #+#    #+#             */
/*   Updated: 2025/05/05 22:19:47 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iomanip>
#include <stdlib.h>
#include <ctime>
#include <iostream>

int	main(int argc, char **argv)
{
	(void) argc;
	std::vector<int> vec;
	for (std::size_t i = 1; argv[i]; i++)
		vec.push_back(atoi(argv[i]));
	clock_t startVec = clock();
	PmergeMe::sort(vec);
	clock_t endVec = clock();

	std::list<int> list;
	for (std::size_t i = 1; argv[i]; i++)
		list.push_back(atoi(argv[i]));
	clock_t startList = clock();
	PmergeMe::sort(list);
	clock_t endList = clock();
	double vecTime = static_cast<double>(endVec - startVec) * 1000.0 / CLOCKS_PER_SEC;
	double listTime = static_cast<double>(endList - startList) * 1000.0 / CLOCKS_PER_SEC;

	std::cout << "Before: ";
	for (size_t i = 1; argv[i]; i++)
		std::cout << argv[i] << " ";
	std::cout << std::endl;
	std::cout << "After: ";
	printVector(vec);
	std::cout << std::fixed << std::setprecision(3) << "Time to process a range of " << vec.size() << " elements with std::vector: " << vecTime << " ms\n";
	std::cout << std::fixed << std::setprecision(3) << "Time to process a range of " << list.size() << " elements with std::list: " << listTime << " ms\n";
}
