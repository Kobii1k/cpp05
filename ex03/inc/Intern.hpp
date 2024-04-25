/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:29:00 by mgagne            #+#    #+#             */
/*   Updated: 2024/04/25 17:59:06 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
	#define INTERN_HPP

	#include "AForm.hpp"
	#include "Bureaucrat.hpp"
	#include "PresidentialPardonForm.hpp"
	#include "RobotomyRequestForm.hpp"
	#include "ShrubberyCreationForm.hpp"

	class AForm;

	class Intern
	{
		public:
			Intern();
			~Intern();
			Intern(const Intern &copy);
			Intern const &operator=(const Intern &src);

			AForm	*makeForm(std::string formName, std::string target);
			AForm	*PardonForm(std::string target);
			AForm	*RobotomyForm(std::string target);
			AForm	*ShrubberyForm(std::string target);
	};

#endif
