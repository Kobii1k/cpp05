/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:38:54 by mgagne            #+#    #+#             */
/*   Updated: 2024/03/05 14:42:50 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
	#define BUREAUCRAT_HPP

	#include "main.h"

	class Bureaucrat
	{
		private:
			std::string const	name;
			int					grade;

		public:
			Bureaucrat(void);
			~Bureaucrat(void);
			Bureaucrat(Bureaucrat const &copy);
			Bureaucrat const		&operator=(const Bureaucrat &src);

			Bureaucrat(std::string new_name, int new_grade);

			std::string			getName() const;
			int					getGrade() const;
			void				reduceGrade();
			void				raiseGrade();

		class	GradeTooHighException : public std::exception
		{
			public:
				const char	*what(void) const throw()
				{ return ("Maximum grade is 1\n"); }
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				const char	*what(void) const throw()
				{ return ("Minimum grade is 150\n"); }
		};
	};

	std::ostream				&operator<<(std::ostream &os, const Bureaucrat &src);

#endif
