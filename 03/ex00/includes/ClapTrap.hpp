#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

# define GREEN	"\033[92m"
# define RED	"\033[91m"
# define CYAN	"\033[96m"
# define YELLOW	"\033[93m"
# define BLUE	"\033[94m"
# define MAGENT	"\033[95m"
# define RESET	"\033[0m"

class ClapTrap {

private:

	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;

public:

	ClapTrap( void );
	ClapTrap(std::string name);
	ClapTrap( const ClapTrap& other);
	ClapTrap& operator=( const ClapTrap& other);
	~ClapTrap( void );

	void	attack( const std::string& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );

	std::string	getName() const;
	int			getHitPoints() const;
	int			getEnergyPoints() const;
	int			getAttackDamage() const;

	void	setName(std::string name);
	void	setHitPoints( unsigned int amount );
	void	setEnergyPoints( unsigned int amount );
	void	setAttackDamage( unsigned int amount );

};


#endif
