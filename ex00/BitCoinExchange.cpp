/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <alexm@live.be>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:23:16 by amylle            #+#    #+#             */
/*   Updated: 2025/06/18 14:55:24 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitCoinExchange::BitCoinExchange()
{
	parseDatabase();
}

BitCoinExchange::BitCoinExchange(const BitCoinExchange &other): _rates(other._rates)
{
}

BitCoinExchange::~BitCoinExchange()
{
}

BitCoinExchange& BitCoinExchange::operator= (const BitCoinExchange &other)
{
	if (this != &other)
		this->_rates = other._rates;
	return (*this);
}

void	BitCoinExchange::execute(const char *fileName) const
{
	std::ifstream file(fileName);
	if (!file.is_open())
		throw std::ifstream::failure("Cannot open file: " + std::string(fileName));

	std::string	line;
	std::getline(file, line);
	if (line != "date | value")
		throw std::runtime_error("Invalid input file header");
	std::cout << std::fixed << std::setprecision(2);

	while (getline(file, line))
	{
		try
		{
			std::string	date, valueString, pipe;
			std::istringstream	ss(line);
			
			if (!(ss >> date) || !isValidDate(date))
				throw std::runtime_error("Bad input => " + line);
			if (!(ss >> pipe) || pipe != "|")
				throw std::runtime_error("Bad input => " + line);
			if (!(ss >> valueString))
				throw std::runtime_error("Bad input => " + line);
			
			int value = parseValue(valueString);
			double	rate = getRate(date);
			std::cout << date << " => " << value << " = " << value * rate << "\n";
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	file.close();
}

double	BitCoinExchange::getRate(const std::string& date) const
{
	std::map<std::string, double>::const_iterator it = _rates.find(date);
	if (it != _rates.end())
		return (it->second);
	else
	{
		it = _rates.lower_bound(date);
		if (it == _rates.begin())
			throw std::runtime_error("Date before database start: " + date);
		--it;
		return (it->second);
	}
}

int	BitCoinExchange::parseValue(const std::string& valueStr) const
{
	std::istringstream ss(valueStr);
	int	value;

	if (!(ss >> value))
		throw std::runtime_error("bad value input => " + valueStr);
	if (value < 0)
		throw std::runtime_error("not a positive number.");
	if (value > 1000)
		throw std::runtime_error("too large a number");
	return (value);
}

static bool	isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool	BitCoinExchange::isValidDate(const std::string& date) const
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return (false);
    int year, month, day;
    if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
        return (false);
    if (month < 1 || month > 12)
		return (false);
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year))
        daysInMonth[1] = 29;
    if (day < 1 || day > daysInMonth[month - 1])
        return (false);
    return (true);
}

void	BitCoinExchange::parseDatabase()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw std::ifstream::failure("Cannot open data.csv");
	std::string	line;
	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("Invalid database header");
	while (getline(file, line))
	{
		std::string			date, rateString;
		std::istringstream	ss(line);
		std::getline(ss, date, ',');
		if (!isValidDate(date))
			throw std::runtime_error("Invalid date in database: " + date);

		std::getline(ss, rateString);
		double	rate;
		std::istringstream	rateStream(rateString);
		if (!(rateStream >> rate) || rate < 0)
			throw std::runtime_error("Invalid exchange rate in database: " + rateString);
		_rates[date] = rate;
	}
	file.close();
}
