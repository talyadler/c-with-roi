#include "string.h"

int main() {
	// "asdf".compareTo("qwer") < 0  --> first letter difference: a < q
	String s1("asdf");
	String s2("qwer");
	int compareResult = s1.compareTo(s2);
	if (!(compareResult < 0)) {
		std::cout << "First case fail, result should have been < 0, actual: " << compareResult << std::endl;
	}
	// "asdf".compareTo("asdf") == 0 --> no difference in letters or length
	
	// "qwer".compareTo("asdf") > 0 --> first letter difference: q > a
	// "aaa".compareTo("aab") < 0 --> 3rd letter difference : a < b
	// "aaaa".compareTo("aaa") > 0 --> length difference: 4 > 3
	// "".compareTo("  ")  < 0 --> length difference: 0 < 2
}

