/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:56:49 by csturm            #+#    #+#             */
/*   Updated: 2024/09/18 16:28:03 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie* zombie = newZombie("Braineater");
    zombie->announce();
    randomChump("Moaner");
    delete zombie;
    return (0);
}
