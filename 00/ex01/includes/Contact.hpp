#ifndef CONTACT_HPP
# define CONTACT_HPP

class	Contact {

public:

	Contact(void);
	Contact(const std::string& firstName, const std::string& lastName,
			const std::string& nickname, const std::string& phoneNumber,
			const std::string& darkestSecret);
	~Contact(void);

	//getters
	std::string	getFirstName() const;
	std::string	getLastName() const;
	std::string	getNickname() const;
	std::string	getPhoneNumber() const;
	std::string	getDarkestSecret() const;
	
	//setters
	void	setFirstName(const std::string& firstName);
	void	setLastName(const std::string& lastName);
	void	setNickname(const std::string& nickname);
	void	setPhoneNumber(const std::string& phoneNumber);
	void	setDarkestSecret(const std::string& darkestSecret);

 private:
 
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

};

#endif
