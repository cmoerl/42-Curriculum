#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    public:
        PhoneBook();
        void addContact();
        void searchContact() const;
        void printContactShort(int index) const;
        void printContactLong(int index) const;
    private:
        Contact _contacts[8];
        int     _index;
};

#endif