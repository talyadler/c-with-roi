#include "string.h"

int main() {
	const char* str = "asdfqwer";
	String s1(str);
	std::cout << "Size of s1: " << s1.length() << std::endl;
	std::cout << "s1[5]: " << s1.charAt(5) << std::endl;
	(std::cout << "s1: ") << s1 << std::endl << std::endl;

	String s2(s1); //using copy CTOR
	std::cout << "s2: " << s2 << std::endl << std::endl;

	String s3 = s1; //using copy CTOR
	std::cout << "s3: " << s3 << std::endl << std::endl;

	String s4 = "Tal is a great student";
	std::cout << "s4: " << s4 << std::endl << std::endl;

	s3 = "sg;ldkfjgs;dfl"; // creates rvalue of String - we'll talk about this at another time
	std::cout << "s3: " << s3 << std::endl << std::endl;

	s3 = s4; // calling operator=
	std::cout << "s3: " << s3 << std::endl << std::endl;

}
