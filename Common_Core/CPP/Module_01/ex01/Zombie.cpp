/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:48:01 by csturm            #+#    #+#             */
/*   Updated: 2024/10/08 13:14:00 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name): _name(name){}

Zombie::Zombie() {}

Zombie::~Zombie()
{
    std::cout << _name << " has been destroyed.\n";
}

void Zombie::announce()
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string name)
{
    _name = name;
}
