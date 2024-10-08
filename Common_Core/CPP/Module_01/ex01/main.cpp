/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:43:12 by csturm            #+#    #+#             */
/*   Updated: 2024/10/08 13:16:37 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int zombies = 5;
    
    Zombie *horde = zombieHorde(zombies, "Rando");
    for (int i = 0; i < zombies; i++)
        horde[i].announce();
    delete[] horde;
    return (0);
}
