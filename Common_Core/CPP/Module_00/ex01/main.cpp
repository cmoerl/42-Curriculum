/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:55:52 by csturm            #+#    #+#             */
/*   Updated: 2024/09/18 13:17:43 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(int argc, char **argv)
{
    if (argc != 1)
    {
        std::cerr << "Error: No arguments expected\n";
        return 1;
    }

    (void)argv;
    std::cout << "Entering phonebook\n";
    PhoneBook pb;
    while (true)
    {
        std::string command;
        std::cout << "Available commands: ADD, SEARCH, EXIT\nYour command: ";
        std::getline(std::cin, command);
        if (command == "EXIT")
            break;
        else if (command == "ADD")
            pb.addContact();
        else if (command == "SEARCH")
            pb.searchContact();
        else
            std::cout << "Invalid command\n";
    }
    std::cout << "Exiting phonebook\n";
    return 0;
}
