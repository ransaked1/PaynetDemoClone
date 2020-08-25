/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 18:22:57 by dbraghis          #+#    #+#             */
/*   Updated: 2017/08/02 18:22:58 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename A>
void	f(A const &element)
{
	std::cout << "The element is: " << element << std::endl;
}

template <typename T>
void	iter(T *array, int n, void (*f)(T const &))
{
	int 	i = 0;

	while (i < n)
	{
		f(array[i]);
		i++;
	}
}

int		main()
{
	int  r[5] = {1, 3, 34, 12, 325};
	char str[10] = "Ya boiiii";
	::iter(r, 5, f<int>);
	::iter(str, 9, f<char>);
	return (0);
}
