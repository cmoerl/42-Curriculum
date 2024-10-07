/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:35:34 by csturm            #+#    #+#             */
/*   Updated: 2024/10/07 13:49:40 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon){}

HumanA::~HumanA() {}

std::string HumanA::getName() const
{
    return (_name);
}

std::string HumanA::getWeaponType() const
{
    return (_weapon.getType());
}

void    HumanA::setName(std::string name)
{
    _name = name;
}

void    HumanA::attack() const
{
    std::cout << HumanA::getName() << " attacks with their " << HumanA::getWeaponType() << "\n";
}
