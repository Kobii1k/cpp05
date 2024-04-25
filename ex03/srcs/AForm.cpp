/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:02:48 by mgagne            #+#    #+#             */
/*   Updated: 2024/04/25 17:21:45 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"
# include "Bureaucrat.hpp"

AForm::AForm(void) : name("not defined"), signGrade(150), execGrade(150)
{
	isSigned = false;
	// std::cout << "Form" << CONSTRUCTOR << std::endl;
}

AForm::~AForm(void)
{
	// std::cout << "Form" << DESTRUCTOR << std::endl;
}

AForm::AForm(AForm const &copy) : name(copy.name), signGrade(copy.signGrade), execGrade(copy.execGrade), isSigned(copy.isSigned)
{
	// std::cout << "Form" << CPYCONSTRUCTOR << std::endl;
}

AForm const &AForm::operator=(const AForm &src)
{
	(void)src;
	return (*this);
}

AForm::AForm(const std::string new_name, const int sGrade, const int eGrade) : name(new_name), signGrade(sGrade), execGrade(eGrade)
{
	isSigned = false;
	if (signGrade >= 151 || execGrade >= 151)
		throw AForm::GradeTooLowException();
	if (signGrade <= 0 || execGrade <= 0)
		throw AForm::GradeTooHighException();
	// std::cout << "Form" << CONSTRUCTOR << std::endl;
}

std::string		AForm::getName() const
{ return name; }

int				AForm::getexecGrade() const
{ return (execGrade); }

int				AForm::getsignGrade() const
{ return (signGrade); }

bool			AForm::getSignature() const
{ return (isSigned); }

void			AForm::setSignature(bool result)
{ isSigned = result; }

std::ostream	&operator<<(std::ostream &os, const AForm &src)
{
	os << "Form name : " << src.getName() << std::endl;
	os << "Signature : " << src.getSignature() << std::endl;
	os << "Grade needed for signature : " << src.getsignGrade() << std::endl;
	os << "Grade needed for execution : " << src.getexecGrade() << std::endl;
	return (os);
}
