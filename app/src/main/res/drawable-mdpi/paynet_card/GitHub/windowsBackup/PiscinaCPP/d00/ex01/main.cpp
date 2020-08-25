/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 09:46:18 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/24 09:46:21 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassAPB.hpp"

void	printMenu()
{
	std::cout << "Welcome to the AwesomePhoneBook! This is a programmer Phonebook so contacts are numbered from 0 XD" << std::endl;
	std::cout << "ADD - Add a contact to the PhoneBook" << std::endl;
	std::cout << "SEARCH - View contact list and inspect one" << std::endl;
	std::cout << "EXIT - Exit the PhoneBook" << std::endl;
}

int 	main()
{
	Phonebook 		MyPhoneBook;
	std::string		input;

	while (1)
	{
		printMenu();
		std::cin >> input;
		if (input == "ADD")
			MyPhoneBook.addContact();
		else if (input == "SEARCH")
			MyPhoneBook.searchContact();
		else if (input == "EXIT")
		{
			std::cout << "Have a nice day!" << std::endl;
			return (0);
		}
		else
		{
			std::cout << std::endl << "INVALID COMMAND! CHECK IF COMMAND IS WRITTEN IN UPPER CASE." << std::endl;
		}
	}
	return(0);
}