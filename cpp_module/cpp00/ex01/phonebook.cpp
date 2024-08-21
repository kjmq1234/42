#include "phonebook.hpp"

Phonebook::Phonebook(void)
{
	this->contactCount = 0;
}

Phonebook::~Phonebook(void)
{
}

void	Phonebook::add_contact()
{
	Contact	contact;
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

	std::cout << "이름을 입력하세요: ";
	std::cin >> firstName;
	contact.set_firstName(firstName);
	std::cout << "성을 입력하세요: ";
	std::cin >> lastName;
	contact.set_lastName(lastName);
	std::cout << "닉네임을 입력하세요: ";
	std::cin >> nickname;
	contact.set_nickname(nickname);
	std::cout << "전화번호를 입력하세요: ";
	std::cin >> phoneNumber;
	contact.set_phoneNumber(phoneNumber);
	std::cout << "가장 비밀스러운 정보를 입력하세요: ";
	std::cin >> darkestSecret;
	contact.set_darkestSecret(darkestSecret);
	this->contacts[this->contactCount % 8] = contact;
	this->contactCount++;
}

void    Phonebook::search_contact()
{
	int i;
	int index;
	std::string input;

	i = 0;
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << std::endl;
	while (i < this->contactCount && i < 8)
	{
		std::cout << "|";
		std::cout << std::setw(10) << (i + 1) << "|";

		std::string firstName = this->contacts[i].get_firstName();
		if (firstName.length() > 10)
			firstName = firstName.substr(0, 9) + ".";
		std::cout << std::setw(10) << firstName << "|";

		std::string lastName = this->contacts[i].get_lastName();
		if (lastName.length() > 10)
			lastName = lastName.substr(0, 9) + ".";
		std::cout << std::setw(10) << lastName << "|";

		std::string nickname = this->contacts[i].get_nickname();
		if (nickname.length() > 10)
			nickname = nickname.substr(0, 9) + ".";
		std::cout << std::setw(10) << nickname << "|" << std::endl;
		
		i++;
	}
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "검색할 index를 입력하세요: ";
	std::cin >> input;
	if (std::all_of(input.begin(), input.end(), ::isdigit)) {
        index = std::stoi(input);
	if (index >= 1 && index < (this->contactCount + 1) && index <= 8)
	{
		std::cout << "이름: " << this->contacts[index - 1].get_firstName() << std::endl;
		std::cout << "성: " << this->contacts[index - 1].get_lastName() << std::endl;
		std::cout << "닉네임: " << this->contacts[index - 1].get_nickname() << std::endl;
		std::cout << "전화번호: " << this->contacts[index - 1].get_phoneNumber() << std::endl;
		std::cout << "가장 비밀스러운 정보: " << this->contacts[index - 1].get_darkestSecret() << std::endl;
	}
	else
		std::cout << "잘못된 index입니다." << std::endl;
	}
	else
		std::cout << "잘못된 입력입니다. 숫자를 입력하세요." << std::endl;
}
