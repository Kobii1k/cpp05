/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:34:22 by mgagne            #+#    #+#             */
/*   Updated: 2024/04/25 18:10:05 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	// std::cout << "Intern" << CONSTRUCTOR << std::endl;
}

Intern::Intern(Intern const &copy)
{
	(void) copy;
    // std::cout << "Intern" << CPYCONSTRUCTOR << std::endl;
}

Intern::~Intern()
{
    // std::cout << "Intern" << DESTRUCTOR << std::endl;
}

Intern const &Intern::operator=(const Intern &src)
{
	(void)src;
	return (*this);
}

AForm	*Intern::makeForm(std::string formName, std::string target)
{
	const std::string forms[3] = {
		"PresidentialPardonForm",
		"RobotomyRequestForm",
		"ShrubberyCreationForm"
	};
	AForm* (Intern::*formFunctions[3])(std::string) = {
		&Intern::PardonForm,
		&Intern::RobotomyForm,
		&Intern::ShrubberyForm
	};
	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*(formFunctions[i]))(target);
		}
	}
	throw AForm::NotSignedException();
	return (NULL);
}

AForm	*Intern::PardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::RobotomyForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::ShrubberyForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

