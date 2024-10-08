/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:26:09 by csturm            #+#    #+#             */
/*   Updated: 2024/10/08 12:56:58 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int translateToInt(std::string input)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
    {
        if (input == levels[i])
            return (i + 1);
    }
    return (0);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "[ Probably complaining about insignificant problems ]\n";
        return (1);
    }
    int level = translateToInt(argv[1]);
    Harl harl;
    switch (level)
    {
        case 1:
            std::cout << "[DEBUG]\n";
            harl.complain("DEBUG");
        case 2:
            std::cout << "[INFO]\n";
            harl.complain("INFO");
        case 3:
            std::cout << "[WARNING]\n";
            harl.complain("WARNING");
        case 4:
            std::cout << "[ERROR]\n";
            harl.complain("ERROR");
            break ;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
            return (1);
    }
    return (0);
}
