/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:45:41 by mgagne            #+#    #+#             */
/*   Updated: 2024/04/25 17:10:39 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("undefined")
{
	// std::cout << "PresidentialPardonForm" << CONSTRUCTOR << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string targ) : AForm("PresidentialPardonForm", 25, 5), target(targ)
{
    // std::cout << "PresidentialPardonForm" << CONSTRUCTOR << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm("PresidentialPardonForm", 25, 5), target(copy.target)
{
    // std::cout << "PresidentialPardonForm" << CPYCONSTRUCTOR << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
    // std::cout << "PresidentialPardonForm" << DESTRUCTOR << std::endl;
}

std::string		PresidentialPardonForm::getTarget() const
{
	return (target);
}

PresidentialPardonForm const &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	(void)src;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const PresidentialPardonForm &src)
{
	os << "Form name : " << src.getName() << std::endl;
	os << "Signature : " << src.getSignature() << std::endl;
	os << "Grade needed for signature : " << src.getsignGrade() << std::endl;
	os << "Grade needed for execution : " << src.getexecGrade() << std::endl;
	return (os);
}

void    PresidentialPardonForm::beSigned(Bureaucrat &src)
{
	if (getSignature())
		throw AForm::AlreadySignedException();
	if (src.getGrade() > getsignGrade())
		throw AForm::SignGradeTooLowException();
	if (src.getGrade() <= getsignGrade())
		setSignature(true);
}

void    PresidentialPardonForm::execute(const Bureaucrat &exec) const
{
	if (!getSignature())
			throw AForm::NotSignedException();
	if (exec.getGrade() > getexecGrade())
			throw AForm::ExecGradeTooLowException();
	else
	{
		std::cout << getTarget() << "has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}
