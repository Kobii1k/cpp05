/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:15:22 by mgagne            #+#    #+#             */
/*   Updated: 2024/04/25 17:24:06 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	Bab("Bab", 25); //can sign President
		Bureaucrat	Beb("Beb", 72); //can sign Robotomy
		Bureaucrat	Bib("Bib", 145); //can sign Shrubbery

		Bureaucrat	Bob("Bob", 5); //can execute President
		Bureaucrat	Bub("Bub", 45); //can execute Robotomy
		Bureaucrat	Byb("Byb", 137); //can execute Shrubbery

		PresidentialPardonForm	Attestation_1( "Georges" );
		RobotomyRequestForm  	Attestation_2( "Wall_E" );
		ShrubberyCreationForm		Attestation_3( "home" );

		std::cout << Bab << Beb << Bib << Bob << Bub << Byb << std::endl;

		std::cout << Attestation_1 << std::endl;
		std::cout << Attestation_2 << std::endl;
		std::cout << Attestation_3 << std::endl;

		Bab.reduceGrade( );
		Beb.reduceGrade( );
		Bib.reduceGrade( );

		Bab.signForm( Attestation_1 );
		Beb.signForm( Attestation_2 );
		Bib.signForm( Attestation_3 );

		Bob.reduceGrade( );
		Bub.reduceGrade( );
		Byb.reduceGrade( );

		std::cout << std::endl;

		Bob.executeForm( Attestation_1 );
		Bub.executeForm( Attestation_2 );
		Byb.executeForm( Attestation_3 );

		std::cout << std::endl;

		Bab.signForm( Attestation_1 );
		Beb.signForm( Attestation_2 );
		Bib.signForm( Attestation_3 );
	}
	catch ( std::exception & error )
	{
		std::cerr << error.what( );
	}
    return (0);
}
