/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 01:43:15 by mgagne            #+#    #+#             */
/*   Updated: 2024/04/25 17:07:35 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("undefined")
{
	// std::cout << "RobotomyRequestForm" << CONSTRUCTOR << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string targ) : AForm("RobotomyRequestForm", 72, 45), target(targ)
{
    // std::cout << "RobotomyRequestForm" << CONSTRUCTOR << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm("RobotomyRequestForm", 72, 45), target(copy.target)
{
    // std::cout << "RobotomyRequestForm" << CPYCONSTRUCTOR << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
    // std::cout << "RobotomyRequestForm" << DESTRUCTOR << std::endl;
}

std::string		RobotomyRequestForm::getTarget() const
{
	return (target);
}

RobotomyRequestForm const &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	(void)src;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const RobotomyRequestForm &src)
{
	os << "Form name : " << src.getName() << std::endl;
	os << "Signature : " << src.getSignature() << std::endl;
	os << "Grade needed for signature : " << src.getsignGrade() << std::endl;
	os << "Grade needed for execution : " << src.getexecGrade() << std::endl;
	return (os);
}

void    RobotomyRequestForm::beSigned(Bureaucrat &src)
{
	if (getSignature())
		throw AForm::AlreadySignedException();
	if (src.getGrade() > getsignGrade())
		throw AForm::SignGradeTooLowException();
	if (src.getGrade() <= getsignGrade())
		setSignature(true);
}

void    RobotomyRequestForm::execute(const Bureaucrat &exec) const
{
	int r;
	if (!getSignature())
			throw AForm::NotSignedException();
	if (exec.getGrade() > getexecGrade())
			throw AForm::ExecGradeTooLowException();
	else
	{
		std::cout << "*drilling noise*" << std::endl;
		srand((unsigned) time(NULL));
		r = rand();
		if (r % 2 == 0)
			std::cout << getTarget() << "has been successfully robotomized" << std::endl;
		else
			std::cout << getTarget() << "'s robotomy failed" << std::endl;
	}
}
