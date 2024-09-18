/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:55:17 by csturm            #+#    #+#             */
/*   Updated: 2024/09/18 13:05:05 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _index(0){}

PhoneBook::~PhoneBook() {}

void    PhoneBook::addContact()
{
    Contact newContact;
    std::string input;
    
    bool valid = false;
    while (!valid)
    {
        std::cout << "Enter first name: ";
        std::getline(std::cin, input);
        valid = newContact.setFirstName(input);     
    }
    
    valid = false;
    while (!valid)
    {
        std::cout << "Enter last name: ";
        std::getline(std::cin, input);
        valid = newContact.setLastName(input);
    }
    
    valid = false;
    while (!valid)
    {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, input);
        valid = newContact.setNickname(input);
    }
    
    valid = false;
    while (!valid)
    {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, input);
        valid = newContact.setPhoneNumber(input);
    }

    valid = false;
    while (!valid)
    {
        std::cout << "Enter darkest secret: ";
        std::getline(std::cin, input);
        valid = newContact.setDarkestSecret(input);
    }

    _contacts[_index] = newContact;
    _index = (_index + 1) % 8;
}

void    PhoneBook::searchContact() const
{
    if (_index == 0 && _contacts[0].getFirstName().empty())
    {
        std::cerr << "No contacts available\n";
        return;
    }
    
    for (int i = 0; i < 8; i++)
    {
        if (_contacts[i].getFirstName().empty())
            break;
        printContactShort(i);
    }
    
    std::string input;
    std::cout << "Enter index of contact to display: ";
    std::getline(std::cin, input);
    std::stringstream ss(input);
    int index;
    ss >> index;
    if (ss.fail() || !ss.eof())
    {
        std::cerr << "Invalid index\nReturning to menu\n";
        return;
    }
    if (index >= 0 && index < _index)
        printContactLong(index);
    else
        std::cerr << "Invalid index\n";
}

void    PhoneBook::printContactShort(int index) const
{
    std::string firstName = _contacts[index].getFirstName();
    if (firstName.length() > 10)
        firstName = firstName.substr(0, 9) + ".";
    std::string lastName = _contacts[index].getLastName();
    if (lastName.length() > 10)
        lastName = lastName.substr(0, 9) + ".";
    std::string nickname = _contacts[index].getNickname();
    if (nickname.length() > 10)
        nickname = nickname.substr(0, 9) + ".";
    std::cout << "|" << std::setw(10) << index << "|";
    std::cout << std::setw(10) << firstName << "|";
    std::cout << std::setw(10) << lastName << "|";
    std::cout << std::setw(10) << nickname << "|\n";
}

void    PhoneBook::printContactLong(int index) const
{
    std::cout << "First name: " << _contacts[index].getFirstName() << "\n";
    std::cout << "Last name: " << _contacts[index].getLastName() << "\n";
    std::cout << "Nickname: " << _contacts[index].getNickname() << "\n";
    std::cout << "Phone number: " << _contacts[index].getPhoneNumber() << "\n";
    std::cout << "Darkest secret: " << _contacts[index].getDarkestSecret() << "\n";
}
