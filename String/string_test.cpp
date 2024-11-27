#include "string.h"

int main() {
	// "asdf".compareTo("qwer") < 0  --> first letter difference: a < q
	String s1("asdf");
	String s2("qwer");
	int compareResult = s1.compareTo(s2);
	if (!(compareResult < 0)) {
		std::cout << "1st case fail, result should have been < 0, actual: " << compareResult << std::endl;
	}
	else{
		std::cout << "1st case success actual: " << compareResult << std::endl;
	}

	// "asdf".compareTo("asdf") == 0 --> no difference in letters or length
	s1 = "asdf";
	s2 = "asdf";
	compareResult = s1.compareTo(s2);
	if (!(compareResult == 0)) {
		std::cout << "2nd case fail, result should have been == 0, actual: " << compareResult << std::endl;
	}
	else{
		std::cout << "2nd case success actual: " << compareResult << std::endl;
	}
	
	// "qwer".compareTo("asdf") > 0 --> first letter difference: q > a
	s1 = "qwer";
	s2 = "asdf";
	compareResult = s1.compareTo(s2);
	if (!(compareResult > 0)) {
		std::cout << "3rd case fail, result should have been > 0, actual: " << compareResult << std::endl;
	}
	else{
		std::cout << "3rd case success actual: " << compareResult << std::endl;
	}
	
	// "aaa".compareTo("aab") < 0 --> 3rd letter difference : a < b
	s1 = "aaa";
	s2 = "aab";
	compareResult = s1.compareTo(s2);
	if (!(compareResult < 0)) {
		std::cout << "4th case fail, result should have been < 0, actual: " << compareResult << std::endl;
	}
	else{
		std::cout << "4th case success actual: " << compareResult << std::endl;
	}
	
	// "aaaa".compareTo("aaa") > 0 --> length difference: 4 > 3
	s1 = "aaaa";
	s2 = "aaa";
	compareResult = s1.compareTo(s2);
	if (!(compareResult > 0)) {
		std::cout << "5th case fail, result should have been > 0, actual: " << compareResult << std::endl;
	}
	else{
		std::cout << "5th case success actual: " << compareResult << std::endl;
	}
	
	// "".compareTo("  ")  < 0 --> length difference: 0 < 2
	s1 = "";
	s2 = "  ";
	compareResult = s1.compareTo(s2);
	if (!(compareResult < 0)) {
		std::cout << "6th case fail, result should have been < 0, actual: " << compareResult << std::endl;
	}
	else{
		std::cout << "6th case success actual: " << compareResult << std::endl;
	}
}

