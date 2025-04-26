/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <alexm@live.be>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:23:36 by amylle            #+#    #+#             */
/*   Updated: 2025/04/26 09:08:57 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

class RPN
{

public:
	void	execute(const std::string &input);

private:
	void	doAddition();
	void	doSubtraction();
	void	doMulitplication();
	void	doDivision();
	std::stack<int>	_nums;
};
