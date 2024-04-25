/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:46:27 by mgagne            #+#    #+#             */
/*   Updated: 2024/04/25 16:47:51 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
	#define PRESIDENTIALPARDONFORM_HPP

	#include "Bureaucrat.hpp"

	class Bureaucrat;
	class AForm;

	class PresidentialPardonForm : public AForm
	{
	private:
		std::string		target;

	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm const &operator=(const PresidentialPardonForm &src);

		PresidentialPardonForm(std::string src);
		void	beSigned(Bureaucrat &src);
		void    execute(const Bureaucrat &exec) const;

		std::string		getTarget() const;
	};

	std::ostream			&operator<<(std::ostream &os, const PresidentialPardonForm &src);

#endif
