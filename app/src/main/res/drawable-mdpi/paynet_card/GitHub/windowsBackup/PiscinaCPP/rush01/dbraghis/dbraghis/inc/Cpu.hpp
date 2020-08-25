/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cpu.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 11:49:44 by dbraghis          #+#    #+#             */
/*   Updated: 2017/08/04 11:49:46 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CPU_HPP
#define CPU_HPP

#include "IMonitorModule.hpp"
#include "Header.hpp"

class Cpu : public IMonitorModule
{

public:

    Cpu(void);
    Cpu(const Cpu &src);
    Cpu& operator=(const Cpu &src);
    ~Cpu(void);
	
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
