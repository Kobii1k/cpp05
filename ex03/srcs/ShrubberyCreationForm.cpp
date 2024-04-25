/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:02:48 by mgagne            #+#    #+#             */
/*   Updated: 2024/04/25 16:49:42 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("undefined")
{
	// std::cout << "ShrubberyCreationForm" << CONSTRUCTOR << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string targ) : AForm("ShrubberyCreationForm", 145, 137), target(targ)
{
    // std::cout << "ShrubberyCreationForm" << CONSTRUCTOR << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm("ShrubberyCreationForm", 145, 137), target(copy.target)
{
    // std::cout << "ShrubberyCreationForm" << CPYCONSTRUCTOR << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
    // std::cout << "ShrubberyCreationForm" << DESTRUCTOR << std::endl;
}

std::string		ShrubberyCreationForm::getTarget() const
{
	return (target);
}

ShrubberyCreationForm const &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	(void)src;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const ShrubberyCreationForm &src)
{
	os << "Form name : " << src.getName() << std::endl;
	os << "Signature : " << src.getSignature() << std::endl;
	os << "Grade needed for signature : " << src.getsignGrade() << std::endl;
	os << "Grade needed for execution : " << src.getexecGrade() << std::endl;
	return (os);
}

void    ShrubberyCreationForm::beSigned(Bureaucrat &src)
{
	if (getSignature())
		throw AForm::AlreadySignedException();
	if (src.getGrade() > getsignGrade())
		throw AForm::SignGradeTooLowException();
	if (src.getGrade() <= getsignGrade())
		setSignature(true);
}

void    ShrubberyCreationForm::execute(const Bureaucrat &exec) const
{
        if (!getSignature())
                throw AForm::NotSignedException();
        if (exec.getGrade() > getexecGrade())
                throw AForm::ExecGradeTooLowException();
        else
        {
                std::ofstream   		out;
                std::string             outfile;

                outfile = getTarget( );
                outfile.append( "_shrubbery" );
                out.open( outfile.c_str( ), std::ios::out );
                out << TREE;
                out.close( );
                std::cout << exec.getName();
                std::cout << " planted shrubbery at ";
                std::cout << getTarget() << " in " << outfile;
                std::cout << "." << std::endl;
        }
}
