/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:43:44 by csturm            #+#    #+#             */
/*   Updated: 2024/09/19 12:30:29 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zobieHorde(int N, std::string name)
{
    Zombie* zombieArray = new Zombie[N];
    for (int i = 0; i < N; i++)
        zombieArray[i].setName(name);
    return (zombieArray);
}
