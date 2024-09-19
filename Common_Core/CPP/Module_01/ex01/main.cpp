/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:43:12 by csturm            #+#    #+#             */
/*   Updated: 2024/09/19 12:26:56 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void    deleteZombies(Zombie *horde, int N)
{
    for (int i = 0; i < N; i++)
        delete &horde[i];
}

int main()
{
    int zombies = 5;
    
    Zombie *horde = zombieHorde(zombies, "Rando");
    for (int i = 0; i < zombies; i++)
        horde[i].announce();
    deleteZombies(horde, zombies);
}
