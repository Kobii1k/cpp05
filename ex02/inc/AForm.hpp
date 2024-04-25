/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:02:47 by mgagne            #+#    #+#             */
/*   Updated: 2024/04/25 17:18:08 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
	#define AFORM_HPP

	#include "Bureaucrat.hpp"

	class Bureaucrat;

	class AForm
	{
	private:
		std::string const	name;
		int const			signGrade;
		int const			execGrade;
		bool				isSigned;

	public:
		AForm();
		virtual ~AForm();
		AForm(const AForm &copy);
		AForm const &operator=(const AForm &src);

		AForm(const std::string new_name, const int sGrade, const int eGrade);

		virtual void	beSigned(Bureaucrat &src) = 0;
		virtual void	execute(const Bureaucrat &exec) const = 0;


		std::string		getName() const;
		int				getexecGrade() const;
		int				getsignGrade() const;
		bool			getSignature() const;
		void			setSignature(bool result);

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw()
				{ return ("Maximum grade is 1\n"); }
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw()
				{ return ("Minimum grade is 150\n"); }
		};

		class	AlreadySignedException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw()
				{ return ("this form is already signed\n"); }
		};

		class	SignGradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw()
				{ return ("the bureaucrat's grade is too low to sign this form\n"); }
		};

		class	NotSignedException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw()
				{ return ("the form is not signed yet\n"); }
		};
		class	ExecGradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw()
				{ return ("the bureaucrat's grade is too low to execute this form\n"); }
		};
	};

	std::ostream			&operator<<(std::ostream &os, const AForm &src);

#endif
