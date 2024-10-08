/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:34:57 by csturm            #+#    #+#             */
/*   Updated: 2024/10/08 12:11:44 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl () {}

Harl::~Harl () {}

void    Harl::_debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void    Harl::_info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void    Harl::_warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void    Harl::_error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

typedef void (Harl::*func_ptr)();


void    Harl::complain(std::string level)
{
    func_ptr    functions[] = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*functions[i])();
            return ;
        }
    }
    std::cout << "Invalid level\n";    
}

/* 
    In C++, "this" is a pointer to the current instance of the class within a member function.
    It allows you to access the members (variables and functions) of the current object.
*/
