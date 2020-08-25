/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 01:03:10 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/30 09:23:27 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Header.hpp"
#include "../inc/Ncourses.hpp"

std::map<std::string, IMonitorModule *>		getModules(std::map<std::string, IMonitorModule*> &modules) 
{
	TimeDate	*timedate = new TimeDate();
	UserHost	*userhost = new UserHost();
	OsInfo		*osinfo = new OsInfo();
	Cpu			*cpu = new Cpu();
	Memory 		*memory = new Memory();
	Network		*network = new Network();
	std::vector<std::string>	tmp;

	tmp = timedate->getString();
	modules[tmp[3]] = timedate;

	tmp = userhost->getString();
	modules[tmp[3]] = userhost;

	tmp = osinfo->getString();
	modules[tmp[3]] = osinfo;

	tmp = cpu->getString();
	modules[tmp[3]] = cpu;

	tmp = memory->getString();
	modules[tmp[3]] = memory;

	tmp = network->getString();
	modules[tmp[3]] = network;
	return (modules);
}

int		main()
{
	std::map<std::string, IMonitorModule *>	modules;
	modules = getModules(modules);

	Ncourses *ncourse = new Ncourses(modules);
	ncourse->initialize();
	ncourse->display();
	ncourse->clean();
	delete ncourse;
	return (0);
}
