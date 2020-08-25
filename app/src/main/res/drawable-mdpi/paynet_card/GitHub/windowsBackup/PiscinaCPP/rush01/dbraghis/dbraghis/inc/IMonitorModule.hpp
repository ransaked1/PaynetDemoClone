/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 02:22:01 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/30 02:22:17 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP

# include <iostream>
# include <Vector>
# include <ncurses.h>

class IMonitorModule
{

public:
	virtual std::vector<std::string> getString(void) = 0;
	virtual void	refresh(void) = 0;
	virtual void	setWindow(WINDOW *win) = 0;
	virtual WINDOW*	getWindow(void) = 0;

private:
	
		virtual	void			refreshNcurses(void) = 0;
};

#endif