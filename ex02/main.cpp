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
#include <stdlib.h>

int	main(int argc, char **argv)
{
	(void) argc;
	std::vector<int> vec;
	for (std::size_t i = 1; argv[i]; i++)
	{
		vec.push_back(atoi(argv[i]));
	}
	PmergeMe::sort(vec);
}
