/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 14:01:51 by dbraghis          #+#    #+#             */
/*   Updated: 2017/08/03 14:01:53 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{

public:

	Span(void);
	Span(unsigned int n);
	Span(Span const &src);
	Span 	&operator=(Span const &src);
	~Span(void);
	void	addNumber(unsigned int nr);
	int		shortestSpan(void);
	int		longestSpan(void);
	typedef	std::vector<int>		vector;

private:

	int				count;
	unsigned int 	len;
	vector			d;
};

#endif
