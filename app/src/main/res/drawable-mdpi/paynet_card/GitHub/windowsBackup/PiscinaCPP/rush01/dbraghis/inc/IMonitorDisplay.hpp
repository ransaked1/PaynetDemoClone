/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 04:40:04 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/30 04:40:06 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef IMONITORDISPLAY_HPP
#define IMONITORDISPLAY_HPP

# include "Header.hpp"

class IMonitorModule;

class	IMonitorDisplay {

	public:
		virtual void	initialize(void) = 0;
		virtual void	clean(void) = 0;
};

#endif