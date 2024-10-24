#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class   Brain
{
    private:
        std::string _ideas[100];

    public:
        Brain();
        Brain(const Brain &copy);
        Brain &operator = (const Brain &copy);
        ~Brain();

        std::string *getIdeas() const;
        void        setIdeas(const std::string *ideas);

};

#endif
