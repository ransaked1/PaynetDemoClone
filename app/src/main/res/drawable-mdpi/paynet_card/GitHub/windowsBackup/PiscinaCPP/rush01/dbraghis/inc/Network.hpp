/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Network.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 17:44:28 by dbraghis          #+#    #+#             */
/*   Updated: 2017/08/04 17:44:30 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef NETWORK_HPP
#define NETWORK_HPP

#include "IMonitorModule.hpp"
#include "Header.hpp"

class Network : public IMonitorModule
{

public:

    Network(void);
    Network(const Network &src);
    Network& operator=(const Network &src);
    ~Network(void);
	
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
