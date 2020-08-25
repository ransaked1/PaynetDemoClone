/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncourses.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 05:04:34 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/30 05:04:36 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ncourses.hpp"
//#include "../inc/Header.hpp"

int 		spaces[] = {3, 6, 9, 9, 10};
int 		columns[] = {31, 47};

Ncourses::Ncourses(void) 
{
	return ;
}

Ncourses::Ncourses(Ncourses const & src) 
{
	*this = src;
	return ;
}

Ncourses::Ncourses(std::map<std::string, IMonitorModule *> modules) : _modules(modules) 
{
	return ;
}

Ncourses::~Ncourses(void) 
{
	return ;
}

Ncourses	&Ncourses::operator=(Ncourses const & src) 
{
	(void)src;
	return *this;
}

void	Ncourses::initialize(void) 
{
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	getmaxyx(stdscr, this->_height, this->_width);
	refresh();
	this->modulesInit();
}

void	Ncourses::modulesInit(void) 
{
	std::vector<std::string>	list;
	WINDOW						*tmp;
	float						h, w;
	int							current_height = 0;
	int 						current_width = 0;
	int 						last_height;
	int 						x = 0;
	int 						y = 0;
	int 						i = 0;

	for (std::map<std::string, IMonitorModule*>::iterator it = this->_modules.begin(); it != this->_modules.end(); ++it) 
	{
		list = it->second->getString();
		h = std::atoi(list[1].c_str());
		w = std::atoi(list[2].c_str());
		if (current_width + ((this->_width * w) / 100) > this->_width) 
		{
			current_width = 0;
			current_height += last_height;
		}
		tmp = newwin(((this->_height * h) / 100), ((this->_width * w) / 100), current_height, current_width);
		if ((w < 100) && current_width < this->_width)
		{
			current_width += ((this->_width * w) / 100);
		} 
		else
		{
			current_width = 0;
			current_height += ((this->_height * h) / 100);
		}
		last_height = ((this->_height * h) / 100);
		box(tmp, '|', '-');
		mvwin(tmp, x, y);
		x += spaces[i];
		i++;
		if (i == 3)
		{
			y += columns[0];
			x = 0;
		}
		if (i == 5)
		{
			y += columns[1];
			x = 0;
		}
		it->second->setWindow(tmp);
	}
}

void	Ncourses::display(void)
{
	timeout(500);
	char c;
	while (1) 
	{
		for (std::map<std::string, IMonitorModule*>::iterator it = this->_modules.begin(); it != this->_modules.end(); ++it) 
		{
			it->second->refresh();
			box(it->second->getWindow(), '|', '-');
			wattron(it->second->getWindow(), COLOR_PAIR(5));
			wattron(it->second->getWindow(), A_BOLD);
			mvwprintw(it->second->getWindow(), 0, 3, it->second->getString()[0].c_str());
			wattroff(it->second->getWindow(), COLOR_PAIR(5));
			wattroff(it->second->getWindow(), A_BOLD);
			wrefresh(it->second->getWindow());
		}
		refresh();
		c = getch();
		if (c == 'q')
			return ;
	}
}

void	Ncourses::clean(void) 
{
	endwin();
	std::cout << this->_height << " : " << this->_width << std::endl;
}