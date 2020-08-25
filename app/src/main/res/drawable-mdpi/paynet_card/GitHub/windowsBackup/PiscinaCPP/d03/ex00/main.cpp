/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 00:35:12 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/26 00:35:13 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	srand((unsigned int)time(NULL));
	FragTrap test("Emil");
	std::string const & str = "Ekillz";

	std::cout << test._name << " energy points: " << test._Ep << std::endl;
	test.vaulthunter_dot_exe(str);
	std::cout << test._name << " energy points: " << test._Ep << std::endl;
	test.vaulthunter_dot_exe(str);
	test.vaulthunter_dot_exe(str);
	test.vaulthunter_dot_exe(str);
	std::cout << test._name << " energy points: " << test._Ep << std::endl;
	test.vaulthunter_dot_exe(str);
	std::cout << test._name << " energy points: " << test._Ep << std::endl;
	test.rangedAttack(str);
	test.meleeAttack(str);
	std::cout << test._name << " hit points: " << test._Hp << std::endl;
	test.takeDamage(20);
	std::cout << test._name << " hit points: " << test._Hp << std::endl;
	test.takeDamage(95);
	std::cout << test._name << " hit points: " << test._Hp << std::endl;
	test.beRepaired(40);
	std::cout << test._name << " hit points: " << test._Hp << std::endl;
	test.beRepaired(70);
	std::cout << test._name << " hit points: " << test._Hp << std::endl;
	return (0);
}
