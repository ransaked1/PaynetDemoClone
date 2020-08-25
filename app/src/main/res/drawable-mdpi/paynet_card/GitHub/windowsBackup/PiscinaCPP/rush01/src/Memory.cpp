/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Memory.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 16:19:26 by dbraghis          #+#    #+#             */
/*   Updated: 2017/08/04 16:19:28 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Memory.hpp"
#include "../inc/Header.hpp"

Memory::Memory(void) : w(NULL)
{
	return ;
}

Memory::Memory(Memory const &src)
{
	*this = src;
	return ;
}

void		Memory::setWindow(WINDOW *win) 
{ 
	this->w = win; 
}


WINDOW		*Memory::getWindow(void) 
{ 
	return (this->w); 
}


 Memory::~Memory() 
 {
 	return ;
 }

 static double ParseMemValue(const char * b)
{
   while((*b)&&(isdigit(*b) == false)) b++;
   return isdigit(*b) ? atof(b) : -1.0;
}

float GetSystemMemoryUsagePercentage()
{
   FILE * fpIn = popen("/usr/bin/vm_stat", "r");
   if (fpIn)
   {
      double pagesUsed = 0.0, totalPages = 0.0;
      char buf[512];
      while(fgets(buf, sizeof(buf), fpIn) != NULL)
      {
         if (strncmp(buf, "Pages", 5) == 0)
         {
            double val = ParseMemValue(buf);
            if (val >= 0.0)
            {
               if ((strncmp(buf, "Pages wired", 11) == 0)||(strncmp(buf, "Pages active", 12) == 0)) pagesUsed += val;
               totalPages += val;
            }
         }
         else if (strncmp(buf, "Mach Virtual Memory Statistics", 30) != 0) break;
      }
      pclose(fpIn);

      if (totalPages > 0.0)
      	return static_cast<float>(pagesUsed/totalPages);
   }
   return -1.0f; 
}

void	Memory::refreshNcurses(void) 
{
	char			buff[50];
	char			buffer[50];
	size_t			bufferlen = 50;
	std::string 	text = "Memory: ";
	int   			i = 0;

    sysctlbyname("hw.memsize", &buffer, &bufferlen, NULL, 0);
	i = text.length();
	for (int b = 0; b <= i; b++)
	 	buff[b] = text[b];
	mvwprintw(this->w, 2, 2, "%s%d%s", buff, (buffer), " bytes");
	memset(buff, 0, sizeof buff);
	text = "Memory usage: ";
	i = text.length();
	for (int b = 0; b <= i; b++)
	 	buff[b] = text[b];
	mvwprintw(this->w, 4, 2, "%s%f%c", buff, GetSystemMemoryUsagePercentage() * 100, '%');
}

void	Memory::refresh(void) 
{
	this->refreshNcurses();
}

Memory	&Memory::operator=(Memory const &src) 
{
	(void)src;
	return (*this);
}

std::vector<std::string>	Memory::getString(void) 
{
	std::vector<std::string>		list(4);
	list[0] = "Memory";
	list[1] = "17";
	list[2] = "45";
	list[3] = "5";
	return (list);
}
