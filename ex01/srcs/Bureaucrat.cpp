/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:38:47 by mgagne            #+#    #+#             */
/*   Updated: 2024/03/05 14:40:05 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

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
	os << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return (os);
}

void		Bureaucrat::signForm(Form &src)
{
	try
	{
		src.beSigned(*this);
		std::cout << name << " signed form : " << src.getName() << std::endl;
	}
	catch ( std::exception & error )
	{
		std::cerr << name << " couldn't sign " << src.getName() << " because " << error.what();
	}
}
