#include "string.h"

String::String(const char* str) {
	std::cout << "String: Using normal CTOR" << std::endl;
	size = 0;
	// traversal over the string to find its size
	// a temoprary pointer which will allow us to traverse the string without losing its beggining (held by 'str')
	for (const char *t = str ; *t != '\0'; t++) {
		size++;
	}

	start = new char[size+1];
	for (int i = 0; i< size; i++) {
		start[i] = str[i]; // str[i] = *(str + i*sizeof(char))
	}
	start[size] = '\0';
}

String::String(const String& o) {
	std::cout << "String: Using copy CTOR" << std::endl;
	size = o.size; // accessing a private member is allowed because we write code that is part of the class

	start = new char[size+1];
	for (int i = 0; i< size; i++) {
		start[i] = o.start[i]; 
	}
	start[size] = '\0';
}

String& String::operator=(const String& o) {
	/* default operator= is like:
	 * size = o.size;
	 * start = o.start;
	 */
	std::cout << "String: Using operator=" << std::endl;
	size = o.size; // accessing a private member is allowed because we write code that is part of the class

	start = new char[size+1];
	for (int i = 0; i< size; i++) {
		start[i] = o.start[i]; 
	}
	start[size] = '\0';
}


int String::length() {
	return size;
}

char String::charAt(int index) {
	// we can first do input check to make sure 0 <= index <= size - 1
	// and throw exceptions otherwise
	return start[index];
}
