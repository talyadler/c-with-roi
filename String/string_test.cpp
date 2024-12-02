#include "string.h"

int main() {

	std::cout << "Testing compareTo() method with hard coded inputs\n";
	// "asdf".compareTo("qwer") < 0  --> first letter difference: a < q
	String s1("asdf");
	String s2("qwer");
	int compareResult = s1.compareTo(s2);
	if (!(compareResult < 0)) {
		std::cout << "\t1st case fail, result should have been < 0, actual: " << compareResult << std::endl;
	}
	else{
		std::cout << "\t1st case success actual: " << compareResult << std::endl;
	}

	// "asdf".compareTo("asdf") == 0 --> no difference in letters or length
	s1 = "asdf";
	s2 = "asdf";
	compareResult = s1.compareTo(s2);
	if (!(compareResult == 0)) {
		std::cout << "\t2nd case fail, result should have been == 0, actual: " << compareResult << std::endl;
	}
	else{
		std::cout << "\t2nd case success actual: " << compareResult << std::endl;
	}
	
	// "qwer".compareTo("asdf") > 0 --> first letter difference: q > a
	s1 = "qwer";
	s2 = "asdf";
	compareResult = s1.compareTo(s2);
	if (!(compareResult > 0)) {
		std::cout << "\t3rd case fail, result should have been > 0, actual: " << compareResult << std::endl;
	}
	else{
		std::cout << "\t3rd case success actual: " << compareResult << std::endl;
	}
	
	// "aaa".compareTo("aab") < 0 --> 3rd letter difference : a < b
	s1 = "aaa";
	s2 = "aab";
	compareResult = s1.compareTo(s2);
	if (!(compareResult < 0)) {
		std::cout << "\t4th case fail, result should have been < 0, actual: " << compareResult << std::endl;
	}
	else{
		std::cout << "\t4th case success actual: " << compareResult << std::endl;
	}
	
	// "aaaa".compareTo("aaa") > 0 --> length difference: 4 > 3
	s1 = "aaaa";
	s2 = "aaa";
	compareResult = s1.compareTo(s2);
	if (!(compareResult > 0)) {
		std::cout << "\t5th case fail, result should have been > 0, actual: " << compareResult << std::endl;
	}
	else{
		std::cout << "\t5th case success actual: " << compareResult << std::endl;
	}
	
	// "".compareTo("  ")  < 0 --> length difference: 0 < 2
	s1 = "";
	s2 = "  ";
	compareResult = s1.compareTo(s2);
	if (!(compareResult < 0)) {
		std::cout << "\t6th case fail, result should have been < 0, actual: " << compareResult << std::endl;
	}
	else{
		std::cout << "\t6th case success actual: " << compareResult << std::endl;
	}
	
	// user input test for compareTo()
	char usr_compareTo_input1[254];
	std::cout << "input 1st test text: ";
	std::cin.getline(usr_compareTo_input1, 254);
	char usr_compareTo_input2[254];
	std::cout << "input 2nd test text: ";
	std::cin.getline(usr_compareTo_input2, 254);
	s1 = usr_compareTo_input1;
	s2 = usr_compareTo_input2;
	bool skip = false;
	// std::cout << s1 << ";" << s2 << std::endl;
	compareResult = s1.compareTo(s2);
	//1
	if ((compareResult == 0)) {
		std::cout << "\tMatch\n";
	}
	//3
	else if ((compareResult <= -1000 || compareResult >= 1000)) {
		std::cout << "\tInput size mismach\n";
		bool skip = true;
	}
	//4
	else if (compareResult < 0 || compareResult > 0) {
		std::cout << "\tInput value mismatch\n";
	}

	//char at tests
	// hard coded inputs
	s1 = "charAt test string";
	std::cout << "Testing hard coded charAt method with '" << s1.length()+2 << "' index inputs" << std::endl;
	for (int i = -1; i<=(s1.length()+4);i++){
		try{
			s1.charAt(i);
		}
		catch (...){
			std::cout << "\tWorking as intended. Index: " << i << " is out of bounds\n";
		}
	}
	std::cout << "done\n";
	//user input tests
	// String s1("asdf");
	char usr_charAt_test[254];
	std::cout << "input test text: ";
	std::cin.getline(usr_charAt_test, 254);
	s1 = usr_charAt_test;
	std::cout << "Testing user input charAt method with '" << s1.length()+2 << "' index inputs" << std::endl;
	for (int i = -1; i <= (s1.length());i++){
		try{
			s1.charAt(i);
			std::cout << "test log: \tindex " << i << " \tcharAt is: " << s1.charAt(i) << std::endl;
		}
		catch (...){
			std::cout << "\tWorking as intended. Index: " << i << " is out of bounds\n";
		}
	}
	std::cout << "done\n";
	return 0;
}
