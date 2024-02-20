/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:38:47 by mgagne            #+#    #+#             */
/*   Updated: 2024/02/20 15:41:33 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("not defined"), grade(150)
{
	std::cout << "Bureaucrat" << CONSTRUCTOR << std::endl;
}


Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat" << DESTRUCTOR << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : name(copy.name), grade(copy.grade)
{
	std::cout << "Bureaucrat" << CPYCONSTRUCTOR << std::endl;
}

Bureaucrat const	&Bureaucrat::operator=(const Bureaucrat &src)
{
	(void) src;
	return (*this);
}

Bureaucrat::Bureaucrat(const std::string new_name, int new_grade) : name(new_name), grade(new_grade)
{
	if (grade >= 151)
		throw Bureaucrat::GradeTooLowException();
	if (grade <= 0)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "Bureaucrat" << CONSTRUCTOR << std::endl;
}

std::string		Bureaucrat::getName() const
{
	return (name);
}

int				Bureaucrat::getGrade() const
{
	return (grade);
}

void			Bureaucrat::reduceGrade()
{
	if (grade >= 150)
		throw	Bureaucrat::GradeTooLowException();
	grade = grade + 1;
}

void			Bureaucrat::raiseGrade()
{
	if (grade <= 1)
		throw	Bureaucrat::GradeTooHighException();
	grade = grade - 1;
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &src)
{
	os << src.getName();
	os << ", bureaucrat grade ";
	os << src.getGrade();
	os << std::endl;

	return ( os );
}
