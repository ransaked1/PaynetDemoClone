/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserHost.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 19:46:14 by dbraghis          #+#    #+#             */
/*   Updated: 2017/08/03 19:46:16 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/UserHost.hpp"
#include "../inc/Header.hpp"

UserHost::UserHost(void) : w(NULL)
{
	return ;
}

UserHost::UserHost(UserHost const &src)
{
	*this = src;
	return ;
}

void		UserHost::setWindow(WINDOW *win) 
{ 
	this->w = win;
}


WINDOW		*UserHost::getWindow(void) 
{ 
	return (this->w); 
}


 UserHost::~UserHost() 
 {
 	return ;
 }


void	UserHost::refreshNcurses(void) 
{
	char buff[25];
	
	gethostname(buff, 25);
	mvwprintw(this->w, 2, 2, buff);
	getlogin_r(buff, 25);
	mvwprintw(this->w, 3, 2, buff);
	return ;
}

void	UserHost::refresh(void) 
{
	this->refreshNcurses();
}

UserHost	&UserHost::operator=(UserHost const &src) 
{
	(void)src;
	return (*this);
}

std::vector<std::string>	UserHost::getString(void) 
{
	std::vector<std::string>		list(4);
	list[0] = "Host and User name";
	list[1] = "12";
	list[2] = "30";
	list[3] = "2";
	return (list);
}