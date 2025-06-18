/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <alexm@live.be>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:06:50 by amylle            #+#    #+#             */
/*   Updated: 2025/06/18 15:00:09 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./bitcoin [file]\n";
		return (1);
	}

	try
	{
		BitCoinExchange exchange;
		exchange.execute(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	return (0);
}
