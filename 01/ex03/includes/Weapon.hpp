#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# define GREEN	"\033[92m"
# define RED	"\033[91m"
# define CYAN	"\033[96m"
# define YELLOW	"\033[93m"
# define BLUE	"\033[94m"
# define MAGENT	"\033[95m"
# define RESET	"\033[0m"

class	Weapon {

public:

	Weapon();
	Weapon(std::string type);
	~Weapon();

	const std::string&	getType() const;
	void	setType(std::string type);

private:

	std::string	_type;

};

#endif
