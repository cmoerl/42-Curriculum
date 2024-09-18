#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

class PhoneBook
{
    public:
        PhoneBook();
        ~PhoneBook();
        void addContact();
        void searchContact() const;
        void printContactShort(int index) const;
        void printContactLong(int index) const;
    private:
        Contact _contacts[8];
        int     _index;
};

#endif
