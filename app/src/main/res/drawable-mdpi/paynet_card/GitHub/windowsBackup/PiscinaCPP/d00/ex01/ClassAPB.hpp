/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassAPB.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 09:23:55 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/24 09:23:58 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CLASSAPB_HPP
#define CLASSAPB_HPP

#include <iostream>
#include <string>
#include <iomanip>

class	Contact
{

public:
	Contact(void);
	~ Contact(void);

	std::string		information[11];
};

class Phonebook
{

 public:

 	Contact		ContactList[8];

 	Phonebook(void);
 	~ Phonebook(void);
 	
 	static int	ContactIndex;

 	void		addContact(void);
 	void		showContact(int i);
 	void		searchContact(void);
 	void		showElem(void);

 }; 

#endif