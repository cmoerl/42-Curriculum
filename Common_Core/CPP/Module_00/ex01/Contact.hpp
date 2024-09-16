#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
public:
    Contact();
    bool setFirstName(const std::string& firstName);
    bool setLastName(const std::string& lastName);
    bool setNickname(const std::string& nickname);
    bool setPhoneNumber(const std::string& phoneNumber);
    bool setDarkestSecret(const std::string& darkestSecret);
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;
};

#endif