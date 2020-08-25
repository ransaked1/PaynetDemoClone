/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Network.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 17:44:12 by dbraghis          #+#    #+#             */
/*   Updated: 2017/08/04 17:44:14 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Network.hpp"
#include "../inc/Header.hpp"

Network::Network(void) : w(NULL)
{
	return ;
}

Network::Network(Network const &src)
{
	*this = src;
	return ;
}

void		Network::setWindow(WINDOW *win) 
{ 
	this->w = win; 
}


WINDOW		*Network::getWindow(void) 
{ 
	return (this->w); 
}


 Network::~Network() 
 {
 	return ;
 }



void	Network::refreshNcurses(void) 
{
    struct ifaddrs * ifAddrStruct=NULL;
    struct ifaddrs * ifa=NULL;
    void *tmpAddrPtr=NULL;

    getifaddrs(&ifAddrStruct);

    for (ifa = ifAddrStruct; ifa != NULL; ifa = ifa->ifa_next) 
    {
        if (!ifa->ifa_addr) 
        {
            continue;
        }
        if (ifa->ifa_addr->sa_family == AF_INET) 
        {
            tmpAddrPtr=&((struct sockaddr_in *)ifa->ifa_addr)->sin_addr;
            char addressBuffer[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);
            mvwprintw(this->w, 2, 2, "%s", "IP Address:"); 
            mvwprintw(this->w, 3, 1, "%s", addressBuffer); 
        } 
        else if (ifa->ifa_addr->sa_family == AF_INET6) 
        {
            tmpAddrPtr=&((struct sockaddr_in6 *)ifa->ifa_addr)->sin6_addr;
            char addressBuffer[INET6_ADDRSTRLEN];
            inet_ntop(AF_INET6, tmpAddrPtr, addressBuffer, INET6_ADDRSTRLEN);
            mvwprintw(this->w, 2, 2, "%s", "IP Address:");
            mvwprintw(this->w, 3, 1, "%s", addressBuffer); 
        } 
    }

    	int 		mib[6];
	char 		*lim;
	char 		*next;
	size_t 		len;
	struct 		if_msghdr *ifm;

	long int 	ipackets = 0;
	long int 	opackets = 0;

	const char 		*_inpacket;
	const char 		*_oupacket;

	mib[0] = CTL_NET;
	mib[1] = PF_ROUTE;
	mib[2] = 0;
	mib[3] = 0;
	mib[4] = NET_RT_IFLIST2;
	mib[5] = 0;
	
	sysctl(mib, 6, NULL, &len, NULL, 0);
	char buf[len];
	sysctl(mib, 6, buf, &len, NULL, 0);

	lim = buf + len;
	for (next = buf; next < lim; ) 
	{
		ifm = (struct if_msghdr *)next;
		next += ifm->ifm_msglen;

		if (ifm->ifm_type == RTM_IFINFO2) 
		{
			struct if_msghdr2 *if2m = (struct if_msghdr2 *)ifm;

			if(if2m->ifm_data.ifi_type!=18) 
			{
				opackets += if2m->ifm_data.ifi_opackets;
				ipackets += if2m->ifm_data.ifi_ipackets;
			}
		}
	}

    std::ostringstream stream3;
    stream3 <<  ipackets;
    std::string str3 = stream3.str().substr(0, 5);
    _inpacket = str3.c_str();

    std::ostringstream stream4;
    stream4 << opackets;
    std::string str4 = stream4.str().substr(0, 5);
    _oupacket = str4.c_str();

    mvwprintw(this->w, 5, 2, "%s%s", "Packets sent: ", _inpacket);
    mvwprintw(this->w, 6, 2, "%s%s", "Packets received: ", _oupacket);
}



void	Network::refresh(void) 
{
	this->refreshNcurses();
}

Network	&Network::operator=(Network const &src) 
{
	(void)src;
	return (*this);
}

std::vector<std::string>	Network::getString(void) 
{
	std::vector<std::string>		list(4);
	list[0] = "Network";
	list[1] = "18";
	list[2] = "27";
	list[3] = "6";
	return (list);
}
