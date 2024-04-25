/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 01:45:04 by mgagne            #+#    #+#             */
/*   Updated: 2024/03/14 01:45:47 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
	#define ROBOTOMYREQUESTFORM_HPP

	#include "Bureaucrat.hpp"

	class Bureaucrat;
	class AForm;

	class RobotomyRequestForm : public AForm
	{
	private:
		std::string		target;

	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm const &operator=(const RobotomyRequestForm &src);

		RobotomyRequestForm(std::string src);
		void	beSigned(Bureaucrat &src);
		void    execute(const Bureaucrat &exec) const;

		std::string		getTarget() const;
	};

	std::ostream			&operator<<(std::ostream &os, const RobotomyRequestForm &src);

#endif
