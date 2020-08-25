/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 14:01:40 by dbraghis          #+#    #+#             */
/*   Updated: 2017/08/03 14:01:41 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span()
{
	return ;
}

Span::Span(unsigned int n)
{
	this->d.resize(n);
	this->count = 0;
	this->len = n;
	return ;
}

Span::~Span()
{
	return ;
}

Span::Span(Span const &src)
{
	*this = src;
	return ;
}

Span 	&Span::operator=(Span const &src)
{
	this->d = src.d;
	this->len = src.len;
	this->count = src.count;
	return (*this);
}

void	Span::addNumber(unsigned int nr)
{
	if (this->count + 1 > this->len)
		throw std::string("Cant add numbers anymore!");
	else
	{
		this->d[count] = nr;
		this->count += 1;
	}
}

int		Span::shortestSpan()
{
	if (this->count <= 1)
		throw std::string("Not enougth numbers!");
	std::sort(this->d.begin(), this->d.end());
	return (this->d[1] - this->d[0]);
}

int		Span::longestSpan()
{
	if (this->count <= 1)
		throw std::string("Not enougth numbers!");
	std::sort(this->d.begin(), this->d.end());
	return (this->d[count - 1] - this->d[0]);
}