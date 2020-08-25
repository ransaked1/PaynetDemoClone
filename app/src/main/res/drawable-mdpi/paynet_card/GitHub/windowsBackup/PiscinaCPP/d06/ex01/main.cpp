/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 09:34:00 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/29 09:34:03 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <climits>

struct Data
{
	std::string		s1;
	int				n;
	std::string		s2;
};

void 	*serialize(void)
{
	const char 	var[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	std::string	str;
	int			i;
	std::stringstream	s;

	i = 0;
	while (i < 8)
	{
		str.push_back(var[rand() % static_cast<int>(sizeof(var) - 1)]);
		i++;
	}
	s << rand() % INT_MAX;
	str += s.str();
	i = 0;
	while (i < 8)
	{
		str.push_back(var[rand() % static_cast<int>(sizeof(var) - 1)]);
		i++;
	}
	return (reinterpret_cast<void *>(const_cast<char *>(str.c_str())));
}

Data 	*deserialize(void *raw)
{
	Data *d = new Data();

	d->s1 = reinterpret_cast<char *>(raw);
	d->s2 = d->s1.substr(d->s1.length() - 8, d->s1.length());
	d->n = atoi(d->s1.substr(8, d->s1.length() - 8).c_str());
	d->s1 = d->s1.substr(0, 8);
	return (d);
}

int		main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	void *s = serialize();

	std::cout << "  Serial data: " << reinterpret_cast<char *>(s) << std::endl;
	std::cout << "  Data address: " << s << std::endl;
	Data *d = deserialize(s);
	std::cout << "  Deserial data:" << std::endl;
	std::cout << "		1st string: " << d->s1 << std::endl;
	std::cout << "		number: " << d->n << std::endl;
	std::cout << "		2nd string: " << d->s2 << std::endl;
	return (0);
}