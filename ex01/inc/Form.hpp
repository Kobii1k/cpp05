/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:02:47 by mgagne            #+#    #+#             */
/*   Updated: 2024/03/05 14:37:43 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
	#define FORM_HPP

	#include "Bureaucrat.hpp"

	class Bureaucrat;

	class Form
	{
	private:
		std::string const	name;
		int const			signGrade;
		int const			execGrade;
		bool				isSigned;

	public:
		Form();
		~Form();
		Form(const Form &copy);
		Form const &operator=(const Form &src);

		Form(const std::string new_name, const int sGrade, const int eGrade);
		void	beSigned(Bureaucrat &src);

		std::string		getName() const;
		int				getexecGrade() const;
		int				getsignGrade() const;
		bool			getSignature() const;

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
	};

	std::ostream			&operator<<(std::ostream &os, const Form &src);

#endif
