/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 03:05:43 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/30 03:09:39 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HEADER_HPP
#define HEADER_HPP

#include "Ncourses.hpp"
#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include "TimeDate.hpp"
#include "Cpu.hpp"
#include "Memory.hpp"
#include "Network.hpp"
#include "OsInfo.hpp"
#include "UserHost.hpp"

#include <iostream>
#include <string>
#include <unistd.h>
#include <sstream>
#include <list>
#include <ncurses.h>
#include <ifaddrs.h>
#include <map>
#include <ctime>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <cstdlib>
#include <unistd.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <stdlib.h>
#include <stdio.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>
#include <mach/mach_error.h>
#include <mach/vm_map.h>
#include <sys/socket.h>
#include <sys/sysctl.h>
#include <sys/time.h>
#include <net/if.h>
#include <net/if_mib.h>
#include <netinet/in.h>
#include <net/route.h>
#include <ifaddrs.h>
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <net/if_dl.h>

#endif
