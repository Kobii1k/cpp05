/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:15:22 by mgagne            #+#    #+#             */
/*   Updated: 2024/04/25 18:06:30 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	Faa("Faa", 25);
		Bureaucrat	Reb("Reb", 72);
		Bureaucrat	lil("lil", 145);
		Bureaucrat	Bob("Bob", 5);
		Bureaucrat	Hug("Hug", 45);
		Bureaucrat	ivy("ivy", 137);

		PresidentialPardonForm	Attestation_1( "Georges" );
		RobotomyRequestForm  	Attestation_2( "Wall_E" );
		ShrubberyCreationForm		Attestation_3( "home" );

		std::cout << Faa << Reb << lil << Bob << Hug << ivy << std::endl;

		std::cout << Attestation_1 << std::endl;
		std::cout << Attestation_2 << std::endl;
		std::cout << Attestation_3 << std::endl;

		Faa.reduceGrade();
		Reb.reduceGrade();
		lil.reduceGrade();
		Faa.signForm( Attestation_1 );
		Reb.signForm( Attestation_2 );
		lil.signForm( Attestation_3 );
		Bob.reduceGrade();
		Hug.reduceGrade();
		ivy.reduceGrade();

		std::cout << std::endl;

		Bob.executeForm( Attestation_1 );
		Hug.executeForm( Attestation_2 );
		ivy.executeForm( Attestation_3 );

		std::cout << std::endl;

		Faa.signForm( Attestation_1 );
		Reb.signForm( Attestation_2 );
		lil.signForm( Attestation_3 );

		std::cout << std::endl;

		Intern coffeeMaker;
		AForm* randomForm;
		randomForm = coffeeMaker.makeForm("PresidentialPardonForm", "Bush");
		Faa.signForm(*randomForm);
		Bob.executeForm(*randomForm);

		if (randomForm)
			delete randomForm;
	}
	catch ( std::exception & error )
	{
		std::cerr << error.what( );
	}
    return (0);
}
