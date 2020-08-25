/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncourses.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 04:57:32 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/30 04:58:12 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef NCOURSES_HPP
#define NCOURSES_HPP

#include <map>
#include <list>
# include "IMonitorDisplay.hpp"
# include "IMonitorModule.hpp"

class	Ncourses : public IMonitorDisplay 
{

public:

		Ncourses(void);
		Ncourses(Ncourses const & src);
		Ncourses(std::map<std::string, IMonitorModule *> modules);
		virtual ~Ncourses(void);

		Ncourses &operator=(Ncourses const & rhs);
		void		initialize(void);
		void		clean(void);
		void		display(void);
		void		modulesInit(void);

private:

		std::list<WINDOW *>		_glob;
		float					_height;
		float					_width;
		std::map<std::string, IMonitorModule *> _modules;
};

#endif