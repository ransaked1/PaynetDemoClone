/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Memory.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 16:19:40 by dbraghis          #+#    #+#             */
/*   Updated: 2017/08/04 16:19:41 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MEMORY_HPP
#define MEMORY_HPP

#include "IMonitorModule.hpp"
#include "Header.hpp"

class Memory : public IMonitorModule
{

public:

    Memory(void);
    Memory(const Memory &src);
    Memory& operator=(const Memory &src);
    ~Memory(void);
	
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
