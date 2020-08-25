/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 19:13:09 by dbraghis          #+#    #+#             */
/*   Updated: 2017/08/02 19:13:10 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
class Array
{

public:

	Array(void)
	{
		this->myArray = new T[0];
		return ;
	}
	~Array(void)
	{
		delete [] this->myArray;
		return ;
	}
	Array(unsigned int n)
	{
		this->myArray = new T[n];
		this->len = n;
		return ;
	}
	Array(Array const &src)
	{
		*this = src;
		return ;
	}
	Array 	&operator=(Array const &src)
	{
		delete [] this->myArray;
		this->len = src.len;
		this->myArray = src.myArray;
		return (*this);
	}
	T 	&operator[](unsigned int n)
	{
		if (n > this->len)
			throw std::runtime_error("Error: Wrong memory access");
		return (this->myArray[n]);
	}
	unsigned int 	size()
	{
		return (this->len);
	}
	
private:

	unsigned int 	len;
	T 				*myArray;
};
