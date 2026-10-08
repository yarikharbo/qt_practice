#include <iostream>
#include <string>
#include <cctype>

void find_numbers(std::string&);

int main() {
	try {
		std::string str{};
		std::cout << "Enter a string: ";
		std::getline(std::cin, str);
		if (str.size() > 100) {
			throw "Incorrect size";
		}
		find_numbers(str);
	}
	catch (const char* err) {
		std::cerr << err << '\n';
	}
	return 0;
}

void find_numbers(std::string& str) {
	if (isdigit(str[0])) {
		std::cout << str[0];
	}
	for (size_t i = 1; i < str.size(); ++i) {
		if (isdigit(str[i])) {
			if (!isdigit(str[i - 1])) {
				std::cout << '\n';
			}
			std::cout << str[i];
		}
	}
}