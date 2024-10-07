/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:31:59 by csturm            #+#    #+#             */
/*   Updated: 2024/10/07 14:00:13 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL) {}

HumanB::~HumanB() {}

std::string HumanB::getName() const
{
    return (_name);
}

std::string HumanB::getWeaponType() const
{
    return (_weapon->getType());
}

void    HumanB::setName(std::string name)
{
    _name = name;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    _weapon = &weapon;
}

void    HumanB::attack() const
{
    if (_weapon)
        std::cout << HumanB::getName() << " attacks with their " << HumanB::getWeaponType() << "\n";
    else
        std::cout << HumanB::getName() << " has no weapon to attack with" << "\n";
}
