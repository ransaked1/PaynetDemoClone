/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserHost.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 19:45:48 by dbraghis          #+#    #+#             */
/*   Updated: 2017/08/03 19:45:51 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef USERHOST_HPP
#define USERHOST_HPP

#include "IMonitorModule.hpp"
#include "Header.hpp"

class UserHost : public IMonitorModule
{

public:

    UserHost(void);
    UserHost(const UserHost &src);
    UserHost& operator=(const UserHost &src);
    ~UserHost(void);
	
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
