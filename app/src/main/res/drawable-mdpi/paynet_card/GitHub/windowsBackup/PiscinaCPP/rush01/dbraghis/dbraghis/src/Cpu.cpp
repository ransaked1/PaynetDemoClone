/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cpu.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 11:49:31 by dbraghis          #+#    #+#             */
/*   Updated: 2017/08/04 12:38:58 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cpu.hpp"
#include "../inc/Header.hpp"

static unsigned long long _previousTotalTicks = 0;
static unsigned long long _previousIdleTicks = 0;

Cpu::Cpu(void) : w(NULL)
{
	return ;
}

Cpu::Cpu(Cpu const &src)
{
	*this = src;
	return ;
}

void		Cpu::setWindow(WINDOW *win) 
{ 
	this->w = win; 
}


WINDOW		*Cpu::getWindow(void) 
{ 
	return (this->w); 
}


 Cpu::~Cpu() 
 {
 	return ;
 }

float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
  unsigned long long totalTicksSinceLastTime = totalTicks-_previousTotalTicks;
  unsigned long long idleTicksSinceLastTime  = idleTicks-_previousIdleTicks;
  float ret = 1.0f-((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime)/totalTicksSinceLastTime : 0);
  _previousTotalTicks = totalTicks;
  _previousIdleTicks  = idleTicks;
  return ret;
}

float GetCPULoad()
{
   host_cpu_load_info_data_t cpuinfo;
   mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
   if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
   {
      unsigned long long totalTicks = 0;
      for(int i=0; i<CPU_STATE_MAX; i++) totalTicks += cpuinfo.cpu_ticks[i];
      return CalculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks);
   }
   else return -1.0f;
}

void	Cpu::refreshNcurses(void) 
{
	char			buff[100];
	std::string 	name = "CPU model: ";
	size_t			bufferlen = 100;
	int				k = 0;
	int				n = 0;
	int   			i = 0;

	i = name.size();
	for (int b = k; b <= i; b++)
	{
		buff[b] = name[n];
		n++;
	}
	mvwprintw(this->w, 2, 2, buff);
	memset(buff, 0, sizeof buff);
	sysctlbyname("machdep.cpu.brand_string", &buff, &bufferlen, NULL, 0);
	mvwprintw(this->w, 3, 2, buff);
	memset(buff, 0, sizeof buff);
	name = "Thread count: ";
	i = name.length();
	for (int b = 0; b <= i; b++)
		buff[b] = name[b];
	int numCPU = sysconf(_SC_NPROCESSORS_ONLN);
	buff[i] = numCPU + 48;
	mvwprintw(this->w, 5, 2, buff);
//Get load
	memset(buff, 0, sizeof buff);
	name = "Cpu load: ";
	std::string info = std::to_string(static_cast<int>(GetCPULoad() * 100));
	n = 0;
	i = name.length();
	for (int a = 0; a <= i; a++)
	{
		buff[a] = name[a];
		k = a;
	}
	i = name.length() + info.length();
	for (int b = k; b <= i; b++)
	{
		buff[b] = info[n];
		n++;
	}
	mvwprintw(this->w, 7, 2, "%s%%", buff);
}

void	Cpu::refresh(void) 
{
	this->refreshNcurses();
}

Cpu	&Cpu::operator=(Cpu const &src) 
{
	(void)src;
	return (*this);
}

std::vector<std::string>	Cpu::getString(void) 
{
	std::vector<std::string>		list(4);
	list[0] = "Cpu";
	list[1] = "19";
	list[2] = "45";
	list[3] = "4";
	return (list);
}
