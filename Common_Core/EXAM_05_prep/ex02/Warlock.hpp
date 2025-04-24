#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"
#include <string>
#include <iostream>

class Warlock {
	private:
		std::string	name;
		std::string	title;
		SpellBook	book;
		
		Warlock();
		Warlock(const Warlock &other);
		Warlock &operator = (const Warlock &other);
	
	public:
		Warlock(const std::string &newName, const std::string &newTitle);
		~Warlock();

		const std::string	&getName() const;
		const std::string	&getTitle() const;
		void			setTitle(const std::string &newTitle);
		void			introduce() const;
		
		void	learnSpell(ASpell *spell);
		void	forgetSpell(std::string spellName);
		void	launchSpell(std::string spellName, const ATarget &target);
};

#endif
