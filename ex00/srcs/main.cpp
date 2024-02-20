/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:15:22 by mgagne            #+#    #+#             */
/*   Updated: 2024/02/20 15:49:43 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main( void )
{
	try
	{
		Bureaucrat hug("hug", 149);
		std::cout << hug;
		hug.reduceGrade();
		std::cout << hug;
		// hug.reduceGrade();

		Bureaucrat tyler( "tyler", 2 );
		std::cout << tyler;
		tyler.reduceGrade();
		std::cout << tyler;
		tyler.raiseGrade();
		std::cout << tyler;
	}

	catch ( std::exception & error )
	{
		std::cout << error.what( );
	}

	return ( 0 );
}
