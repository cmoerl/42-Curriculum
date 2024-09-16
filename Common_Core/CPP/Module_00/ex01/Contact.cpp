/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:24:42 by csturm            #+#    #+#             */
/*   Updated: 2024/09/16 15:55:43 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact() {}

bool    Contact::setFirstName(const std::string& firstName)
{
    if (firstName.empty())
    {
        std::cerr << "Invalid first name\n";
        return (false);
    }
    _firstName = firstName;
    return (true);
}

bool    Contact::setLastName(const std::string& lastName)
{
    if (lastName.empty())
    {
        std::cerr << "Invalid last name\n";
        return (false);
    }
    _lastName = lastName;
    return (true);
}

bool    Contact::setNickname(const std::string& nickname)
{
    if (nickname.empty())
    {
        std::cerr << "Invalid nickname\n";
        return (false);
    }
    _nickname = nickname;
    return (true);
}

bool    Contact::setPhoneNumber(const std::string& phoneNumber)
{
    if (phoneNumber.empty())
    {
        std::cerr << "Invalid phone number\n";
        return (false);
    }
    int i = 0;
    if (phoneNumber[i] == '+')
        i++;
    for (; phoneNumber[i] != '\0'; i++)
    {
        if (!std::isdigit(phoneNumber[i]))
        {
            std::cerr << "Invalid phone number\n";
            return (false);
        }
    }
    _phoneNumber = phoneNumber;
    return (true);
}

bool    Contact::setDarkestSecret(const std::string& darkestSecret)
{
    if (darkestSecret.empty())
    {
        std::cerr << "Invalid darkest secret\n";
        return (false);
    }
    _darkestSecret = darkestSecret;
    return (true);
}

std::string Contact::getFirstName() const
{
    return (_firstName);
}

std::string Contact::getLastName() const
{
    return (_lastName);
}

std::string Contact::getNickname() const
{
    return (_nickname);
}

std::string Contact::getPhoneNumber() const
{
    return (_phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
    return (_darkestSecret);
}