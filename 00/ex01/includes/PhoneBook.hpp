#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

class	PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook(void);

	void	addContact(void);
	void	searchContact(void);
	void	exit(void);

private:

	Contact	_contacts[8];
	int		_contactCount;

};

#endif
