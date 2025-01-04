#include <iostream>
#include <cstdlib>
#include <cctype>

using std::cout, std::cin, std::endl, std::string;

bool isUnique(string str);

int main(int argc, char** argv) {
	string str;
	if (argc  < 2) {
		std::cerr << "No string arguments were given" << endl;
		std::exit(1);
	}
	else if (argc == 2) {
		str = argv[1];
		cout << "Checking if string is unique" << endl;
		if (isUnique(str))
			cout << "String is unique" << endl;
		else
			cout << "String is not unique" << endl;
		return 0;
	}
	else {
		std::cerr << "Invalid amount of string argumenets" << endl;
		std::exit(1);
	}
	return 0;
}

bool isUnique(string str) {
	bool seen[52] = {false};
	int index;
	for (char ch : str) {
		index = islower(ch) ? ch - 'a' : ch - 'A' + 26;
		if (seen[index]) return false;
		
		else seen[index] = true;
	}
	return true;
}
