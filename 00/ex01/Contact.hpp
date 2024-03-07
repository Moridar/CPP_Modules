/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsyvasal <bsyvasal@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:59:36 by bsyvasal          #+#    #+#             */
/*   Updated: 2024/03/07 12:21:45 by bsyvasal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
	private:
		std::string name;
		std::string lastname;
		std::string nickname;
		std::string number;
		std::string darkestSecret;
	public:	
		Contact();
		Contact(std::string name, std::string lastname, std::string nickname, std::string number, std::string darkestSecret);
		void longinfo();
		void shortinfo(int i);
};

#endif