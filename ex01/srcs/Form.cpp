/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:02:48 by mgagne            #+#    #+#             */
/*   Updated: 2024/03/05 14:35:36 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"
# include "Bureaucrat.hpp"

Form::Form(void) : name("not defined"), signGrade(150), execGrade(150)
{
	isSigned = false;
	std::cout << "Form" << CONSTRUCTOR << std::endl;
}

Form::~Form(void)
{
	std::cout << "Form" << DESTRUCTOR << std::endl;
}

Form::Form(Form const &copy) : name(copy.name), signGrade(copy.signGrade), execGrade(copy.execGrade), isSigned(copy.isSigned)
{
	std::cout << "Form" << CPYCONSTRUCTOR << std::endl;
}

Form const &Form::operator=(const Form &src)
{
	(void)src;
	return (*this);
}

Form::Form(const std::string new_name, const int sGrade, const int eGrade) : name(new_name), signGrade(sGrade), execGrade(eGrade)
{
	isSigned = false;
	if (signGrade >= 151 || execGrade >= 151)
		throw Form::GradeTooLowException();
	if (signGrade <= 0 || execGrade <= 0)
		throw Form::GradeTooHighException();
	std::cout << "Form" << CONSTRUCTOR << std::endl;
}

std::string		Form::getName() const
{ return name; }

int				Form::getexecGrade() const
{ return (execGrade); }

int				Form::getsignGrade() const
{ return (signGrade); }

bool			Form::getSignature() const
{ return (isSigned); }

std::ostream	&operator<<(std::ostream &os, const Form &src)
{
	os << "Form name : " << src.getName() << std::endl;
	os << "Signature : " << src.getSignature() << std::endl;
	os << "Grade needed for signature : " << src.getsignGrade() << std::endl;
	os << "Grade needed for execution : " << src.getexecGrade() << std::endl;
	return (os);
}

void Form::beSigned(Bureaucrat &src)
{
	if (isSigned)
		throw Form::AlreadySignedException();
	if (src.getGrade() > signGrade)
		throw Form::SignGradeTooLowException();
	if (src.getGrade() <= signGrade)
		isSigned = true;
}
