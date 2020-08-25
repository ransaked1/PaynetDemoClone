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
#include "ScavTrap.hpp"

int main(void)
{
	srand((unsigned int)time(NULL));
	FragTrap test("emil");
	std::string const & str = "ekillz";
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
	std::cout << std::endl << std::endl;
	ScavTrap test2("emil2");
	test2.rangedAttack(str);
	test2.meleeAttack(str);
	std::cout << test2._name << " hit points: " << test2._Hp << std::endl;
	test2.takeDamage(20);
	std::cout << test2._name << " hit points: " << test2._Hp << std::endl;
	test2.takeDamage(95);
	std::cout << test2._name << " hit points: " << test2._Hp << std::endl;
	test2.beRepaired(40);
	std::cout << test2._name << " hit points: " << test2._Hp << std::endl;
	test2.beRepaired(70);
	std::cout << test2._name << " hit points: " << test2._Hp << std::endl;
	test2.challengeNewcomer();
	test2.challengeNewcomer();
	test2.challengeNewcomer();
	test2.challengeNewcomer();

	return (0);
}
