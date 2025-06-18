/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <alexm@live.be>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 08:51:02 by amylle            #+#    #+#             */
/*   Updated: 2025/06/18 15:07:18 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>
#include <sstream>
#include <stdexcept>


void	RPN::execute(const std::string &input)
{
	std::istringstream	ss(input);
	std::string			token;

	while (ss >> token)
	{
		if (token.size() != 1)
			throw std::exception();
		if (std::isdigit(token[0]))
			_nums.push(token[0] - '0');
		else if (token[0] == '+')
			doAddition();
		else if (token[0] == '-')
			doSubtraction();
		else if (token[0] == '*')
			doMulitplication();
		else if (token[0] == '/')
			doDivision();
		else
			throw std::exception();
	}
	int result = _nums.top();
	_nums.pop();
	if (!_nums.empty())
		throw std::exception();
	std::cout << result << std::endl;
}

void	RPN::doAddition()
{
	if (_nums.empty())
		throw std::exception();
	int a = _nums.top();
	_nums.pop();
	if (_nums.empty())
		throw std::exception();
	int b = _nums.top();
	_nums.pop();
	
	_nums.push(a + b);
}

//because of the stack LIFO, order is reversed for non associative operations
void	RPN::doSubtraction()
{
	if (_nums.empty())
		throw std::exception();
	int a = _nums.top();
	_nums.pop();
	if (_nums.empty())
		throw std::exception();
	int b = _nums.top();
	_nums.pop();

	_nums.push(b - a);
}

void RPN::doMulitplication()
{
	if (_nums.empty())
		throw std::exception();
	int a = _nums.top();
	_nums.pop();
	if (_nums.empty())
		throw std::exception();
	int b = _nums.top();
	_nums.pop();

	_nums.push(a * b);
}

//because of the stack LIFO, order is reversed for non associative operations
void	RPN::doDivision()
{
	if (_nums.empty())
		throw std::exception();
	int a = _nums.top();
	_nums.pop();
	if (_nums.empty())
		throw std::exception();
	int b = _nums.top();
	_nums.pop();
	if (a == 0)
		throw std::exception();

	_nums.push(b / a);
}
