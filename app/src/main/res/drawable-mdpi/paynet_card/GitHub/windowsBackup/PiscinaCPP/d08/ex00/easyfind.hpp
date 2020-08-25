/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 17:33:08 by dbraghis          #+#    #+#             */
/*   Updated: 2017/08/03 17:42:34 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
void	easyfind(T v, int i)
{
	int 					z = 0;
	std::vector<int>::iterator 	it;

	it = std::find(v.begin(), v.end(), i);
	if (it == v.end())
		std::cout << "Number not found" << std::endl;
	else
		std::cout << "Number found" << std::endl;
}

#endif
