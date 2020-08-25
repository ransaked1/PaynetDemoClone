/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 14:08:58 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/28 14:09:02 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <ctype.h>
#include <limits>
#include <cstring>
#include <iomanip>
#include <float.h>
#include <cstdlib>
#include <cmath>

void		val_char(char c)
{
	std::cout << "char: " << "'" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float:" << static_cast<float>(c) << std::endl;
	std::cout << "double:" << static_cast<double>(c);
}

void		val_int(int i, int precis)
{
	if (isprint(i))
		std::cout << "char: " << "'" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	if (fmod(static_cast<double>(i), 1) == 0)
	{
		std::cout << std::setprecision(precis) << "float: " << static_cast<float>(i) << ".0f" << std::endl;
		std::cout << std::setprecision(precis) << "double: " << static_cast<double>(i) << ".0";
	}
	else
	{
		std::cout << std::setprecision(precis) << "float: " << static_cast<float>(i) << "f" << std::endl;
		std::cout << std::setprecision(precis) << "double: " << static_cast<double>(i);
	}
}

void		val_float(float f, int precis)
{
	if (isprint(f))
		std::cout << "char: " << "'" << static_cast<char>(f) << "'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	if (f < INT_MAX)
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	else
		std::cout << "int: " << "impossible" << std::endl;
	if (fmod(f, 1) == 0)
	{
		std::cout << std::setprecision(precis) << "float: " << f << ".0f" << std::endl;
		std::cout << std::setprecision(precis) << "double: " << static_cast<double>(f) << ".0";
	}
	else
	{
		std::cout << std::setprecision(precis) << "float: " << f << "f" << std::endl;
		std::cout << std::setprecision(precis) << "double: " << static_cast<double>(f);
	}
}

void		val_double(double d, int precis)
{
	if (isprint(d))
		std::cout << "char " << "'" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	if (d < INT_MAX)
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: " << "impossible" << std::endl;
	if (d < FLT_MAX)
	{
		if (fmod(d, 1) == 0)
			std::cout << std::setprecision(precis) << "float: " << static_cast<float>(d) << ".0f" << std::endl;
		else
			std::cout << std::setprecision(precis) << "float: " << static_cast<float>(d) << "f" << std::endl;
	}
	else
		std::cout << "float: impossible" << std::endl;
	if (fmod(d, 1) == 0)
		std::cout << std::setprecision(precis) << "double: " << d << ".0";
	else
		std::cout << std::setprecision(precis) << "double: " << d;

}

void	find_type(std::string str)
{
	char const		*pars = str.c_str();
	bool			fp = false;
	bool			f = false;

	if ((str.length() == 1) && !isdigit(str[0]) && isprint(str[0]))
		val_char(static_cast<char>(str[0]));
	else
	{
		if (strcmp(pars, "nan") == 0 || strcmp(pars, "nanf") == 0)
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan";
			return ;
		}
		if (pars)
		{
			if (*pars == '-' || *pars == '+')
			{
				char 	sign = *pars;
				pars++;
				if (sign == '-')
				{
					if (strcmp(pars, "inf") == 0 || strcmp(pars, "inff") == 0)
					{
						std::cout << "char: impossible" << std::endl;
						std::cout << "int: impossible" << std::endl;
						std::cout << "float: -inff" << std::endl;
						std::cout << "double: -inf";
						return ;
					}
				}
				if (sign == '+')
				{
					if (strcmp(pars, "inf") == 0 || strcmp(pars, "inff") == 0)
					{
						std::cout << "char: impossible" << std::endl;
						std::cout << "int: impossible" << std::endl;
						std::cout << "float: +inff" << std::endl;
						std::cout << "double: +inf";
						return ;
					}
				}
			}
			while (isdigit(*pars))
			{
				pars++;
				if (*pars == '.')
				{
					fp = true ? fp = true : fp = false;
					pars++;
				}
				if (*pars == 'f')
				{
					f = true ? f = true : f = false;
					pars++;
				}
			}
			if (*pars)
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible";
				return ;
			}
			else
			{
				if ((!fp && !f) && (atol(str.c_str()) <= INT_MAX && atol(str.c_str()) >= INT_MIN))
					val_int(static_cast<int>(atol(str.c_str())), strlen(str.c_str()));
				else if ((fp && !f) && (atof(str.c_str()) <= DBL_MAX && atol(str.c_str()) >= -DBL_MIN))
					val_double(static_cast<double>(atof(str.c_str())), strlen(str.c_str()));
				else if ((fp && f) && (atof(str.c_str()) <= FLT_MAX && atol(str.c_str()) >= FLT_MIN))
					val_float(static_cast<float>(atof(str.c_str())), strlen(str.c_str()));
				else
				{
					std::cout << "char: impossible" << std::endl;
					std::cout << "int: impossible" << std::endl;
					std::cout << "float: impossible" << std::endl;
					std::cout << "double: impossible";
					return ;
				}
			}
		}
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		find_type(static_cast<std::string>(av[1]));
	else
		std::cout << "Use: ./conv [std::string]";
	std::cout << std::endl;
	return 0;
}