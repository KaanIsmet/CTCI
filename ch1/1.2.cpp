#include <iostream>
#include <cstdlib>
#include <string>

using std::string;

bool checkPermutation(string str1, string str2);

int main(int argc, char** argv) {
	if (argc != 3) {
		std::cerr << "Must provide two string arguments" << std::endl;
		exit(1);
	}
	string str1 = argv[1], str2 = argv[2];
	if (checkPermutation(str1, str2))
		std::cout << "One string is a permutation of the other string" << std::endl;
	else 
		std::cout << "Neither string is a permutation of one another" << std::endl;
	return 0;
}

bool checkPermutation(string str1, string str2) {
	for (char ch : str1) {
		if (str2.find(ch) != string::npos) continue;
		
		else return false;		
	}
	return true;
}
