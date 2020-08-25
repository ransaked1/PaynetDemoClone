/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsInfo.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 10:32:20 by dbraghis          #+#    #+#             */
/*   Updated: 2017/08/04 10:32:22 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef OSINFO_HPP
#define OSINFO_HPP

#include "IMonitorModule.hpp"
#include "Header.hpp"

class OsInfo : public IMonitorModule
{

public:

    OsInfo(void);
    OsInfo(const OsInfo &src);
    OsInfo& operator=(const OsInfo &src);
    ~OsInfo(void);
	
	void							refresh(void);
	std::vector<std::string> 		getString(void);
	void							setWindow(WINDOW *win);
	WINDOW							*getWindow(void);
	std::string 					osNameImpl(void);

private:

	WINDOW 			*w;
	std::string 	s;
	void			refreshNcurses(void);
};

#endif
