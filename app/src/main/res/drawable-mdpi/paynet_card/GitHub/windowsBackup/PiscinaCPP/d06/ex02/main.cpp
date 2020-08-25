/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 09:34:20 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/29 09:34:21 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

class Base
{

public:

	virtual ~Base() {}
	
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

static Base		*generate(void)
{
	Base	*b = new Base();
	char 	r =rand() % 4;

	if (r == 1)
		b = new A();
	else if (r == 2)
		b = new B();
	else
		b = new C();
	return (b);
}

static void identify_from_reference(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e)
	{
		try
		{
			B &b = dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "C" << std::endl;
		}
	}
}

static void identify_from_pointer(Base *p)
{
	A *a = dynamic_cast<A *>(p);

	if (a)
		std::cout << "A" << std::endl;
	else
	{
		B *b = dynamic_cast<B *>(p);
		if (b)
			std::cout << "B" << std::endl;
		else
			std::cout << "C" << std::endl;
	}
}

int 	main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	Base *b;

	for (int i = 0; i < 5; i++)
	{
		b = generate();
		std::cout << "Reference: ";
		identify_from_reference(*b);
		std::cout << "Pointer: ";
		identify_from_pointer(b);
		delete b;
	}
	return 0;
}