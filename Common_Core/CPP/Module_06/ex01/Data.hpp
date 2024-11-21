#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data
{
    private:
        int number_;

    public:
        Data();
        Data(const Data &copy);
        Data &operator=(const Data &copy);
        virtual ~Data();

        int getNumber() const;
        void setNumber(int number);
};

#endif
