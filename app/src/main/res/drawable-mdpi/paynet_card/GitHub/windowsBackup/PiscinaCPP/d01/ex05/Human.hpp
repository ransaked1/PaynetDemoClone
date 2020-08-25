/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 11:16:04 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/25 11:16:06 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HUMAN_HPP
#define HUMAN_HPP

#include "Brain.hpp"

class Human
{

public:

	Human(void);
	~Human(void);

	std::string	identify(void);
	Brain 	&getBrain(void);

private:

	Brain	*brain;
	
};

#endif
