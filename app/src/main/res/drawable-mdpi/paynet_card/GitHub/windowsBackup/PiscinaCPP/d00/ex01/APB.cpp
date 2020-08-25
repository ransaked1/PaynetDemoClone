/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   APB.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 09:23:46 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/24 09:23:48 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassAPB.hpp"

Contact::Contact(void)
{
	this->information[0] = "first name";
	this->information[1] = "last name";
	this->information[2] = "nickname";
	this->information[3] = "login";
	this->information[4] = "postal address";
	this->information[5] = "email address";
	this->information[6] = "phone number";
	this->information[7] = "birthday date";
	this->information[8] = "favorite meal";
	this->information[9] = "underwear color";
	this->information[10] = "darkest secret";
}

Contact::~Contact(void)
{
	return ;
}

Phonebook::Phonebook(void)
{
	return ;
}

Phonebook::~Phonebook(void)
{
	std::cout << "Contacts deleted!" << std::endl;
	return ;
}

int		Phonebook::ContactIndex = 0;

void 	Phonebook::addContact(void)
{
	int				i;
	std::string		ans = "";
	Contact 		tmp;

	i = 0;
	if (ContactIndex <= 7)
	{
		while (i < 11)
		{
			std::cout << "Enter " << tmp.information[i] << ": ";
			std::cin >> this->ContactList[ContactIndex].information[i];
			i++;
		}
		ContactIndex++;
	}
	else
	{
		std::cout << std::endl << "CONTACT AMOUNT LIMIT EXCEDED! DO YOU WANT TO" << std::endl;
		std::cout << "CAHNGE THE LAST CONTACT YOU ENTERED? YES or anytext = NO" << std::endl;
		std::cin >> ans;
		if (ans == "yes" || ans == "YES")
		{
			ContactIndex -= 1;
			while (i < 11)
			{
				std::cout << "Enter " << tmp.information[i] << ": ";
				std::cin >> this->ContactList[ContactIndex].information[i];
				i++;
			}
			ContactIndex++;
		}
	}
}

void 	Phonebook::showContact(int i)
{
	Contact 	tmp;
	int			n;

	n = 0;
	while (n < 11)
	{
		std::cout << tmp.information[n] << ": " << this->ContactList[i].information[n]
			<< std::endl;
		n++;
	}
}

void	Phonebook::searchContact(void)
{
	int 			i;
	int 			n;
	int 			search;
	std::string		text;

	i = 0;
	n = 0;
	std::cout << std::setw(10) << "INDEX" << " " << std::setw(10) << "FST NAME" << " " << std::setw(10) <<
		"LST NAME" << " " << std::setw(10) << "NICKNAME" << " " << std::endl;
	while (i <= ContactIndex - 1)
	{
		n = 0;
		std::cout << std::setw(10) << i << "|";
		while (n <= 2)
		{
			text = this->ContactList[i].information[n];
			if (text.length() > 10)
			{ 
				text.erase(10, text.length() - 10);
				text[9] = '.';
			}
			std::cout << std::setw(10) << text;
			if (n != 2)
				std::cout << "|";
			n++;
		}
		std::cout << std::endl;
		i++;
	}
	start: std::cout << "INDEX OF CONTACT TO INSPECT: ";
	std::cin >> search;
	while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << std::endl << "BAD ENTRY. ENTER A NUMBER: ";
        std::cin >> search;
    }
    if (search > ContactIndex - 1 || search < 0)
    {
    	std::cout << std::endl << "EXCEDED THE CONTACT NUMBER OR NEGATIVE NBR!" << std::endl;
    	goto start;
    }
	this->showContact(search);
}



