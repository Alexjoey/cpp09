/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <alexm@live.be>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 09:13:21 by amylle            #+#    #+#             */
/*   Updated: 2025/04/26 09:16:25 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	RPN rpn;

	if (argc == 2)
	{
		try
		{
		rpn.execute(std::string(argv[1]));
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error\n";
		}
	}
	else
		std::cerr << "Error\n";
}
