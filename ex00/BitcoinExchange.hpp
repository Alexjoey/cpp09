/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <alexm@live.be>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:23:13 by amylle            #+#    #+#             */
/*   Updated: 2025/04/25 19:07:50 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <iostream>

class BitCoinExchange
{
public:
	BitCoinExchange();
	BitCoinExchange(const BitCoinExchange &other);
	~BitCoinExchange();
	BitCoinExchange& operator= (const BitCoinExchange &other);

	void	execute(const char *fileName) const;

private:
	bool	isValidDate(const std::string& date) const;
	double	getRate(const std::string& date) const;
	int		parseValue(const std::string& valueStr) const;
	void	parseDatabase();
	std::map<std::string, double> _rates;
};
