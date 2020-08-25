/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 19:28:24 by dbraghis          #+#    #+#             */
/*   Updated: 2017/08/02 19:28:25 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.cpp"

int		main()
{
	int		a[6] = {0, 134, 32, 12, 76, 1};
	char 	str[11] = "Hey man...";

	Array<int> array1(6);
	Array<char> array2(10);
	int		i = 0;
	while (i < 6)
	{
		std::cout << "At index " << i << " int is: ";
		array1[i] = a[i];
		std::cout << array1[i] << std::endl;
		i++;
	}
	i = 0;
	while (i < 12)
	{
		std::cout << "At index " << i << " char is: ";
		array2[i] = str[i];
		std::cout << array2[i] << std::endl;
		i++;
	}
	return (0);
}
