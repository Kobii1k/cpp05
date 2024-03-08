/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:15:22 by mgagne            #+#    #+#             */
/*   Updated: 2024/03/05 15:04:36 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main( void )
{
	try
	{
		Bureaucrat hug("hug", 10);
		Form contract("contract", 10, 10);

		std::cout << hug;
		std::cout << contract;

		hug.reduceGrade();
		std::cout << hug;

		hug.signForm(contract);

		hug.raiseGrade();
		std::cout << hug;

		hug.signForm(contract);
		hug.signForm(contract);



		// Form c2("c2", 1, 151);
		// Form c2("c2", 0, 100);
	}
	catch (std::exception &error)
	{
		std::cerr << error.what();
	}
	return (0);
}
