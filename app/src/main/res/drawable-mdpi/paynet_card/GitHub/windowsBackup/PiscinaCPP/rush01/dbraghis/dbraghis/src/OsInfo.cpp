/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsInfo.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 10:32:06 by dbraghis          #+#    #+#             */
/*   Updated: 2017/08/04 10:32:08 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/OsInfo.hpp"
#include "../inc/Header.hpp"

OsInfo::OsInfo(void) : w(NULL)
{
	return ;
}

OsInfo::OsInfo(OsInfo const &src)
{
	*this = src;
	return ;
}

void		OsInfo::setWindow(WINDOW *win) 
{ 
	this->w = win;
}


WINDOW		*OsInfo::getWindow(void) 
{ 
	return (this->w); 
}


 OsInfo::~OsInfo() 
 {
 	return ;
 }

void	OsInfo::refreshNcurses(void) 
{
	char 	buff[40];
	int		k;
	int		n = 0;
	struct utsname uts;

    uname(&uts);
//Name
	std::string text = "OS name: ";
	std::string info = uts.sysname;
	int i = text.size();
	for (int a = 0; a <= i; a++)
	{
		buff[a] = text[a];
		k = a;
	}
	i = text.size() + info.size();
	for (int b = k; b <= i; b++)
	{
		buff[b] = info[n];
		n++;
	}
	mvwprintw(this->w, 2, 2, buff);
//Release
	memset(buff, 0, sizeof buff);
	text = "Release: ";
	info = uts.release;
	n = 0;
	i = text.size();
	for (int a = 0; a <= i; a++)
	{
		buff[a] = text[a];
		k = a;
	}
	i = text.size() + info.size();
	for (int b = k; b <= i; b++)
	{
		buff[b] = info[n];
		n++;
	}
	mvwprintw(this->w, 3, 2, buff);
//Machine
	memset(buff, 0, sizeof buff);
	text = "Hardware: ";
	info = uts.machine;
	n = 0;
	i = text.size();
	for (int a = 0; a <= i; a++)
	{
		buff[a] = text[a];
		k = a;
	}
	i = text.size() + info.size();
	for (int b = k; b <= i; b++)
	{
		buff[b] = info[n];
		n++;
	}
	mvwprintw(this->w, 4, 2, buff);
//Node
	memset(buff, 0, sizeof buff);
	text = "Node: ";
	info = uts.nodename;
	n = 0;
	i = text.size();
	for (int a = 0; a <= i; a++)
	{
		buff[a] = text[a];
		k = a;
	}
	i = text.size() + info.size();
	for (int b = k; b <= i; b++)
	{
		buff[b] = info[n];
		n++;
	}
	mvwprintw(this->w, 5, 2, buff);
	return ;
}

void	OsInfo::refresh(void) 
{
	this->refreshNcurses();
}

OsInfo	&OsInfo::operator=(OsInfo const &src) 
{
	(void)src;
	return (*this);
}

std::vector<std::string>	OsInfo::getString(void) 
{
	std::vector<std::string>		list(4);
	list[0] = "OS Info";
	list[1] = "16";
	list[2] = "30";
	list[3] = "3";
	return (list);
}
