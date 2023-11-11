#include <iostream>
#include <exception>
#include <string>



class Forbidden_length :public std::exception {
public:
	const char* what() const override { return "You have entered a word of prohibited length! Goodbye";}
};


int function(std::string str, int forbidden_length) {
	if (forbidden_length == str.length())
		throw Forbidden_length();
	return str.length();
}



int main() {

	std::string str;
	int length;
	bool flag = true;

	std::cout << "Enter forbidden length:";
	std::cin >> length;

	while (flag) {
		try {
			std::cout << "Enter a word:";
			std::cin >> str;

			std::cout << "The length of word \"" << str << "\" equal " << function(str, length);
			std::cout << std::endl;
		}
		catch (const Forbidden_length& e) { std::cout << e.what() << std::endl; flag = false;}
	}

	return 0;
}