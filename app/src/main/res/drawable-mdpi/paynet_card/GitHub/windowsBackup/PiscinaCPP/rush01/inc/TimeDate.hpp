/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeDate.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 02:30:22 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/30 02:30:24 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef TIMEDATE_HPP
#define TIMEDATE_HPP

#include "IMonitorModule.hpp"
#include "Header.hpp"

class TimeDate : public IMonitorModule
{

public:

    TimeDate(void);
    TimeDate(const TimeDate &src);
    TimeDate& operator=(const TimeDate &src);
    ~TimeDate(void);
	
	void							refresh(void);
	std::vector<std::string> 		getString(void);
	void							setWindow(WINDOW *win);
	WINDOW							*getWindow(void);

private:

	WINDOW 			*w;
	std::string 	s;
	void			refreshNcurses(void);
};

#endif