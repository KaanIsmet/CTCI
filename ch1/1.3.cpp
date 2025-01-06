#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

using std::string;

string URLify(string str, int len);
string trimRight(string str);
string trimLeft(string str);
string removeExtraSpaces(string str);

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Must provide a string argument" << std::endl;
		exit(1);
	}

	string str = argv[1];
	std::cout << "string before URLify" << std::endl;
	str = URLify(str, sizeof(str));
	std::cout << "string after URLify" << std::endl
		<< str << std::endl;
	return 0;
}

string URLify(string str, int len) {
	std::ostringstream oss;
	str = trimLeft(str);
	str = trimRight(str);
	str = removeExtraSpaces(str);
	for (char ch : str) {
		if (ch == ' ') oss << "%20";

		else oss << ch;
	}

	return oss.str();
}

string trimRight(string str) {
	size_t end = str.find_last_not_of(" \t\n\r");
	if (end != string::npos) return str.substr(0, end + 1);

	else return str;
}

string trimLeft(string str) {
	size_t start = 0;
	while (start < str.size() && std::isspace(str[start])) 
		start++;

	return str.substr(start);
}

string removeExtraSpaces(string str) {
	string result;
	bool inWhiteSpace = false;
	for (char ch : str) {
		if (std::isspace(ch)) {
			if (!inWhiteSpace) {
				result += " ";
				inWhiteSpace = true;
			}
		}
		else {
			result += ch;
			inWhiteSpace = false;
		}
	}

	if (!result.empty() && std::isspace(result.back()))
		result.pop_back();

	return result;
}
