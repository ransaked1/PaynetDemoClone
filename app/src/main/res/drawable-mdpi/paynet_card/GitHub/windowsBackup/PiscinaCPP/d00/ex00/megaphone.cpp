/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 08:34:32 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/24 08:34:33 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include <locale>

int		main(int ac, char **av)
{
	int		i;
    std::string allWords;
    std::locale loc;

    allWords = "";
    i = 1;

    if (ac == 1)
    {
    	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    	return (0);
    }

    while (ac > 1)
    {
        allWords += av[i];
        i++;
        ac--;
    }

    for (std::string::size_type i=0; i<allWords.length(); ++i)
    	std::cout << std::toupper(allWords[i], loc);
    std::cout << std::endl;
    return 0;
}