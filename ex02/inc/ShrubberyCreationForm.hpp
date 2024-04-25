/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:02:47 by mgagne            #+#    #+#             */
/*   Updated: 2024/03/14 00:44:05 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
	#define SHRUBBERYCREATIONFORM_HPP

	#include "Bureaucrat.hpp"

	class Bureaucrat;
	class AForm;

	class ShrubberyCreationForm : public AForm
	{
	private:
		std::string		target;

	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm const &operator=(const ShrubberyCreationForm &src);

		ShrubberyCreationForm(std::string src);
		void	beSigned(Bureaucrat &src);
		void    execute(const Bureaucrat &exec) const;

		std::string		getTarget() const;
	};

	std::ostream			&operator<<(std::ostream &os, const ShrubberyCreationForm &src);

#endif
