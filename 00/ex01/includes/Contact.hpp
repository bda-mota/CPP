#ifndef CONTACT_H
# define CONTACT_H

class	Contact {

public:

	int		value1;
	char	value2;
	float	value3;

	Contact(void);
	~Contact(void);

	void	add(void);
	void	search(void);
	void	exit(void);

/* private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	int			_phoneNumber;
	std::string	_darkestSecret;
*/

};

#endif
