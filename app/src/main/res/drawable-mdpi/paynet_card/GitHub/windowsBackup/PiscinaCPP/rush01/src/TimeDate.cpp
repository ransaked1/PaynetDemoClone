/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeDate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 02:45:51 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/30 02:45:57 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/TimeDate.hpp"
#include "../inc/Header.hpp"

TimeDate::TimeDate(void) : w(NULL)
{
	return ;
}

TimeDate::TimeDate(TimeDate const &src)
{
	*this = src;
	return ;
}

void		TimeDate::setWindow(WINDOW *win) 
{ 
	this->w = win; 
}


WINDOW		*TimeDate::getWindow(void) 
{ 
	return (this->w); 
}


 TimeDate::~TimeDate() 
 {
 	return ;
 }


void	TimeDate::refreshNcurses(void) 
{
    time_t			t = time(0);
    struct tm		*tinfo = localtime(&t);
	char			buff[40];

	strftime(buff, 40, "%c", tinfo);
	mvwprintw(this->w, 1, 3, buff);
}

void	TimeDate::refresh(void) 
{
	this->refreshNcurses();
}

TimeDate	&TimeDate::operator=(TimeDate const &src) 
{
	(void)src;
	return (*this);
}

std::vector<std::string>	TimeDate::getString(void) 
{
	std::vector<std::string>		list(4);
	list[0] = "Time and Date";
	list[1] = "7";
	list[2] = "30";
	list[3] = "1";
	return (list);
}
